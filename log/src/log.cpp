#include "log.h"

using namespace Log;

template<std::size_t Capacity>
Logger<Capacity>::Logger()
{
    worker_ = std::thread([this](){ process();});
}

template<std::size_t Capacity>
Logger<Capacity>::~Logger()
{
    isStop_.store(true);
    cvRead_.notify_all();
    worker_.join();
}

template<std::size_t Capacity>
void Logger<Capacity>::stop()
{
   isStop_.store(true);
}

template<std::size_t Capacity>
void Logger<Capacity>::setFilterLeve(Log::LogLevel level)
{
    std::unique_lock<std::mutex> lock(levelMutex_);
    minLevel_ = level;
}

template<std::size_t Capacity>
LogErrorCode Logger<Capacity>::addAppender(int type, std::shared_ptr<IMessageAppender> appender)
{
    if(appender == nullptr)
    {
        return LogErrorCode::APPENDER_NULLPTR;
    }

    auto findRes = appenderMap_.find(type);
    if(findRes != appenderMap_.end())
    {
        return LogErrorCode::EXIST_APPENDER;
    }

    bool initRes = appender->init();
    if(!initRes)
        return LogErrorCode::APPENDER_INIT_FAILE;

    return LogErrorCode::NO_ERROR;
}

template<std::size_t Capacity>
LogErrorCode Logger<Capacity>::selectAppender(int type)
{
    if(appenderMap_.size() == 0)
    {
        return LogErrorCode::NO_ADD_APPENDER;
    }

    auto resFind = appenderMap_.find(type);
    if(resFind == appenderMap_.end())
    {
        return LogErrorCode::NOT_FIND_APPENDER;
    }

    {
        std::unique_lock<std::mutex> lock(appenderMutex_);
        currentAppender_ = resFind->second;
    }

    return LogErrorCode::NO_ERROR;
}

template<std::size_t Capacity>
LogErrorCode Logger<Capacity>::log(const Log::Base::IMessageFormatter & formatter)
{
    if(isStop_)
        return LogErrorCode::LOGGER_IS_STOP;

    IMessageAppenderPtr currPtr = nullptr;
    {
        std::unique_lock<std::mutex> lock(appenderMutex_);
        currPtr = currentAppender_;
    }
    if(currPtr == nullptr)
    {
        return LogErrorCode::NO_SELECT_APPENDER;
    }

    if(formatter.getLogLevel() < minLevel_)
    {
        return LogErrorCode::NO_ERROR;
    }

    LogMessage message(formatter,currPtr);
    {
        std::unique_lock<std::mutex> lock(writeMutex_);
        cvWrite_.wait(lock,[this](){return !writeLogBuffer_.isFull();});
        if(!writeLogBuffer_.add(message))
        {
            return LogErrorCode::ADD_MESSAGE_ERROR;
        }
        cvRead_.notify_all();
    }
    return LogErrorCode::NO_ERROR;
}

template<std::size_t Capacity>
void Logger<Capacity>::process()
{
    while(true)
    {
        int curr_size = 0;
        {
            std::unique_lock<std::mutex> lock(writeMutex_);
            cvRead_.wait(lock,[this]() {return writeLogBuffer_.isFull() || isStop_;});

            curr_size = writeLogBuffer_.size();
            readLogBuffer_.transData(writeLogBuffer_);
        }

        if(!isStop_)
        {
            cvWrite_.notify_all();
        }

        for(int i = 0 ; i < curr_size; ++i)
        {
            bool appendRes = readLogBuffer_.at(i).append();
            if(!appendRes) break;
        }

        if(isStop_)
        {
            return;
        }

    }
}