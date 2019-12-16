#include <iostream>
#include <thread>
#include <string>

using namespace std;

void f (int32_t i, string const& s);

int main()
{
	thread t(f, 3, "hello");		// Notice! It's dangerous.
	t.detach();
	
	char buffer[1024];
	sprintf(buffer, "%i", 100);
	std::thread t1(f, 3, buffer);	// Notcie! It's also dangerous.
	t.detach();
	
	thread t2(f, 3, string(buffer));	// Right! It's safe now.
	return 0;
}

void f(int32_t i, string const& s)
{
	for (int32_t j = 0; j < 100; ++j)
		;
}