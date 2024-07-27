
#ifndef EASY_LOG_I_MESSAGE_APPENDER_H
#define EASY_LOG_I_MESSAGE_APPENDER_H

#include <string>

#include "nocopyable.h"

namespace Log
{
    namespace Base
    {
        class IMessageAppender : NoCopyAbled
        {
        public:
            IMessageAppender() = default;

            virtual bool init() = 0;

            virtual ~IMessageAppender() = default;

            [[nodiscard]] virtual bool append(const std::string&)  = 0;
        };
    }
}

#endif //EASY_LOG_I_MESSAGE_APPENDER_H
