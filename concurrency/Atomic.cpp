#include <iostream>
#include <atomic>

class X
{
public:
    X() : m_X(0), m_Y(0) {}
    ~X() {}

private:
    int32_t m_X;
    int32_t m_Y;
};

int main()
{
    int32_t x = 0;
    std::atomic<int32_t> y(0);

    std::cout << "y is " << (y.is_lock_free()? "lock free" : "not lock free") << std::endl;
    std::cout << std::endl;

    std::atomic<X> xx;
    std::cout << "xx is " << (xx.is_lock_free()? "lock free" : "not lock free") << std::endl;
    std::cout << std::endl;
}