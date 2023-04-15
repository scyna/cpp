#ifndef SETTING_H
#define SETTING_H

#include <map>
#include <boost/thread.hpp>
#include "signal.h"
#include "proto/generated/engine.pb.h"

namespace scyna
{
    class Setting
    {
    private:
        std::map<std::string, std::string> data_;
        boost::mutex mutex_;

    private:
        void update_(std::string key, std::string value);
        void remove_(std::string key);
        bool load_(std::string key, std::string &value);

    public:
        bool set(std::string key, std::string value);
        bool get(std::string key, std::string &value);
        bool remove(std::string key);
    };

    class SettingUpdatedHandler : public Signal::Handler<scyna_proto::SettingUpdatedSignal>
    {
        void execute() override
        {
            /* TODO */
        }
    };

    class SettingRemovedHandler : public Signal::Handler<scyna_proto::SettingRemovedSignal>
    {
        void execute() override
        {
            /* TODO */
        }
    };
}

#endif