#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

int main()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
    std::cout << "24 hours ago, the time was " 
              << std::put_time(std::localtime(&now_c), "%F %T") << "\n";

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::cout << "Hello world\n";
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Printing took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << "us.\n";

    start = std::chrono::steady_clock::now();
    end = std::chrono::steady_clock::now();
    std::cout << "Getting two time points took "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
              << "ns.\n";

}