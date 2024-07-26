#include <iostream>

#include "formatter_base.h"

using namespace std;
using namespace Log;
using namespace Log::Base;

int main()
{
    if( MessageFormatterBase(LogLevel::INFO,"info",__FILE__,__LINE__).getLogLevel() < LogLevel::DEBUG)
    {
        std::cout << "SUCCESS" << "\n";
    }
    std::cout << MessageFormatterBase(LogLevel::INFO,"info",__FILE__,__LINE__).format() ;
    std::cout << MessageFormatterBase(LogLevel::WARN,"warn",__FILE__,__LINE__).format() ;
    std::cout << MessageFormatterBase(LogLevel::DEBUG,"debug",__FILE__,__LINE__).format() ;
    std::cout << MessageFormatterBase(LogLevel::ERROR,"error",__FILE__,__LINE__).format() ;
    std::cout << MessageFormatterBase(LogLevel::FATAL,"fatal",__FILE__,__LINE__).format() ;
}
