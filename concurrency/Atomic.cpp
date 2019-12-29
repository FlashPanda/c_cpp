#include <iostream>
#include <atomic>

struct X
{
    int32_t m_X;
    int32_t m_Y;
};

int main()
{
    int32_t x = 0;
    std::atomic<int32_t> y(0);

    std::cout << "y is " << (y.is_lock_free()? "lock free" : "not lock free") << std::endl;
    std::cout << std::endl;

    // std::atomic<X> xx;  // compile error
    // std::cout << "xx is " << (xx.is_lock_free()? "lock free" : "not lock free") << std::endl;
    // std::cout << std::endl;

    std::atomic<int32_t> z(0);
    std::cout << "z is " << (std::atomic<int32_t>::is_always_lock_free ? "always lock free" : "not always lock free") << std::endl << std::endl;
	
}