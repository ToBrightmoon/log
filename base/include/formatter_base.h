
#ifndef EASY_LOG_FORMATTER_BASE_H
#define EASY_LOG_FORMATTER_BASE_H

#include "i_message_formatter.h"

namespace Log
{
    namespace Base
    {
        class MessageFormatterBase : public IMessageFormatter
        {
        public:

            explicit MessageFormatterBase(LogLevel,const std::string&,const std::string&,int);

            std::string format() const override;

        private:

            LogLevel level_;

            std::string message_;

            std::string file_;

            int line_;
        };
    }
}

#endif //EASY_LOG_FORMATTER_BASE_H
