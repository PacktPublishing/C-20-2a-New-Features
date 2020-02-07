#include <inc.hpp>
#include <compare>

template<typename T>
struct MyValue
{
    T v;
    constexpr MyValue(T v) : v{v} {}
    auto operator <=>(const MyValue&) const = default;
};

int main()
{
    MyValue iw1{1.0f};
    MyValue iw2{NAN};

    cout << "lhs lower: " <<(iw1 <=> iw2 < 0) << endl;
    cout << "lhs equal: " <<(iw1 <=> iw2 == 0) << endl;
    cout << "lhs higher: " <<(iw1 <=> iw2 > 0) << endl;

    cout << typeName(iw2 <=> iw2) << endl;
}
