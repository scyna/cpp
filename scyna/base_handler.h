#ifndef BASE_HANDLER_H
#define BASE_HANDLER_H

#include <string>
#include <google/protobuf/util/json_util.h>
#include <nats/nats.h>

namespace scyna
{
    class BaseHandler
    {
    protected:
        natsSubscription *subscription_;

    public:
        virtual void onMessageReceived(natsConnection *nc, natsMsg *msg) = 0;
        void init(natsSubscription *sub)
        {
            this->subscription_ = sub;
        }

        virtual ~BaseHandler()
        {
            if (subscription_ != NULL)
            {
                natsSubscription_Unsubscribe(subscription_);
                natsSubscription_Destroy(subscription_);
            }
        }
    };

    static void _onMessageReceived_(natsConnection *nc, natsSubscription *sub, natsMsg *msg, void *closure)
    {
        auto handler = (scyna::BaseHandler *)closure;
        handler->onMessageReceived(nc, msg);
        natsMsg_Destroy(msg);
    }
}

#endif