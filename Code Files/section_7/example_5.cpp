#include <memory>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>

int main()
{
    std::flex_barrier barrier{2};
    std::atomic<int> counter;

    for(;;)
    {
        std::jthread threadA([&]()
        {
            for(int i = 0; i < 5; ++i)
            {
                ++counter;
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }
            barrier.arrive_and_wait();
            std::cout << "final counter from A: " << counter << std::endl;
        });
        std::jthread threadB([&]()
        {
            for(int i = 0; i < 10; ++i)
            {
                ++counter;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            barrier.arrive_and_wait();
            std::cout << "final counter from B: " << counter << std::endl;
        });
    }
}
