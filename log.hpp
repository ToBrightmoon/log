
#include <iostream>
#include <mutex>
#include <iomanip>
#include <chrono>
#include <iosfwd>
#include <sstream>
#include <fstream>
#include <iomanip> 
// 定义日志级别
enum class LogLevel {
    INFO,
    WARNING,
    ERRORS
};

class Logger {

public:
    Logger(LogLevel level, const char* file, int line);
       

    static void LogSet(const std::string filePath);

    ~Logger();

    static void LogClose();

    template <typename T>
    Logger& operator<<(const T& value) {
        std::lock_guard<std::mutex> lock(mux);
        message << value;
        return *this;
    }

private:

    static std::mutex mux;
    static std::ofstream logFile;

    LogLevel level;
    const char* file;
    int line;
    std::string dateTime;
    std::ostringstream message;
   
    static const char* logLevelToString(LogLevel level);

};

#define LOG(level, filePath) Logger(level, __FILE__, __LINE__)
#define LOG_SET(filePath) Logger::LogSet(filePath)
#define LOG_INFO Logger(LogLevel::INFO, __FILE__, __LINE__)
#define LOG_WARN Logger(LogLevel::WARNING, __FILE__, __LINE__)
#define LOG_ERROR Logger(LogLevel::ERRORS, __FILE__, __LINE__)
#define LOG_CLOSE Logger::LogClose();
