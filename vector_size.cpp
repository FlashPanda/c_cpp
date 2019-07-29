#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

struct TestStructure
{
	uint32_t x;
	uint32_t y;
	int32_t z;
	std::vector<uint32_t> u;
};

int main()
{
	TestStructure t;
	int32_t x1 = sizeof(t.x);
	int32_t x2 = sizeof(t.y);
	int32_t x3 = sizeof(t.z);
	int32_t x4 = sizeof(t.u);
	int32_t x5 = sizeof(t);
	
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "x3 = " << x3 << endl;
	cout << "x4 = " << x4 <<endl;
	cout << "x5 = " << x5 << endl;
	cout << "&t = " << (uint32_t)&t << endl;
	cout << "&t.u = " << (uint32_t)&t.u << endl;
	getchar();
	return 0;
}