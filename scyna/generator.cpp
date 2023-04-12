#include "generator.h"
#include "engine.h"
#include "path.h"

bool scyna::Generator::getID_()
{
    scyna_proto::Request request;
    request.set_json(false);
    request.set_traceid(0);

    auto engine = Engine::instance();

    auto response = engine->natsRequest(Utils::publishUrl(Path::GEN_GET_ID_URL), request);

    if (response == nullptr)
    {
        return false;
    }

    scyna_proto::GetIDResponse id;
    if (!id.ParseFromString(response->body()))
    {
        return false;
    }

    this->prefix_ = id.prefix();
    this->value_ = id.start();
    this->end_ = id.end();
    return true;
}

uint64_t scyna::Generator::next()
{
    boost::lock_guard<boost::mutex> guard(mutex_);
    if (value_ < end_)
    {
        value_++;
    }
    else if (!getID_())
    {
        std::cerr << "Can not get ID from server" << std::endl;
        exit(0);
    }
    return Utils::calculateID(prefix_, value_);
}
