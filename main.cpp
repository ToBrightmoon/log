
#include "log_message.h"
#include "message_buffer.hpp"

#include <iostream>

using namespace Log::Base;



int main()
{
    Buffer<LogMessage,100> logBuffer;

    LogMessage message();
    logBuffer.add()
}