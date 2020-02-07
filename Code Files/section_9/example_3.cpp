#include <iostream>
#include <string>

struct S
{
    std::string a;
    int b = 42;
    int c = -1;
};

int main()
{
    S s{.c = 3};
    std::cout << "\"" << s.a << "\", " << s.b << ", " << s.c << std::endl;
}
