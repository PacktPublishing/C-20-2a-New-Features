#include <memory>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>

int main()
{
    std::counting_semaphore sem{0};
    std::jthread threadA([&sem]()
    {
        for(;;)
        {
            std::cout << "A+\n";
            sem.acquire();
            std::cout << "A unblocked\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            sem.release();
            std::cout << "A-\n";
        }
    });
    std::jthread threadB([&sem]()
    {
        for(;;)
        {
            std::cout << "B+\n";
            sem.acquire();
            std::cout << "B unblocked\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            sem.release();
            std::cout << "B-\n";
        }
    });

    std::cout << "starting threads";
    sem.release();
}
