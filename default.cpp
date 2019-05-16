#include <iostream>

class A
{
private:
	int a;
	int b;
	
public:
	A() = default;
	A(int _a, int _b) : a(_a), b(_b) {}

	A& operator=(A&) = default;
	
	friend std::ostream& operator<<(std::ostream& out, A& t)
	{
		out << "Start output A value:" << std::endl;
		out << "A.a = " << t.a << ", A.b = " << t.b << std::endl;
		out << std::endl;
		
		return out;
	}
};

int main()
{
	A a(10, 15);
	A a1(1, 5);
	
	std::cout << "a1 Value: " << std::endl;
	std::cout << "_____________________" << std::endl;
	std::cout << a1;
	
	std::cout << std::endl;
	std::cout << "After operator = " << std::endl;
	
	a1 = a;
	
	std::cout << "a1 value: " << std::endl;
	std::cout << "_______________________" << std::endl;
	std::cout << a1;
	
	return 0;
}