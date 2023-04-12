#include <google/protobuf/message.h>
#include "signal.h"
#include "engine.h"

void scyna::Signal::Emit(std::string channel, const google::protobuf::Message &m)
{
    auto nc = Engine::instance()->connection();
    auto result = m.SerializeAsString();
    natsConnection_Publish(nc, channel.c_str(), (const void *)result.c_str(), result.length());
}