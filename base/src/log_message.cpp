
#include "log_message.h"

using namespace Log;
using namespace Log::Base;

LogMessage::LogMessage(const Log::Base::IMessageFormatter &formatter, IMessageAppenderPtr appender):
message_(formatter.format()),level_(formatter.getLogLevel()),appender_(appender)
{

}

bool LogMessage::operator<(const Log::Base::LogMessage &logMessage) const
{
    return level_ < logMessage.getLogLevel();
}

bool LogMessage::operator<(Log::LogLevel level) const
{
    return level_ < level;
}

bool LogMessage::append()
{
    if(appender_ == nullptr)
    {
        return appender_->append(message_);
    }
}

LogLevel LogMessage::getLogLevel() const
{
    return level_;
}