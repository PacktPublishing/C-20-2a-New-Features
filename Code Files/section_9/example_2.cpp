#include <vector>
#include <iostream>

struct S
{
    auto fun()
    {
        return [=, this] { std::cout << s << std::endl; };
    }
    std::string s;
};

int main()
{
    auto fun = []<typename T>(const std::vector<T>& vec)
    {
        std::cout << std::size(vec) << std::endl;
    };

    std::vector<int> v{1, 2, 3};
    fun(v);
}
