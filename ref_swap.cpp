#include <iostream>
#include <algorithm>

using namespace std;

void TestSwap(float& a, float& b)
{
	swap(a, b);
}

class EFloat
{
public:
	EFloat(float a) : x(a) {}
	
	float x;
};

void TestSwap(EFloat& a, EFloat& b)
{
	swap(a, b);
}

int main()
{
	float a = 1.f;
	float b = 2.f;
	
	cout << "[Before] a = " << a << ", b = " << b << endl << endl;
	
	TestSwap(a, b);
	cout << "[After] a = " << a << ", b = " << b << endl << endl;
	cout << endl << endl;
	
	EFloat efa(1.f);
	EFloat efb(2.f);
	cout << "[BEFORE] efa = " << efa.x << ", efb = " << efb.x << endl << endl;
	TestSwap(efa, efb);
	cout << "[AFTER] efa = " << efa.x << ", efb = " <<efb.x << endl << endl;
	
	return 0;
}