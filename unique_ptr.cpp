#include <iostream>
#include <memory>

// 必须通过引用传递std::unique_ptr<int>，
// 因为unique_ptr没有显式的赋值或者拷贝构造函数
void Function(std::unique_ptr<int>& ptr)
{
	*ptr = 20;
}

// 可以通过右值引用传递unique_ptr，
// 但是如果这样，原来的unique_ptr就没用了（语义上已经是无效数据，
// 在程序里可能数据还是正好正确的，但是这个数据随时会被污染，绝对不能用）。
std::unique_ptr<int> Function1(std::unique_ptr<int>&& ptr)
{
	std::unique_ptr<int> temp = std::move(ptr);
	*temp = 30;
	
	return std::move(temp);
}

int main()
{
	std::unique_ptr<int>	pInt(new int);
	*pInt = 10;
	std::cout << "*pInt = " << *pInt << std::endl;
	
	Function(pInt);
	std::cout << "After *pInt = " << *pInt << std::endl;
	
	std::unique_ptr<int> pInt2 = Function1(std::move(pInt));
	std::cout << "After *pInt2 = " << *pInt2 << std::endl;
	
	return 0;
}