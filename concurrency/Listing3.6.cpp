// Using std::lock() and std::lock_guard in a swap operation
#include <mutex>

class some_big_object;
void swap(some_big_object& lhs, some_big_object& rs);
class X
{
private:
    some_big_object some_detial;
    std::mutex m;

public:
    X(some_big_object const& sd) : some_detial(sd) {}

    friend void swap(X& lhs, X& rhs)
    {
        if (&lhs == &rhs)
            return;

        // std::lock(lhs.m, rhs.m);
        // std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        // std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        std::scoped_lock guard(lhs.m, rhs.m);
        swap(lhs.some_detail, rhs.some_detail);
    }
};