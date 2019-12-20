#include<iostream>
#include <thread>
#include <future>

int DoSomething()
{
    for (int32_t i = 0; i < 1000000; ++i)
        for(int32_t j = 0; j < 1000; ++j)
            int x = j;

    return 8;
}

class X
{
public:
    void foo(int32_t t, std::string const& st)
    {
        std::cout << "X::foo ... " << std::endl;
    }
    std::string bar(std::string const& st)
    {
        std::cout << "X::bar ... " << std::endl; 
        return std::string("return from bar");
    }
};

struct Y
{
    int32_t m = 2;
    double operator() (double t)
    {
        return t * m;
    }
};

int main()
{
    // future from an async()
    // std::future<int32_t> f2 = std::async(DoSomething);
    // std::future<int32_t> f3 = std::async([]{return 9;});

    // std::cout << "Waiting..." << std::flush;
    // f2.wait();
    // f3.wait();

    // std::cout << "Done!" << std::endl;
    // std::cout << "f2 = " << f2.get() << std::endl
    //     << "f3 = " << f3.get() << std::endl;

    // X x;
    // std::future<void> f1 = std::async(&X::foo, &x, 42, "hello");
    // std::future<std::string> f2 = std::async(&X::bar, &x, "goodbye");

    // std::cout << "Waiting..." << std::flush;
    // f1.wait();
    // f2.wait();
    // std::cout << "Done!" << std::endl;
    // std::cout << "f2 = " << f2.get().c_str() << std::endl;

    Y y;
    y.m = 4;
    std::future<double> f3 = std::async(Y(), 3.141);
    std::future<double> f4 = std::async(std::ref(y), 3.141);
    std::cout << "Waiting..." << std::flush;
    f3.wait();
    f4.wait();
    std::cout << "Done!" << std::endl;
    std::cout << "f3 = " << f3.get() << std::endl;
    std::cout << "f4 = " << f4.get() << std::endl;

    return 0;
}