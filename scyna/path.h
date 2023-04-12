#ifndef PATH_H
#define PATH_H

#include <string>

namespace scyna
{
    namespace Path
    {
        static const std::string GEN_GET_ID_URL = "/scyna/generator/id";
        static const std::string GEN_GET_SN_URL = "/scyna/generator/sn";
        static const std::string SESSION_CREATE_URL = "/scyna/session/create";
        static const std::string SESSION_UPDATE_CHANNEL = "scyna.session.update";
        static const std::string SESSION_END_CHANNEL = "scyna.session.end";
        static const std::string LOG_CREATED_CHANNEL = "scyna.log";
        static const std::string SETTING_WRITE_URL = "/scyna/setting/write";
        static const std::string SETTING_READ_URL = "/scyna/setting/read";
        static const std::string SETTING_REMOVE_URL = "/scyna/setting/remove";
        static const std::string SETTING_UPDATE_CHANNEL = "scyna.setting.updated.";
        static const std::string SETTING_REMOVE_CHANNEL = "scyna.setting.removed.";
        static const std::string CALL_WRITE_CHANNEL = "scyna.call.write";
        static const std::string APP_UPDATE_CHANNEL = "scyna.application.updated";
        static const std::string CLIENT_UPDATE_CHANNEL = "scyna.client.updated";
        static const std::string AUTH_CREATE_URL = "/scyna/auth/create";
        static const std::string AUTH_GET_URL = "/scyna/auth/get";
        static const std::string AUTH_LOGOUT_URL = "/scyna/auth/logout";
        static const std::string TRACE_CREATED_CHANNEL = "scyna.trace";
        static const std::string START_TASK_URL = "/scyna/task/start";
        static const std::string STOP_TASK_URL = "/scyna/task/stop";
    }
}

#endif