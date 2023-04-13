#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>
#include <sstream>
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

    public:
        Logger(uint64_t id, bool session = false);
        void trace(const char *file, int line, uint level, const char *message);
        void print(uint level, std::string message);

        template <typename... Args>
        void print(uint level, Args &&...args)
        {
            std::ostringstream stream;
            (stream << ... << std::forward<Args>(args));
            this->print(level, stream.str());
        }

        template <typename... Args>
        void trace(const char *file, int line, uint level, Args &&...args)
        {
            std::ostringstream stream;
            stream << file << "(" << line << ") : ";
            (stream << ... << std::forward<Args>(args));
            this->print(level, stream.str());
        }

    public:
        void info(std::string message) { print(INFO, message); }
        void error(std::string message) { print(ERROR, message); }
        void debug(std::string message) { print(DEBUG, message); }
        void warning(std::string message) { print(WARNING, message); }
        void fatal(std::string message) { print(FATAL, message); }
    };
}

#define _TRACE_(logger, level, message) logger->trace(__FILE__, __LINE__, level, message);
#define _SESSION_TRACE_(level, message) _TRACE_(scyna::Engine::LOG(), level, message)

#define traceINFO(message) _SESSION_TRACE_(scyna::Logger::INFO, message);
#define traceDEBUG(message) _SESSION_TRACE_(scyna::Logger::DEBUG, message);
#define traceERROR(message) _SESSION_TRACE_(scyna::Logger::ERROR, message);
#define traceWARNING(message) _SESSION_TRACE_(scyna::Logger::WARNING, message);
#define traceFATAL(message) _SESSION_TRACE_(scyna::Logger::FATAL, message);

#endif