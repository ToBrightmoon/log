#include "log.hpp"
#include "message_appender_file.h"
#include "message_appender_console.h"

using namespace Log;

int main()
{
    Logger<1000> logger;
    auto appenderConsole = std::make_shared<MessageAppenderConsole>();
    auto appenderFile = std::make_shared<MessageAppenderFile>("/home/chengzhao/log/log.txt");

    LogErrorCode code1 = logger.addAppender(1,appenderConsole);
    LogErrorCode code2 = logger.addAppender(2,appenderFile);
    if(code1 == LogErrorCode::NO_ERROR)
    {
        std::cout << "No Error 1" << "\n";
    }
    if(code2 == LogErrorCode::NO_ERROR)
    {
        std::cout << "No Error 2" << "\n";
    }

    logger.setFilterLeve(LogLevel::INFO);

    logger.selectAppender(1);

    LOG_DEBUG(logger,"Hello");
    return 0;
}
