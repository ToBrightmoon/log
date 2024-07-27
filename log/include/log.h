
#ifndef EASY_LOG_LOG_H
#define EASY_LOG_LOG_H

#include <map>
#include <mutex>
#include <atomic>
#include <thread>
#include <condition_variable>

#include "log_message.h"
#include "message_buffer.hpp"
#include "log_error_code.h"

using namespace Log::Base;

namespace Log
{
    template<std::size_t Capacity = 100>
    class Logger
    {
        using IMessageAppenderPtr = std::shared_ptr<IMessageAppender>;
    public:
        Logger();

        void stop();

        void setFilterLeve(LogLevel);

        LogErrorCode addAppender(int type,std::shared_ptr<IMessageAppender>);

        LogErrorCode selectAppender(int type);

        LogErrorCode log(const IMessageFormatter&);

        ~Logger();

    private:
        void process();

    private:
        std::atomic<bool> isStop_ = false;

        std::thread worker_;

        std::mutex appenderMutex_;

        std::mutex writeMutex_;

        std::mutex levelMutex_;

        LogLevel minLevel_ = LogLevel::INFO;

        IMessageAppenderPtr currentAppender_ = nullptr;

        std::map<int,IMessageAppenderPtr> appenderMap_;

        std::condition_variable cvWrite_;

        std::condition_variable cvRead_;

        Buffer<LogMessage,Capacity> writeLogBuffer_;

        Buffer<LogMessage,Capacity> readLogBuffer_;
    };

#define LOG_DEBUG(logger, message) (logger).log(MessageFormatterBase(LogLevel::DEBUG, message, __FILE__, __LINE__))
#define LOG_INFO(logger, message) (logger).log(MessageFormatterBase(LogLevel::INFO, message, __FILE__, __LINE__))
#define LOG_WARN(logger, message) (logger).log(MessageFormatterBase(LogLevel::WARN, message, __FILE__, __LINE__))
#define LOG_ERROR(logger, message) (logger).log(MessageFormatterBase(LogLevel::ERROR, message, __FILE__, __LINE__))
#define LOG_FATAL(logger, message) (logger).log(MessageFormatterBase(LogLevel::FATAL, message, __FILE__, __LINE__))

}

#endif //EASY_LOG_LOG_H
