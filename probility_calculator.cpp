#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	double probility = 1.0;
	
	for (int32_t i = 0; i < 13; ++i)
	{
		probility *= (36.0 - i) / (52.0 - i);
	}
	cout << probility << endl;
	
	getchar();
	return 0;
}