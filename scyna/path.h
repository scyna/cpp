#ifndef PATH_H
#define PATH_H

#include <string>

namespace scyna
{
    namespace Path
    {
        const std::string GEN_GET_ID_URL = "/scyna/generator/id";
        const std::string GEN_GET_SN_URL = "/scyna/generator/sn";
        const std::string SESSION_CREATE_URL = "/scyna/session/create";
        const std::string SESSION_UPDATE_CHANNEL = "scyna.session.update";
        const std::string SESSION_END_CHANNEL = "scyna.session.end";
        const std::string LOG_CREATED_CHANNEL = "scyna.log";
        const std::string SETTING_WRITE_URL = "/scyna/setting/write";
        const std::string SETTING_READ_URL = "/scyna/setting/read";
        const std::string SETTING_REMOVE_URL = "/scyna/setting/remove";
        const std::string SETTING_UPDATE_CHANNEL = "scyna.setting.updated.";
        const std::string SETTING_REMOVE_CHANNEL = "scyna.setting.removed.";
        const std::string CALL_WRITE_CHANNEL = "scyna.call.write";
        const std::string APP_UPDATE_CHANNEL = "scyna.application.updated";
        const std::string CLIENT_UPDATE_CHANNEL = "scyna.client.updated";
        const std::string AUTH_CREATE_URL = "/scyna/auth/create";
        const std::string AUTH_GET_URL = "/scyna/auth/get";
        const std::string AUTH_LOGOUT_URL = "/scyna/auth/logout";
        const std::string TRACE_CREATED_CHANNEL = "scyna.trace";
        const std::string START_TASK_URL = "/scyna/task/start";
        const std::string STOP_TASK_URL = "/scyna/task/stop";
    }
}

#endif