#ifndef SIGNAL_H
#define SIGNAL_H

#include <google/protobuf/message.h>
#include "base_handler.h"
#include "engine.h"
#include "utils.h"

namespace scyna
{
    namespace Signal
    {
        enum Scope
        {
            SCOPE_MODULE = 1,
            SCOPE_SESSION = 2
        };

        template <typename T>
        class Handler : public scyna::BaseHandler
        {
        protected:
            T data;

        private:
            void onMessageReceived(natsConnection *nc, natsMsg *msg) override
            {
                if (!data.ParseFromArray(natsMsg_GetData(msg), natsMsg_GetDataLength(msg)))
                {
                    std::cerr << "Can not parse signal data" << std::endl;
                    return;
                }
                this->execute();
            }

        public:
            virtual void execute() = 0;
        };

        static void Emit(std::string channel, const google::protobuf::Message &m)
        {
            auto nc = Engine::instance()->connection();
            auto result = m.SerializeAsString();
            natsConnection_Publish(nc, channel.c_str(), (const void *)result.c_str(), result.length());
        }

        template <typename H>
        static void Register(std::string channel, Scope scope = SCOPE_MODULE)
        {
            std::cout << "Register Signal:" << channel << std::endl;

            H *handler = new H();
            auto engine = Engine::instance();
            auto nc = engine->connection();

            natsSubscription *sub = NULL;
            natsStatus status = NATS_ERR;
            if (scope == SCOPE_MODULE)
            {
                status = natsConnection_QueueSubscribe(&sub, nc, Utils::subscribeUrl(channel).c_str(), engine->module().c_str(), scyna::_onMessageReceived_, handler);
            }
            else if (scope == SCOPE_SESSION)
            {
                status = natsConnection_Subscribe(&sub, nc, Utils::subscribeUrl(channel).c_str(), scyna::_onMessageReceived_, handler);
            }

            if (status == NATS_OK)
            {
                handler->init(sub);
            }
            else
            {
                std::cerr << "Can not register signal:" << channel << std::endl;
                exit(0);
            }
        }
    }
}

#endif