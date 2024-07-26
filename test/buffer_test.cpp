#include "message_buffer.hpp"

#include <iostream>

using namespace Log::Base;

template<class T>
void print_ab(const T& a, const T& b)
{
    for(int i = 0 ; i < a.maxCapacity(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    for(int i = 0 ; i < b.maxCapacity(); ++i)
    {
        std::cout << b[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    Log::Base::Buffer<int,5> a ;
    Buffer<int,5> b;
    for(int i = 1; i < 6 ; ++i)
    {
        a.add(i);
    }

    for(int i = 6; i < 11 ; ++i)
    {
        b.add(i);
    }

    print_ab(a,b);

    a.transData(b);

    print_ab(a,b);

}
