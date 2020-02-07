#include <concepts>
#include <algorithm>
#include <vector>
#include <list>

struct MyStruct
{
    int value;
    MyStruct(int v) : value(v) {}
    //auto operator<=>(const MyStruct&) const = default;
};

template<typename It>
concept RandomAccessIterator = 
    requires(It i, typename std::incrementable_traits<It>::difference_type n)
{
    { i - i } -> std::same_as<decltype(n)>;
    { i + n } -> std::same_as<It>;
    { i - n } -> std::same_as<It>;
};

template<typename It>
concept LessThanComparable = requires(It a, It b)
{
    typename It::value_type;
    { *a < *b } -> std::same_as<bool>;
};

template<typename T>
    requires RandomAccessIterator<T> && LessThanComparable<T>
void mysort(T begin, T end)
{
    std::sort(begin, end);
}

int main()
{
    std::vector<MyStruct> vec{1, 3, 5 , 2, 2};
    
    //mysort(vec.begin(), vec.end());
}
