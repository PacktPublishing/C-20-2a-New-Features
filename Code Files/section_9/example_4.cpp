#include <iostream>

consteval const char* f(bool v)
{
    return v ? "this is true" : "this is false";
}

constinit const char *c = f(true);

int main()
{
    constexpr bool v = false;
    std::cout << f(v) << std::endl;
}
