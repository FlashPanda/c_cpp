#include <iostream>
#include <thread>

using namespace std;

void Hello()
{
	cout << "Hello Concurrent World\n";
}

int main()
{
	thread t(Hello);
	int64_t sum = 0;
	for (int32_t i = 0; i < 100000; ++i)
		for (int32_t j = 0; j < 10000; ++j)
			sum += i;
	t.join();
}