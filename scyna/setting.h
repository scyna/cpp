#ifndef SETTING_H
#define SETTING_H

#include "signal.h"
#include "proto/generated/engine.pb.h"

namespace scyna
{
    class Setting
    {
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