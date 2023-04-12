#ifndef SETTING_H
#define SETTING_H

#include "signal.h"
#include "proto/generated/engine.pb.h"

namespace scyna
{
    class SettingUpdatedHandler : public Signal::Handler<scyna_proto::SettingUpdatedSignal>
    {
        void execute() override
        {
        }
    };

    class SettingRemovedHandler : public Signal::Handler<scyna_proto::SettingRemovedSignal>
    {
        void execute() override
        {
        }
    };

}

#endif