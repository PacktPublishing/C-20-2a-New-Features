#include <iostream>

struct MyInt
{
    int v;
    constexpr MyInt(int v) : v{v} {}
    auto operator <=>(const MyInt&) const = default;
};

int main()
{
    MyInt iw1{1};
    MyInt iw2{2};

    std::cout << (iw1 < iw2 == true  ) << " "
              << (iw1 > iw2 == false ) << " "
              << (iw1 >= iw2 == false) << " "
              << (iw1 <= iw2 == true ) << " "
              << (iw1 == iw2 == false) << " "
              << (iw1 != iw2 == true ) << " "
              << (iw1 > 0 == true)     << std::endl;

    std::cout << (0 < iw1 == true)     << " "
              << (0 > iw1 == false)    << std::endl;
    static_assert(MyInt(1) > 0);
}
