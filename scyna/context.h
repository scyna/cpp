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
        // void sendRequest();
        // void scheduleTask();
        // void tag();
        // void publishEvent();
        // void raiseEvent();
    };
}

#define _CONTEXT_LOG_(level, message) _TRACE_(context, level, message)

#define ctxINFO(message) _CONTEXT_LOG_(scyna::Logger::INFO, message)
#define ctxDEBUG(message) _CONTEXT_LOG_(scyna::Logger::DEBUG, message)
#define ctxERROR(message) _CONTEXT_LOG_(scyna::Logger::ERROR, message)
#define ctxWARNING(message) _CONTEXT_LOG_(scyna::Logger::WARNING, message)
#define ctxFATAL(message) _CONTEXT_LOG_(scyna::Logger::FATAL, message)

#endif