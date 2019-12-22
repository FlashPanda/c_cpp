#include <iostream>
#include <thread>

int main()
{
    uint32_t n = std::thread::hardware_concurrency();

    // Output 8 on my i7-9700K based computer.
    std::cout << n << " concurrent threads are supported.\n";
}