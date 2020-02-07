#include <iostream>

#include <cppcoro/single_consumer_event.hpp>
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/when_all_ready.hpp>

int main()
{
    cppcoro::single_consumer_event event;

    auto consumer = [&]() -> cppcoro::task<>
    {
        std::cout << "consumer start\n";
        co_await event;
        std::cout << "consumer end\n";
    };

    auto producer = [&]() -> cppcoro::task<>
    {
        std::cout << "producer event set\n";
        event.set();
        std::cout << "producer returning\n";
        co_return;
    };

    cppcoro::sync_wait(cppcoro::when_all_ready(consumer(), producer()));
}
