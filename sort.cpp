#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template <typename T>
void InsertSortingDecreasing(std::vector<T>& arr)
{
	for (int32_t i = 1; i < arr.size(); ++i)
	{
		T key = arr[i];
		int32_t j = i - 1;
		for (; j >= 0; --j)
		{
			if (key >= arr[j])
				std::swap(arr[j], arr[j + 1]);
			else 
				break;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	srand(time (0));
	std::vector<int32_t> ints;
	
	for (int32_t i = 0; i < 1000000; ++i)
	{
		ints.push_back(rand());
	}
	
	cout << "Sorting ... " << endl;
	// for (int32_t i = 0; i < ints.size(); ++i)
		// cout << ints[i] << " ";
	// cout << endl << endl;
	
	InsertSortingDecreasing(ints);
	
	cout << "Done!" << endl;
	// for (int32_t i = 0; i < ints.size(); ++i)
		// cout << ints[i] << " ";
	cout << endl << endl;
	
	return 0;
}