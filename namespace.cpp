#include <iostream>

namespace my
{
	using namespace std;
}

int main()
{
	// 这是可行的。用这种方式可以把std里的东西转到my里。
	my::cout << "success!" << my::endl;
	return 0;
}