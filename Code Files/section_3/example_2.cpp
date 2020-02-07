#include "inc.hpp"

int main()
{
    int n = 10;
    auto square_fn = [](int x){ return x * x;};

    std::vector<int> input(static_cast<size_t>(n));
    std::iota(input.begin(), input.end(), 0);
    std::vector<int> results;
    std::transform(input.begin(),input.end(),
        std::back_inserter(results), square_fn);

    std::cout << format("\nc++98: {}\n", fmt::join(results, ", "));

    //auto result2 = ranges::views::iota(0, n)
        //| ranges::views::transform(square_fn);

    auto result2 =
        ranges::views::transform(ranges::views::iota(0, n), square_fn);
    std::cout << format("\nc++20: {}\n", fmt::join(result2, ", "));
}
