#include <iostream>
#include <concepts>
#include <compare>

template<typename T>
concept ThreeWayComparable = requires(T a, T b)
{
	{ a <=> b } -> std::convertible_to<std::partial_ordering>;
};

template<typename T> requires ThreeWayComparable<T>
auto comp(const T& a, const T& b)
{
	return a <=> b;
}

struct MyStruct
{
	auto operator<=>(const MyStruct&) const = default;
};

int main()
{
	std::cout << (comp(MyStruct{}, MyStruct{}) == 0) << std::endl;
}
