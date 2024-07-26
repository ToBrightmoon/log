#include <chrono>
#include <sstream>
#include <iomanip>

#include "formatter_base.h"

using namespace Log;
using namespace Log::Base;

MessageFormatterBase::MessageFormatterBase(Log::LogLevel level, const std::string & msg, const std::string & file, int line)
:message_(msg),file_(file),line_(line)
{
    level_ = level;
}

std::string MessageFormatterBase::format() const
{
    std::ostringstream oss;
    auto now = std::chrono::system_clock::now();

    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::tm* now_tm = std::localtime(&now_time);

    oss << "[" << std::put_time(now_tm, "%Y:%m:%d:%H:%M:%S") << "]"
        << "[" << getLevelString(level_) << "]"
        << "[" << file_ << ":" << line_ << "]"
        << "[" << message_  << "]" << "\n";

    return oss.str();
}
