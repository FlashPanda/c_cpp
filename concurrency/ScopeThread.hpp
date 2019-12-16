#include <iostream>
#include <thread>

using namespace std;

class ScopedThread
{
public:
	explicit ScopedThread(thread&& t) : t(t) {
		if (!t.joinable())
			throw logic_error("No thread");
	}
	~ScopedThread()
	{
		t.join();
	}
	
	ScopedThread(ScopedThread const &) = delete;
	ScopedThread& operator=(ScopedThread const &) = delete;

private:
	thread t;
};