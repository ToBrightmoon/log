
#ifndef EASY_LOG_MESSAGE_APPENDER_CONSOLE_H
#define EASY_LOG_MESSAGE_APPENDER_CONSOLE_H

#include "i_message_appender.h"

namespace Log
{
    namespace Base
    {
        class MessageAppenderConsole : public IMessageAppender
        {
        public:
            MessageAppenderConsole() = default;

            ~MessageAppenderConsole() override = default;

            [[nodiscard]] bool append(const std::string &) override;

            bool init() override;

        private:
            bool isStart_ = false;
        };
    }
};

#endif //EASY_LOG_MESSAGE_APPENDER_CONSOLE_H
