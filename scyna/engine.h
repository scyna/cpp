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
        Session *session_;
        Generator *id_;
        natsConnection *connection_ = NULL;
        Logger *logger_;

    public:
        Generator *ID() { return id_; }
        std::string module() { return module_; }
        Session *session() { return session_; }
        natsConnection *connection() { return connection_; }
        Logger *logger() { return logger_; }

    public:
        static boost::shared_ptr<Engine> instance();
        static void Init(std::string managerURL, std::string module, std::string secret);
        void start();
        ~Engine();

    public:
        void natsPublish(std::string subject, const char *data, int len);
        boost::shared_ptr<scyna_proto::Response> natsRequest(std::string subject, const scyna_proto::Request &request);

    private:
        static boost::shared_ptr<Engine> instance_;
        Engine(std::string module, uint64_t sid, const scyna_proto::Configuration &config);
    };
}

#endif