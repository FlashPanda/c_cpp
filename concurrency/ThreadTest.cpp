#include <iostream>
#include <thread>

int32_t i = 0;

void Add100Times1()
{
    for (int32_t j = 0; j < 100000; ++j)
        ++i;
}

void Add100Times2()
{
    for (int32_t j = 0; j < 100000; ++j)
        ++i;
}

int main()
{
    std::thread t1(Add100Times1);
    std::thread t2(Add100Times2);

    std::cout << "The final i is " << std::endl;
    t1.join();
    t2.join();

    std::cout << i << std::endl;
    // 185524,166968,200000,186661... and so on.
}