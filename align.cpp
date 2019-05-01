#include <iostream>

#ifndef ALIGN
#define ALIGN(x,a)	(((x) + ((a) - 1)) & ~((a) - 1))
#endif

int main()
{
	uint8_t* p;
	p = reinterpret_cast<uint8_t*> (malloc(10));
	
	std::cout << "p value is: " << reinterpret_cast<size_t>(p) << std::endl;
	
	p = reinterpret_cast<uint8_t*>(ALIGN(reinterpret_cast<size_t>(p), 16));
	
	std::cout << "p value is: " << reinterpret_cast<size_t>(p) << std::endl;
}