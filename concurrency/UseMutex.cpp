#include <list>
#include <mutex>
#include <algorithm>

std::list<int32_t> some_list;
std::mutex some_mutex;

void add_to_list(int32_t new_value)
{
    //std::lock_guard<std::mutex> guard(some_mutex);  // before c++17
    std::lock_guard guard(some_mutex);  // since c++17: template argument deduction
    // std::scoped_lock guard(some_mutex); // since C++17
    some_list.push_back(new_value);
}

bool list_contains(int32_t value_to_find)
{
    //std::lock_guard<std::mutex> guard(some_mutex);  // before c++17
    std::lock_guard guard(some_mutex);  // since C++17: template argument deduction
    // std::scope_lock guard(some_mutex);   // since C++17
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}