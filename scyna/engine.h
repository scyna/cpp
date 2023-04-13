#ifndef ENGINE_H
#define ENGINE_H

#include <boost/make_shared.hpp>
#include <nats/nats.h>
#include "proto/generated/engine.pb.h"
#include "proto/generated/scyna.pb.h"

namespace scyna
{
    class Session;
    class Generator;
    class Logger;

    class Engine
    {
    private:
        std::string module_;
        Session *session_ = NULL;
        Generator *id_ = NULL;
        natsConnection *connection_ = NULL;
        Logger *logger_ = NULL;

    public:
        static Generator *ID() { return instance_->id_; }
        static std::string Module() { return instance_->module_; }
        static uint64_t SessionID();
        static natsConnection *Connection() { return instance_->connection_; }
        static Logger *LOG() { return instance_->logger_; }

    public:
        static Engine *instance();
        static void Init(std::string managerURL, std::string module, std::string secret);
        void start();
        void release();
        ~Engine();
        boost::shared_ptr<scyna_proto::Response> natsRequest(std::string subject, const scyna_proto::Request &request);

    private:
        static Engine *instance_;
        Engine(std::string module, uint64_t sid, const scyna_proto::Configuration &config);
    };
}

#endif