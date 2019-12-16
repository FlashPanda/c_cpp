#include <iostream>
#include <thread>

using namespace std;

// I can use the function call operator of an instance of a class.
class BackgroundTask
{
public:
	void operator()() const 
	{
		cout << "Hello BackgroundTask function call operator" << endl;
	}
};

int main()
{
	BackgroundTask f;
	thread t(f); // object f defined function call operator
	t.join();
	
	thread myThread1(BackgroundTask());	// Wrong! myThread1 is just a function declearation.
	//myThread1.join();	// compile error: there must be a class/structure/union on the left of .join()
	
	thread myThread2((BackgroundTask()));	// Right! This is a thread.
	myThread2.join();
	
	thread myThread3{BackgroundTask()};	// Right! This is also a thread.
	myThread3.join();
	
	return 0;
}