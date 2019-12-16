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
	t.join();
}