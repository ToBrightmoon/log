
#ifndef EASY_LOG_LOG_MESSAGE_H
#define EASY_LOG_LOG_MESSAGE_H

#include <memory>

#include "log_level.h"
#include "i_message_appender.h"
#include "i_message_formatter.h"

namespace Log::Base
{
    class LogMessage : NoCopyAbled
    {
        using IMessageAppenderPtr =  std::shared_ptr<IMessageAppender>;

    public:
        LogMessage() = default;

        explicit LogMessage(const IMessageFormatter&, IMessageAppenderPtr appenderPtr);

        bool append();

        bool operator<(const LogMessage& logMessage) const;

        bool operator<(LogLevel level) const;

        ~LogMessage() = default;

    private:
        [[nodiscard]] LogLevel getLogLevel() const;

        std::string message_;

        LogLevel level_ = LogLevel::INFO;

        IMessageAppenderPtr appender_ = nullptr;
    };
}

#endif //EASY_LOG_LOG_MESSAGE_H
