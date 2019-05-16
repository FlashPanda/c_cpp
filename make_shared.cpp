// make_shared example
#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<int> foo = std::make_shared<int>(10);
	// same as:
	std::shared_ptr<int> foo2(new int(10));
	
	// output 
	std::cout << "*foo = " << *foo << std::endl;
	std::cout << "*foo2 = " << *foo2 << std::endl;
	
	// we can use 'auto' to let compiler conclude value type
	auto foo3 = std::make_shared<int>(10);
	std::cout << "*foo3 = " << *foo3 << std::endl;
}