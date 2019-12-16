#include <iostream>

using namespace std;

int32_t Pan(int32_t a);
int32_t (*pf)(int32_t a);

typedef int32_t (*pff)(int32_t a);
int32_t (*ff)(int32_t a) = Pan;

int main()
{
	Pan(10);
	pf = Pan;
	(*pf)(11);
	
	//pff = Pan;	// error
	pff pfff;
	pfff = Pan;
	(*pfff)(12);	// OK!
	
	(*ff)(13);
	
	ff(14);
	return 0;
}

int32_t Pan(int32_t a)
{
	cout << "The input a is " << a << endl;
	return a;
}