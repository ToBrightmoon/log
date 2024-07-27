#ifndef EASY_LOG_MESSAGE_APPENDER_FILE_H
#define EASY_LOG_MESSAGE_APPENDER_FILE_H

#include <fstream>

#include "i_message_appender.h"

namespace Log::Base
{
    class MessageAppenderFile : public IMessageAppender
    {
    public:
        explicit MessageAppenderFile(const std::string& filename);

        bool init() override;

        bool append(const std::string &)  override;

        ~MessageAppenderFile() override;

    private:
        bool isStart_ = false;

        std::string fileName_;

        std::ofstream logFile_;
    };
}



#endif
