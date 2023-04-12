#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>
#include "proto/generated/engine.pb.h"
#include "path.h"
#include "engine.h"

namespace scyna
{
    class Logger
    {
    public:
        static const uint INFO = 1;
        static const uint ERROR = 2;
        static const uint WARNING = 3;
        static const uint DEBUG = 4;
        static const uint FATAL = 5;

    protected:
        uint64_t id_;
        bool session_;
        void add(uint level, std::string messgage);

    public:
        Logger(uint64_t id, bool session = false);
        void print(const char *file, int line, uint level, const char *message);
        void printf(const char *file, int line, uint level, const char *format, ...);
    };
}

#define _LOG_(logger, level, message) logger->print(__FILE__, __LINE__, level, message);
#define _SESSION_LOG_(level, message) _LOG_(scyna::Engine::instance()->logger(), level, message)

#define logINFO(message) _SESSION_LOG_(scyna::Logger::INFO, message);
#define logDEBUG(message) _SESSION_LOG_(scyna::Logger::DEBUG, message);
#define logERROR(message) _SESSION_LOG_(scyna::Logger::ERROR, message);
#define logWARNING(message) _SESSION_LOG_(scyna::Logger::WARNING, message);
#define logFATAL(message) _SESSION_LOG_(scyna::Logger::FATAL, message);

#endif