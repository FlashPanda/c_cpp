#include <atomic>
#include <thread>

class barrier
{
private:
    unsigned const count;
    std::atomic<unsigned> spaces;
    std::atomic<unsigned> generation;

public:
    explicit barrier(unsigned count_) : // 1
        count(count_), spaces(count), generation(0)
        {}
    void wait()
    {
        unsigned const my_generation = generation;  // 2
        if (!--spaces)  // 3
        {
            spaces = count; // 4
            ++generation;   // 5
        }
        else 
        {
            while(generation == my_generation) // 6
                std::this_thread::yield();  // 7
        }
    }
};