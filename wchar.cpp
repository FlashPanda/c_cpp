#include <wchar.h>
#include <iostream>

int main()
{
	const wchar_t* a = L"Test wchar_t";
	const char* b = "Test char";
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	getchar();
	return 0;
}