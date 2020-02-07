#include <inc.hpp>
#include <compare>

struct MyValue
{
    int v;
    constexpr MyValue(int v) : v{v} {}
    //auto operator <=>(const MyValue& rhs) const = default;
    auto operator <=>(const MyValue& rhs) const
    {
        cout << "operator<=> called with: " << v << ", " << rhs.v << endl;
        return v <=> rhs.v;
    }
};

int main()
{
    MyValue iw1{2};
    MyValue iw2{3};

    iw1 <= iw2;
}
