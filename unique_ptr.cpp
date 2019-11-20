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

/// 测试引用和右值引用
void TestRefAndRRef()
{
	std::unique_ptr<int>	pInt(new int);
	*pInt = 10;
	std::cout << "*pInt = " << *pInt << std::endl;
	
	Function(pInt);
	std::cout << "After *pInt = " << *pInt << std::endl;
	
	std::unique_ptr<int> pInt2 = Function1(std::move(pInt));
	std::cout << "After *pInt2 = " << *pInt2 << std::endl;
}
////////////////////////////////////////////////////////////////

int32_t countNum = 0;
struct D
{
	int32_t n;
    D() { n = countNum; std::cout << "D::D " << ", n = " << n << "\n";  ++countNum;}
    ~D() { std::cout << "D::~D " << ", n = " << n << "\n";  }
    void bar() { std::cout << "D::bar\n";  }
};

void TestUniqueArray()
{
	std::unique_ptr<int[]> intArray(new int[10]);
	for (int32_t i = 0; i < 10; ++i)
		intArray[i] = i;
	std::cout << "The unique array is: " << std::endl;
	for (int32_t i = 0; i < 10; ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl << std::endl << std::endl;
	
	{
		std::unique_ptr<D[]> DArray(new D[4]);
	}
	std::cout << std::endl << std::endl << std::endl;
}
// 智能指针。作为一种对普通指针的扩展，拥有直接调用以及作为数组使用两种使用方式。
//////////////////////////////////////////////////////////////

int main()
{
	//TestRefAndRRef();
	TestUniqueArray();
	
	return 0;
}