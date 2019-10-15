#include <iostream>

int main()
{
	uint8_t x = 12;
	
	// Yeah, we must add '+' sign before the variable, 'cause the default 
	// output format is unsigned char
	std::cout << +x << std::endl;
	
	return 0;
}