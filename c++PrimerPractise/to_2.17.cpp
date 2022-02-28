#include <iostream>
#include <string>

#pragma region Section1
void Function1_3()
{
	std::cout << "Function1_3-----------------------------" << std::endl;
	std::cout << "Hello, World" << std::endl;
	std::cout << "Function1_3-----------------------------" << std::endl << std::endl;

	return;
}

void Function1_4()
{
	std::cout << "Function1_4-----------------------------" << std::endl;
	std::cout << "Enter two numbers: " << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The mul of " << v1 << " and " << v2
		<< " is " << v1 * v2 << std::endl;
	std::cout << "Function1_4-----------------------------" << std::endl << std::endl;

	return;
}

void Function1_5()
{
	std::cout << "Function1_5-----------------------------" << std::endl;
	std::cout << "Enter two numbers: " << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The mul of " << v1 << std::endl;
	std::cout << " and " << v2 << std::endl;
	std::cout << " is " << v1 * v2 << std::endl;
	std::cout << "Function1_5-----------------------------" << std::endl << std::endl;

	return;
}

void Function1_6()
{
	std::cout << "Function1_6-----------------------------" << std::endl;
	int v1 = 0, v2 = 0;
	//std::cout << "The mul of " << v1;		// 这个合法
	//		  << " and " << v2;		// 这个不合法。需要在前面加上std::cout
	//		  << " is " << v1 * v2 << std::endl;	// 这个不合法，需要加上std::cout
	std::cout << "The mul of " << v1 << std::endl;
	std::cout << " and " << v2 << std::endl;
	std::cout << " is " << v1 * v2 << std::endl;
	std::cout << "Function1_6-----------------------------" << std::endl << std::endl;

	return;
}

void Function1_7()
{
	// 观察不正确的注释返回的错误信息。
	//int v1 = 0;  错误注释看编译错误信息

}

void Function1_8()
{
	//std::cout << "/*";	// 可行
	//std::cout << "*/";	// 可行
	//std::cout << /* "*/" */ ;	// 不可行
	//std::cout << /* "*/" /* "/*" */;	// 可行
}

void Function1_9()
{
	std::cout << "Function1_9-----------------------------" << std::endl;
	int sum = 0;
	int i = 50;
	while (i <= 100)
	{
		sum += i;

		++i;
	}
	std::cout << "The sum from 50 to 100 is " << sum << std::endl;
	std::cout << "Function1_9-----------------------------" << std::endl << std::endl;
}

void Function1_10()
{
	std::cout << "Function1_10-----------------------------" << std::endl;

	int i = 9;
	while (i > 0)
	{
		std::cout << i << " ";
		--i;
	}
	std::cout << std::endl;
	std::cout << "Function1_10-----------------------------" << std::endl << std::endl;
}

void Function1_11()
{
	std::cout << "Function1_11-----------------------------" << std::endl;
	int v1 = 0, v2 = 0;
	std::cout << "Enter two numbers: " << std::endl;
	std::cin >> v1 >> v2;
	if (v1 > v2)
	{
		int v = v1;
		v1 = v2;
		v2 = v;
	}
	std::cout << "Output integers between " << v1 << " and " << v2 << ":" << std::endl;
	int v = v1 + 1;
	while (v < v2)
	{
		std::cout << v << " ";
		++v;
	}
	std::cout << std::endl;
	std::cout << "Function1_11-----------------------------" << std::endl << std::endl;
}

void Function1_12()
{
	std::cout << "Function1_12-----------------------------" << std::endl;
	int sum = 0;
	for (int i = -100; i <= 100; ++i)
		sum += i;
	std::cout << "I suggest the sum is " << 0 << std::endl;
	std::cout << "The true sum is " << sum << std::endl;
	std::cout << "Function1_12-----------------------------" << std::endl << std::endl;
}

void Function1_13_1()
{
	int sum = 0;
	for (int i = 50; i <= 100; ++i)
		sum += i;
	std::cout << "The sum form 50 to 100 is " << sum << std::endl;
}

void Function1_13_2()
{
	for (int i = 9; i > 0; --i)
		std::cout << i << " ";
	std::cout << std::endl;
}

void Function1_13_3()
{
	int v1 = 0, v2 = 0;
	std::cout << "Enter two numbers: " << std::endl;
	std::cin >> v1 >> v2;

	if (v1 > v2)
	{
		for (int i = v1 - 1; i > v2; --i)
			std::cout << i << " ";
	}
	else if (v1 == v2)
		std::cout << "No number" << std::endl;
	else
		for (int i = v1 + 1; i < v2; ++i)
			std::cout << i << " ";
	std::cout << std::endl;
}

void Function1_14()
{
	// for循环和while循环各有什么优缺点

	/*
	* for循环适合知道两个边界的循环，while适合只知道终点的循环。
	*/
}

void Function1_16()
{
	int sum = 0;
	int n = 0;
	while (std::cin >> n)
		sum += n;

	std::cout << "the sum of all inputs is " << sum << std::endl;
}

void Function1_17()
{
	int currVal = 0, val = 0;
	if (std::cin >> currVal)
	{
		int cnt = 1;
		while (std::cin >> val)
		{
			if (val == currVal)
				++cnt;
			else {
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs "
			<< cnt << " times" << std::endl;
	}
}

void Function2_3()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;	// 4,294,967,264,这是-32的无符号版数据

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;	// 32
	std::cout << i - i2 << std::endl;	// -32
	std::cout << i - u << std::endl;	// 0
	std::cout << u - i << std::endl;	// 0
}

void TypeDetermine()
{
	std::cout << "The type of 42 is : " << typeid(42).name() << std::endl;	// int
	std::cout << "The type of 4294967295 is : " << typeid(4294967295).name() << std::endl;	// __int64
	//std::cout << "The type of 18446744073709551616 is : " << typeid(18446744073709551616).name() << std::endl;// 18446744073709551616 编译报错
	std::cout << "The type of 18446744073709551615 is : " << typeid(18446744073709551615).name() << std::endl;	// __int64

	// 8进制常量是和十进制有不同的类型确定的，下面这些代码验证了这种猜测。
	std::cout << "The type of 020 is : " << typeid(020).name() << std::endl;	// int
	std::cout << "The type of 037777777777 is : " << typeid(037777777777).name() << std::endl;	// unsigned int 这个值换成十进制是4294967295
	std::cout << "The type of 040000000000 is : " << typeid(040000000000).name() << std::endl;	// __int64 4294967296
	std::cout << "The type of 0777777777777777777777 is : " << typeid(0777777777777777777777).name() << std::endl;	// __int64 9223372036854775807
	std::cout << "The type of 01000000000000000000000 is : " << typeid(01000000000000000000000).name() << std::endl;	// unsigned __int64 9223372036854775808

	// 同样，十六进制的常量和8进制的常量是一样的，它和十进制有不同的类型确定方式。
	std::cout << "The type of 0x20 is : " << typeid(0x20).name() << std::endl;	// int
	std::cout << "The type of 0xFFFFFFFF is : " << typeid(0xFFFFFFFF).name() << std::endl; // unsigned int
	std::cout << "The type of 0x7FFFFFFFFFFFFFFF is : " << typeid(0x7FFFFFFFFFFFFFFF).name() << std::endl; // __int64
	std::cout << "The type of 0xFFFFFFFFFFFFFFFF is : " << typeid(0xFFFFFFFFFFFFFFFF).name() << std::endl; // unsigned __int64
}

#pragma endregion

#pragma region 第2章
void Function2_5()
{
	// （a）输出字面值的数据类型
	'a', L'a', "a", L"a";	// 我觉得是：char, wchar_t，string, wstring
	const char a[2] = "a";
	char const b[2] = "b";

	// 实际上是：
	std::cout << typeid('a').name() << std::endl;	// char
	std::cout << typeid(L'a').name() << std::endl;	// wchar_t
	std::cout << typeid("a").name() << std::endl;	// char const [2]
	std::cout << typeid(L"a").name() << std::endl;	// wchar const [2]
	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;
	std::cout << std::endl;

	// （b）输出这些东西的字面值
	10, 10u, 10L, 10uL, 012, 0xC;	// 我觉得是：int， unsigned int, long, unsigned long, int, int
	// 实际上是：
	std::cout << typeid(10).name() << std::endl;	// int
	std::cout << typeid(10u).name() << std::endl;	// unsigned int
	std::cout << typeid(10L).name() << std::endl;	// long
	std::cout << typeid(10uL).name() << std::endl;	// unsigned long
	std::cout << typeid(012).name() << std::endl;	// int
	std::cout << typeid(0xC).name() << std::endl << std::endl;	// int

	// (c)输出这些东西的字面值
	3.14, 3.14f, 3.14L;		// 我觉得是：double， float， long double
	std::cout << typeid(3.14).name() << std::endl;		// double
	std::cout << typeid(3.14f).name() << std::endl;		// float
	std::cout << typeid(3.14L).name() << std::endl << std::endl;	// long double

	// (d)输出这些东西的字面值
	10, 10u, 10., 10e-2;	// 我觉得是：int， unsigned int, double, double
	std::cout << typeid(10).name() << std::endl;	// int
	std::cout << typeid(10u).name() << std::endl;	// unsigned int
	std::cout << typeid(10.).name() << std::endl;	// double
	std::cout << typeid(10e-2).name() << std::endl << std::endl;	// double
}

void Function2_6()
{
	// 下面两组定义是否有区别，如果有，请叙述之
	//int month = 9, day = 7;		// 这是正常的整型数的定义
	//int month1 = 09, day1 = 07;	// 从0开始的是八进制，所以09是会出现编译错误的。
									// 错误信息是：error C2041: illegal digit '9' for base '8'
}

void Function2_7()
{
	// 下述字面值表示何种含义？它们各自的数据类型是什么？
	// (a)"Who goes with F\145rgus?\012"	// "Who goes with Fergus?(换行符）", char const [22]
	// (b)3.14e1L	// 31.4，long double类型
	// (c)1024f		// 1024.0f，float类型
	// (d)3.14L		// 3.14, double类型
	// std::cout << "Hi \x4dO\115!\n";
	std::cout << typeid("Who goes with F\145rgus?\012").name() << std::endl;	// char const [23]，我忘记最后的0了。
	std::cout << 3.14e1L << "  " << typeid(3.14e1L).name() << std::endl;	// long double类型
	//std::cout << typeid(1024f).name() << std::endl;	// 居然是编译报错，这我想错了
														// invalid literal suffix 'f'; literal operator or literal operator template 'operator ""f' not found
	std::cout << typeid(3.14L).name() << std::endl;		// long double类型
}

void Function2_8()
{
	// 请利用转移序列编写一段程序，要求先输出2M，然后转到新一行。

	std::cout << "\x32\x4d\x0a";

	// 修改程序，使其先输出2，然后输出制表符，再输出M，最后转到新的一行。

	std::cout << "\x32\t\x4d\x0a";

	// 除了16进制之外，还可以用八进制，比如\012就表示换行符。
}

void Instance2_1()
{
	long double ld = 3.1415926536;
	//int a{ ld }, b = { ld };	// 报错：error C2397: conversion from 'long double' to 'int' requires a narrowing conversion
	int c(ld), d = ld;
}

void Function2_9()
{
	// 解释下列定义的含义，对非法的定义，说明错在何处，以及如何改正。
	//std::cin >> int input_value;	// 非法定义。	error C2062: type 'int' unexpected。修改：int input_value; std::cin >> input_value;
	//int i = {3.14};	// 错误，报错是error C2397，无法信息损失地初始化。修改：int i = 3.14;
	//double salary = wage = 9999.99;	// 非法定义，error C2065: 'wage': undeclared identifier，需要这么改:double salary = 9999.99, wage = 9999.99;
	//int i = 3.14;	// 正确，i = 3；
}

std::string global_str;
int global_int;		// 这是初始化好的，值是0。
void Function2_10()
{
	int local_int;
	std::string local_str;

	std::cout << "local_str is " << (local_str.empty() ? "empty." : "not empty.") << std::endl;
	std::cout << "global_int is " << global_int << std::endl;

	std::cout << "local_str is " << (global_str.empty() ? "empty." : "not empty.") << std::endl;
	//std::cout << "localint is " << local_int << std::endl;	// 这是未定义的。而global_int是有定义的。所以，只有local variable才是未定义的。
	
}

extern int ix = 1024;	// 声明+定义
int iy;	// 定义
extern int iz;	// 声明
void Function2_11()
{
}

void Function2_12()
{
	// int double = 3.14；	// 错误，double是C++关键字
	// int _;	// 正确
	// int catch-22;	// 错误，这个-不是符合命名规范，这个-会被解释成减号。
	// int 1_or_2 = 1;	// 错误，不能用数字开头。
	// double Double = 3.14;		// 正确。
}

void Function2_15()
{
	int ival = 1.01;		// 合法
	//int& rvall = 1.01;		// 非法。1.01没有对应的变量，也就没有取“别名”的空间。
	int& rval2 = ival;		// 合法。
	//int& rval3;				// 非法。“别名”必须有目标。
}

void Function2_16()
{
	int i = 0, & r1 = i;
	double d = 0, & r2 = d;
	//r2 = 3.14159;	// 合法，它让d变成了3.14159。
	//r2 = r1;			// 合法，它让d变成了0，结合上一行代码，是从3.14159变成了0。
	//i = r2;			// 合法，将r2赋值给i
	//r1 = d;			// 合法，将d赋值给r1。
}

void Function2_17()
{
	// 执行下面的代码段将输出什么结果？
	int i, & ri = i;
	i = 5;
	ri = 10;
	std::cout << i << " " << ri << std::endl;	// 我觉得是输出：10 10。
												// 实际上的输出也是10 10

}

#pragma endregion

int main()
{
	//Function1_3();
	//Function1_4();
	//Function1_5();
	//Function1_6();
	//Function1_7();
	//Function1_8();
	//Function1_9();
	//Function1_10();
	//Function1_11();
	//Function1_12();
	//Function1_13_1();
	//Function1_13_2();
	//Function1_13_3();
	//Function1_16();
	//Function1_17();
	//Function2_3();
	//TypeDetermine();
	//Function2_5();
	//Function2_6();
	//Function2_7();
	//Function2_8();
	//Function2_10();
	Function2_17();

	return 0;
}