//
// Created by chengzhao on 2024/7/27.
//

#ifndef EASY_LOG_LOG_ERROR_CODE_H
#define EASY_LOG_LOG_ERROR_CODE_H

namespace Log
{
    enum class LogErrorCode
    {
        NO_ERROR = 0,
        EXIST_APPENDER = 1,
        APPENDER_INIT_FAILE = 2,
        APPENDER_NULLPTR = 3,
        NOT_FIND_APPENDER = 4,
        NO_ADD_APPENDER = 5,
        NO_SELECT_APPENDER = 6,
        ADD_MESSAGE_ERROR = 7,
        LOGGER_IS_STOP = 8
    };
}
#endif //EASY_LOG_LOG_ERROR_CODE_H
