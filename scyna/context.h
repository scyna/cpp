#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdint.h>
#include "logger.h"

namespace scyna
{
    class Context : public Logger
    {
    public:
        Context(uint64_t id);
        void reset(uint64_t id) { this->id_ = id; }
        void sendRequest();
        void scheduleTask();
        void tag();
        void publishEvent();
        void raiseEvent();
    };
}

#define ctxINFO(message) context->write(__FILE__, __LINE__, scyna::Logger::INFO, message)
#define ctxDEBUG(message) context->write(__FILE__, __LINE__, scyna::Logger::DEBUG, message)
#define ctxERROR(message) context->write(__FILE__, __LINE__, scyna::Logger::ERROR, message)
#define ctxWARNING(message) context->write(__FILE__, __LINE__, scyna::Logger::WARNING, message)
#define ctxFATAL(message) context->write(__FILE__, __LINE__, scyna::Logger::FATAL, message)

#endif