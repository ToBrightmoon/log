
#include <iostream>

#include "message_appender_console.h"

using namespace Log;
using namespace Log::Base;

bool MessageAppenderConsole::append(const std::string & message) const
{
    if(isStart_)
    {
        std::cout << message;
        return true;
    }
    return false;
}

bool MessageAppenderConsole::init()
{
    isStart_ = true;
    return true;
};
