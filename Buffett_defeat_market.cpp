#include <iostream>
#include <cstdint>
#include <cmath>

// 投资股票的人都希望打牌市场（标准普尔指数）
// 假设一个人在标准普尔指数上随机行走，它有50%的可能性打败市场
// 那么，50年下来，它平均打败市场的次数是25次，标准差是3.5次
// 而Warren Edward Buffett打败了市场42次，这个数字，已经在4个
// 标准差之外。4个标准差是25 + 3.5 * 4 = 39，考虑到3.5是一个
// 四舍后的数字，所以将这个4个标准差定为40.
// 这个程序计算的是在4个标准差，也就是40之外的概率。

int64_t BinomialCoefficient(int total, int choosen);

int main()
{
	int total = 50;
	int choosen = 42;
	
	int64_t totalBinomial = 0;
	for (int i = 0; i < total - choosen + 1; ++i)
	{
		totalBinomial += BinomialCoefficient(total - i, choosen + i);
	}
	
	double possibility = totalBinomial * std::pow(0.5, 50.0);
	
	std::cout << "概率是：" << possibility << std::endl;
	
	getchar();
	return 0;
}

int64_t BinomialCoefficient(int total, int choosen)
{
	int _total = total;
	int _choosen = choosen;
	int left = total - choosen;
	
	int64_t result1 = 1;
	int64_t result2 = 1;
	for (int i = 0; i < _total - _choosen; ++i)
	{
		result1 *= _total - i;
		result2 *= left - i;
	}
	return result1 / result2;
}

// 计算结果：在4个标准差之外的几率是百万分之9.5
// 而要达到Buffett的程度，几率是千万分之4.89