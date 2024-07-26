#include "i_message_formatter.h"

using namespace Log;
using namespace Log::Base;

std::string IMessageFormatter::getLevel(Log::LogLevel level)
{
    switch (level)
    {
        case(LogLevel::INFO):
            return "INFO";
        case (LogLevel::WARN):
            return "WARN";
        case(LogLevel::DEBUG):
            return "DEBUG";
        case (LogLevel::ERROR):
            return "ERROR";
        case (LogLevel::FATAL):
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}
