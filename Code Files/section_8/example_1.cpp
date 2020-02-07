#include "generator.hpp"
#include <iostream>

template<typename T>
generator<T> fibonacci()
{
    T j = 0;
    T i = 1;

    co_yield j;

    for(;;)
    {
        co_yield i;
        T tmp = i;
        i += j;
        j = tmp;
    }
}

int main()
{
    auto gen = fibonacci<unsigned long long>();
    for(int i = 0; i < 20 && gen.next(); ++i)
    {
        std::cout << gen.getValue() << '\n';
    }
}
