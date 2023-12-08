
#define _CRT_SECURE_NO_WARNINGS

#include "clog.h"

std::ofstream Logger::logFile;
std::mutex Logger::mux;

Logger::Logger(LogLevel level, const char* file, int line)
    : level(level), file(file), line(line)
{
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    auto tm_now = *std::localtime(&time_t_now);

    std::ostringstream oss;
    oss << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S");
    dateTime = oss.str();
}

void Logger::LogSet(const std::string filePath)
{
    // 打开日志文件
    logFile.open(filePath, std::ios::out);
}

void Logger::LogClose()
{
    logFile.close();
}
Logger::~Logger() {
    std::lock_guard<std::mutex> lock(mux);
    logFile << "[" << dateTime << " " << "] "
        << "[" << logLevelToString(level) << "] "
        << "[" << file << ":" << line << "] "
        << message.str() << std::endl;
}

const char* Logger::logLevelToString(LogLevel level) {
    switch (level) {
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARNING:
        return "WARNING";
    case LogLevel::ERRORS:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}
