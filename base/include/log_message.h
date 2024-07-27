
#ifndef EASY_LOG_LOG_MESSAGE_H
#define EASY_LOG_LOG_MESSAGE_H

#include "log_level.h"
#include "i_message_appender.h"
#include "i_message_formatter.h"

namespace Log::Base
{
    class LogMessage : NoCopyAbled
    {
    public:
        explicit LogMessage(const IMessageFormatter& formatter,IMessageAppender& appender);

        bool append();

        bool operator<(const LogMessage& logMessage) const;

        bool operator<(LogLevel level) const;

        ~LogMessage() = default;

    private:
        [[nodiscard]] LogLevel getLogLevel() const;

        const std::string message_;

        const LogLevel level_;

        IMessageAppender& appender_;
    };
}

#endif //EASY_LOG_LOG_MESSAGE_H
