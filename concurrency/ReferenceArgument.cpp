#include <iostream>
#include <thread>

using namespace std;

struct WidgetData
{
	int32_t author;
	int32_t begin;
};

typedef int32_t WidgetID;

void UpdateDataForWidget(WidgetID w, WidgetData& data);

int main()
{
	WidgetData data = {1, 2};
	WidgetID w = 10;
	thread t(UpdateDataForWidget, w, data);
	cout << "Before" << endl;
	cout << "w = " << w << ", data.author = " << data.author
		 << ", data.begin = " << data.begin << endl; // The output is :w = 10, data.author = 1, data.begin = 2
	cout << endl;
	t.join();
	
	cout << "After" << endl;
		cout << "w = " << w << ", data.author = " << data.author
		 << ", data.begin = " << data.begin << endl <<endl; // The output is :w = 10, data.author = 1, data.begin = 2
	// Yeah, we didn't change the data!
	// Because, look at the code clearly! We passed data to the constructor of thread, not to the UpdateDataForWidget function. The constructor will copy the data, and pass the copy to UpdateDataForWidget. Of course, we can't change the data of data.
	
	// Try this.
	
	thread t1(UpdateDataForWidget, w, ref(data));
	t1.join();
	cout << "Last" << endl;
	cout << "w = " << w << ", data.author = " << data.author
		 << ", data.begin = " << data.begin << endl; // The output is :w = 10, data.author = 2, data.begin = 4. It's correct now!
	
	return 0;
}

void UpdateDataForWidget(WidgetID w, WidgetData& data)
{
	//
	for (int32_t i = 0; i < 5000; ++i)
		int32_t x = 1;
	data.author = 2;
	data.begin = 4;
}