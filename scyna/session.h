#ifndef SESSION_H
#define SESSION_H

#include <stdint.h>
#include <boost/thread.hpp>

namespace scyna
{
    class Session
    {
    private:
        uint64_t id_;
        uint64_t sequence_;
        boost::mutex mutex_;

    public:
        uint64_t ID() { return id_; }
        uint64_t nextSequence()
        {
            boost::lock_guard<boost::mutex> guard(mutex_);
            return sequence_++;
        }
        Session(uint64_t id)
        {
            this->id_ = id;
            this->sequence_ = 1;
        }
    };
}

#endif