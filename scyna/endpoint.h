#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <string>
#include "engine.h"
#include "session.h"
#include "utils.h"
#include "error.h"
#include "base_handler.h"
#include <google/protobuf/util/json_util.h>

namespace scyna
{
    namespace Endpoint
    {
        template <typename T>
        class Handler : public scyna::BaseHandler
        {
        protected:
            T request;

        private:
            natsConnection *connection_;
            std::string reply_;
            std::string source_;
            bool json_;
            bool flushed_;

            void flush(int code, const google::protobuf::Message &m)
            {
                scyna_proto::Response response;
                response.set_code(code);
                response.set_sessionid(Engine::instance()->session()->ID());

                if (json_)
                {
                    std::string body;
                    auto status = google::protobuf::util::MessageToJsonString(m, &body);
                    response.set_body(body);
                }
                else
                {
                    response.set_body(m.SerializeAsString());
                }

                auto result = response.SerializeAsString();
                natsConnection_Publish(connection_, reply_.c_str(), (const void *)result.c_str(), result.length());

                flushed_ = true;
            }

            void onMessageReceived(natsConnection *nc, natsMsg *msg) override
            {
                this->connection_ = nc;
                this->reply_ = natsMsg_GetReply(msg);
                this->flushed_ = false;

                scyna_proto::Request req;
                if (!req.ParseFromArray(natsMsg_GetData(msg), natsMsg_GetDataLength(msg)))
                {
                    std::cerr << "Can not parse request" << std::endl;
                    flush(400, scyna::BAD_DATA->toProto());
                    return;
                }

                this->json_ = req.json();
                this->source_ = req.data();

                if (json_)
                {
                    auto status = google::protobuf::util::JsonStringToMessage(req.body(), &request);
                    if (!status.ok())
                    {
                        std::cerr << status.error_message() << std::endl;
                        std::cerr << "Can not parse message received from endpoint:" << natsMsg_GetSubject(msg) << std::endl;
                        flush(400, scyna::BAD_DATA->toProto());
                        return;
                    }
                }
                else
                {
                    if (!request.ParseFromString(req.body()))
                    {
                        std::cerr << "Can not parse message received from endpoint:" << natsMsg_GetSubject(msg) << std::endl;
                        flush(400, scyna::BAD_DATA->toProto());
                        return;
                    }
                }

                auto err = execute();

                if (err == scyna::OK)
                {
                    if (!flushed_)
                    {
                        flush(200, scyna::OK->toProto());
                    }
                }
                else
                {
                    flush(400, err->toProto());
                }
            }

        public:
            virtual const Error *execute() = 0;
            void response(const google::protobuf::Message &m)
            {
                flush(200, m);
            }

            const scyna::Error *OK(const google::protobuf::Message &m)
            {
                flush(200, m);
                return scyna::OK;
            }
        };

        template <typename H>
        static void Register(std::string url)
        {
            H *handler = new H();
            std::cout << "Register Service:" << url << std::endl;
            auto nc = Engine::instance()->connection();

            natsSubscription *sub = NULL;
            auto status = natsConnection_QueueSubscribe(&sub, nc, Utils::subscribeUrl(url).c_str(), "API", scyna::_onMessageReceived_, handler);

            if (status == NATS_OK)
            {
                handler->init(sub);
            }
            else
            {
                std::cerr << "Can not register service:" << url << std::endl;
                exit(0);
            }
        }
    }
}

#endif