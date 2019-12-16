#include <iostream>
#include <thread>

using namespace std;

void SomeFunction()
{
}

void SomeOtherFunction()
{
}

thread f()
{
	return thread(SomeFunction);
}

thread g()
{
	thread t(SomeOtherFunction);
	return t;
}

void h(thread t)
{
}

void i()
{
	h(thread(SomeFunction));
	
	thread t(SomeFunction);
	h(std::move(t));
}

void j(thread&& t)
{
}

void k()
{
	j (thread(SomeOtherFunction));
	
	thread t(SomeOtherFunction);
	j (std::move(t));
}

int main()
{
	thread t1(SomeFunction);
	thread t2 = std::move(t1);		// Legal! We can move the ownership to another thread object.
	t1 = thread(SomeOtherFunction);
	
	thread t3;
	t3 = std::move(t2);
	t1 = std::move(t3); // std::terminate() is called to terminate the program.
	
	return 0;
}