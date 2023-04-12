#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>
#include "proto/generated/engine.pb.h"
#include "engine.h"
#include "path.h"

namespace scyna
{
    class Logger
    {
    private:
        const uint INFO = 1;
        const uint ERROR = 2;
        const uint WARNING = 3;
        const uint DEBUG = 4;
        const uint FATAL = 5;
        uint64_t id_;
        bool session_;

    public:
        Logger(uint64_t id, bool session = false);
        void write(const char *file, int line, uint level, const char *message);
    };
}

#endif