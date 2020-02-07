#include <concepts>
#include <algorithm>
#include <vector>

struct MyStruct
{
    int value;
    MyStruct(int v) : value{v} {}
    auto operator<=>(const MyStruct&) const = default;
};

template<typename T, typename F>
    requires std::invocable<F, typename T::value_type, typename T::value_type>
void mysort(T begin, T end, F f)
{
    std::sort(begin, end, f);
}

template<typename T>
    requires std::totally_ordered<typename T::value_type>
void mysort2(T begin, T end)
{
    std::sort(begin, end);
}

int main()
{
    std::vector<MyStruct> vi{1, 3, 3, 2, 6};
    mysort(vi.begin(), vi.end(),
        [](MyStruct lhs , MyStruct rhs) -> bool
        {
            return lhs < rhs;
        }
    );
    mysort2(vi.begin(), vi.end());
}
