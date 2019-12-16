#include <iostream>
#include <thread>

using namespace std;

class X
{
public:
	void DoSomething()
	{
		cout << "You're calling DoSomething" << endl << endl;
	}
	
	void DoSomethingWithParameters(int32_t x, int32_t y)
	{
		cout << "You're calling DoSomethingWithParameters" << endl;
		cout << "And the parameters are :";
		cout << "x = " << x << ", y = " << y <<endl << endl;
	}
};

int main()
{
	X myX;
	std::thread t(&X::DoSomething, &myX);	// Yeah, this is a right way to call member functions.
	t.join();
	
	thread t1(&X::DoSomethingWithParameters, &myX, 13, 34);
	t1.join();
	
	// void ProcessBigObject(std::unique_ptr<big_object>);
	// std::unique_ptr<big_object> p(new big_object);
	// p->prepare_data(42);
	// std::thread t(process_big_object, std::move(p));
	
	return 0;
}