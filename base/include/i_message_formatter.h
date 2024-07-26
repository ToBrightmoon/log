
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
            IMessageFormatter() = default;

            [[nodiscard]] virtual std::string format() const noexcept = 0;

            [[nodiscard]] virtual LogLevel getLogLevel() const noexcept = 0;

            virtual ~IMessageFormatter() = default;

        protected:

            std::string getLevelString(LogLevel) const ;
        };
    }
}

#endif //EASY_LOG_I_MESSAGE_FORMAT_H
