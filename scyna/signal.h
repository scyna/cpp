#ifndef SIGNAL_H
#define SIGNAL_H

#include <google/protobuf/message.h>
#include "base_handler.h"

namespace scyna
{
    namespace Signal
    {
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

        static void Emit(std::string channel, const google::protobuf::Message &m);

        template <typename H>
        static void Register(std::string channel)
        {
            std::cout << "Register Signal:" << channel << std::endl;

            H *handler = new H();
            auto engine = Engine::instance();
            auto nc = engine->connection();

            natsSubscription *sub = NULL;
            auto status = natsConnection_QueueSubscribe(&sub, nc, Utils::subscribeUrl(url).c_str(), engine->module(), scyna::_onMessageReceived_, handler);

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