#include <unistd.h>
#include <iostream>

int main () {
	char dir_name[] = "/tmp/this/is/a/test";
	int result = access (dir_name, 0);
	
	std::cout << "判断的目录:" << dir_name << std::endl;
	if (result == 0)
		std::cout << "目录存在，result的值为0" << std::endl;
	else
		std::cout << "目录不存在，result的值为-1" << std::endl;
		
	char dir_name1[] = "/tmp";
	result = access (dir_name1, 0);
	std::cout << "判断的目录：" << dir_name1 << std::endl;
	if (result == 0)
		std::cout << "目录存在，result的值为0" << std::endl;
	else
		std::cout << "目录不存在，result的值为-1" << std::endl;
}
