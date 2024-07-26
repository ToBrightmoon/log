#include <iostream>

#include "formatter_base.h"

using namespace std;
using namespace Log;
using namespace Log::Base;

int main()
{
    std::cout << MessageFormatterBase(LogLevel::DEBUG,"debug",__FILE__,__LINE__).format() ;
}
