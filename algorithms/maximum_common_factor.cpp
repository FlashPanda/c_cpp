// 欧几里得最大公因子算法
// 给定两个正整数m和n，求它们的最大公因子，即能够同时整除m和n的最大正整数
#include <iostream>

int MaximumCommonFactor(int m, int n)
{	
	if (m < n)
	{
		int t = m;
		m = n;
		n = t;
	}
	
	// 求余数
	int r = m % n;
	
	// 余数是否为0
	if (r == 0)
		return n;
	
	// 迭代
	m = n;
	n = r;
	
	// 返回
	return MaximumCommonFactor(m, n);
}

int main()
{
	int m = 38295;
	int n = 49233859;
	std::cout << "m = " << m << ", n = " << n << std::endl;
	
	std::cout << "maximum common factor = " << MaximumCommonFactor(m, n) << std::endl;
	
	return 0;
}