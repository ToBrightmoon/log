#include <filesystem>

#include "message_appender_file.h"

using namespace Log;
using namespace Log::Base;

MessageAppenderFile::MessageAppenderFile(const std::string &fileName):fileName_(fileName)
{

}

bool MessageAppenderFile::init()
{
    std::filesystem::path filepath(fileName_);
    std::filesystem::path dir = filepath.parent_path();

    if (!std::filesystem::exists(dir)) {
        if (!std::filesystem::create_directories(dir)) {
            return false;
        }
    }

    logFile_.open(fileName_, std::ios::app);
    if (!logFile_.is_open()) {
        return false;
    }
    isStart_ = true;
    return true;
}

bool MessageAppenderFile::append(const std::string & message)
{
    if(isStart_ && logFile_.is_open())
    {
        logFile_ << message;
        return true;
    }
    return false;
}

MessageAppenderFile::~MessageAppenderFile()
{
    if(isStart_)
    {
        logFile_.close();
    }
}


