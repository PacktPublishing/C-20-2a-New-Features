#include "inc.hpp"

int main()
{
    std::vector<int> numbers = { 1, 2, 3 ,4, 5 };

    std::vector<int> evenNumbers;
    std::copy_if(numbers.begin(), numbers.end(),
       std::back_inserter(evenNumbers), [](int n){ return n % 2 == 0; });

    std::vector<int> results;
    std::transform(evenNumbers.begin(), evenNumbers.end(),
       std::back_inserter(results), [](int n){ return n * 2; });

    std::cout << format("\nc++98: {}\n", fmt::join(results, ", "));

    auto result2 = numbers
        | ranges::views::filter([](int n){ return n % 2 == 0; })
        | ranges::views::transform([](int n){ return n * 2; })
        | ranges::to_vector;

    std::cout << format("\nc++20: {}\n", fmt::join(result2, ", "));
}

