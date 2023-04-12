#include "logger.h"
#include "signal.h"

scyna::Logger::Logger(uint64_t id, bool session = false)
{
    this->id_ = id;
    this->session_ = session;
}

void scyna::Logger::add(uint level, std::string messgage)
{
    std::cout << messgage << std::endl;
    if (id_ > 0)
    {
        scyna_proto::LogCreatedSignal signal;
        signal.set_id(id_);
        signal.set_level(level);
        signal.set_text(messgage);
        signal.set_session(session_);
        signal.set_time(0); // FIXME
        Signal::Emit(Path::LOG_CREATED_CHANNEL, signal);
    }
}

void scyna::Logger::write(const char *file, int line, uint level, const char *message)
{
    char buffer[1024] = {0};
    // sprintf_s(buffer, sizeof(buffer), "%s(%d) : %s", fileName, line, message);
    this->add(level, message);
}
