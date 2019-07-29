#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	float x = 19.75;
	int* s = reinterpret_cast<int*>(&x);
	int b = 0;
	float* bf = reinterpret_cast<float*>(&b);
	
	std::istringstream("BC580000") >> std::hex >> b;
	cout << std::dec << "b value 0x‭BC580000‬ is : " << *bf << endl;
	
	return 0;
}