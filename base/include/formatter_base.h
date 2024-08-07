
#ifndef EASY_LOG_FORMATTER_BASE_H
#define EASY_LOG_FORMATTER_BASE_H

#include "i_message_formatter.h"

namespace Log::Base
{
    class MessageFormatterBase : public IMessageFormatter
    {
    public:
        MessageFormatterBase() = default;

        explicit MessageFormatterBase(LogLevel,const std::string&,const std::string&,int);

        [[nodiscard]] std::string format() const noexcept override;

        [[nodiscard]] LogLevel getLogLevel() const  noexcept override;

    private:

        LogLevel level_ = LogLevel::INFO;

        std::string message_;

        std::string file_;

        int line_ = 0;
    };
}

#endif //EASY_LOG_FORMATTER_BASE_H
