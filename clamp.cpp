#include<iostream>
#include<algorithm>

int main()
{
	int32_t t = 100;
	t = std::clamp(t, 20, 80);
	
	std::cout << t << std::endl;
	
	return 0;
}