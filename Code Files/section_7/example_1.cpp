#include <memory>
#include <thread>
#include <atomic>
#include <iostream>

int main()
{
    std::atomic<std::shared_ptr<int>> ptr = std::make_shared<int>(4);
    std::jthread threadA([&ptr]() mutable
    {
        ptr = std::make_shared<int>(10);
    });
    std::jthread threadB([&ptr]() mutable
    {
        ptr = std::make_shared<int>(20);
    });
}
