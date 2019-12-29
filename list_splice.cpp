#include <iostream>
#include <list>

std::ostream& operator<<(std::ostream& out, const std::list<int32_t>& list)
{
    for (auto &i : list)
        out << " " << i;
    return out;
}

int main()
{
    /****************************************/
    // splice will insert the elements before first parameter.
    std::list<int32_t> list1 = {1, 2, 3, 4, 5, 6};
    std::list<int32_t> list2 = {10, 20, 30, 40, 50, 60};
    std::cout << "list1: " << list1 << std::endl;
    list1.splice(list1.begin(), list2);
    std::cout << "After [list1.splice(list1.begin(), list2);]" << "\n";
    std::cout << "list1: " << list1 << std::endl << std::endl;

    list1 = {1, 2, 3, 4, 5, 6};
    list2 = {10, 20, 30, 40, 50, 60};
    std::cout << "list1: " << list1 << std::endl;
    list1.splice(list1.end(), list2);
    std::cout << "After [list1.splice(list1.end(), list2);]" << "\n";
    std::cout << "list1: " << list1 << std::endl << std::endl;
    /****************************************/

    /****************************************/
    list1 = {1, 2, 3, 4, 5, 6};
    list2 = {10, 20, 30, 40, 50, 60};
    typename std::list<int32_t>::iterator it = list1.begin();
    ++it; ++it; // point to '3'
    std::cout << "list1: " << list1 << std::endl;
    list1.splice(it, list2);
    std::cout << "After [list1.splice(it, list2);]" << "\n";
    std::cout << "list1: " << list1 << std::endl << std::endl;
    /****************************************/

    /****************************************/
    list1 = {1, 2, 3, 4, 5, 6};
    list2 = {10, 20, 30, 40, 50, 60};
    typename std::list<int32_t>::iterator it1 = list2.begin();
    ++it1; ++it1; // point to '30'
    typename std::list<int32_t>::iterator it2 = it1;
    ++it2; ++it2;
    std::cout << "list1: " << list1 << std::endl;
    list1.splice(list1.begin(), list2, it1, it2);
    std::cout << "After [list1.splice(list1.begin(), list2, it1, it2);]" << "\n";
    std::cout << "list1: " << list1 << std::endl << std::endl;
    /****************************************/
}