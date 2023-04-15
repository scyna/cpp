#include "setting.h"
#include "proto/generated/error.pb.h"

void scyna::Setting::update_(std::string key, std::string value)
{
    boost::lock_guard<boost::mutex> guard(mutex_);
    data_[key] = value;
}

void scyna::Setting::remove_(std::string key)
{
    boost::lock_guard<boost::mutex> guard(mutex_);
    data_.erase(key);
}

bool scyna::Setting::load_(std::string key, std::string &value)
{
    boost::lock_guard<boost::mutex> guard(mutex_);
    auto it = data_.find(key);
    if (it != data_.end())
    {
        value = it->second;
        return true;
    }
    return false;
}

bool scyna::Setting::set(std::string key, std::string value)
{
    auto engine = Engine::Instance();
    scyna_proto::WriteSettingRequest request;
    request.set_key(key);
    request.set_module(Engine::Module());
    request.set_value(value);

    auto response = engine->sendRequest<scyna_proto::WriteSettingRequest, scyna_proto::Error>(Path::SETTING_WRITE_URL, request);
    if (response != nullptr)
    {
        update_(key, value);
        return true;
    }
    return false;
}

bool scyna::Setting::get(std::string key, std::string &value)
{
    if (load_(key, value))
    {
        return true;
    }

    auto engine = Engine::Instance();
    scyna_proto::ReadSettingRequest request;
    request.set_key(key);
    request.set_module(Engine::Module());

    auto response = engine->sendRequest<scyna_proto::ReadSettingRequest, scyna_proto::ReadSettingResponse>(Path::SETTING_READ_URL, request);
    if (response != nullptr)
    {
        value = response->value();
        update_(key, value);
        return true;
    }

    return false;
}

bool scyna::Setting::remove(std::string key)
{
    auto engine = Engine::Instance();
    scyna_proto::RemoveSettingRequest request;
    request.set_key(key);
    request.set_module(Engine::Module());
    auto response = engine->sendRequest<scyna_proto::RemoveSettingRequest, scyna_proto::Error>(Path::SETTING_READ_URL, request);
    if (response != nullptr)
    {
        remove_(key);
        return true;
    }
    return false;
}
