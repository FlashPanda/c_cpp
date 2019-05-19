#include <iostream>

int main()
{
	int index = 30;
	int _index = (index >> 3) * 8 + (index & 0x07);
	int _index_ = (index >> 3) * 8 + index & 0x07;
	
	std::cout << "index = " << index << std::endl;
	std::cout << "_index = " << _index << std::endl;
	std::cout << "_index_ = " << _index_ << std::endl;
	std::cout << std::endl;
	
	return 0;
}