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
        void write(const char *file, int line, uint level, const char *message);
    };
}

#define LOG_INFO(message) scyna::Engine::instance()->logger()->write(__FILE__, __LINE__, scyna::Logger::INFO, message);
#define LOG_DEBUG(message) scyna::Engine::instance()->logger()->write(__FILE__, __LINE__, scyna::Logger::DEBUG, message);
#define LOG_ERROR(message) scyna::Engine::instance()->logger()->write(__FILE__, __LINE__, scyna::Logger::ERROR, message);
#define LOG_WARNING(message) scyna::Engine::instance()->logger()->write(__FILE__, __LINE__, scyna::Logger::WARNING, message);
#define LOG_FATAL(message) scyna::Engine::instance()->logger()->write(__FILE__, __LINE__, scyna::Logger::FATAL, message);

#endif