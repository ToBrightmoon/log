
#ifndef EASY_LOG_I_MESSAGE_FORMATTER_H
#define EASY_LOG_I_MESSAGE_FORMATTER_H

#include <string>

#include "log_level.h"

namespace Log
{
    namespace Base
    {
        class IMessageFormatter
        {
        public:
            virtual std::string format();

            virtual ~IMessageFormatter() = default;

        protected:

            std::string getLevelString(LogLevel);
        };
    }
}

#endif //EASY_LOG_I_MESSAGE_FORMAT_H
