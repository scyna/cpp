#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdint.h>
#include <boost/thread.hpp>
#include "utils.h"
#include "proto/generated/engine.pb.h"
#include "proto/generated/scyna.pb.h"

namespace scyna
{
    class Generator
    {
    private:
        uint32_t prefix_;
        uint64_t value_;
        uint64_t end_;
        boost::mutex mutex_;

    public:
        uint64_t next();

    private:
        bool getID_();
    };
}

#endif