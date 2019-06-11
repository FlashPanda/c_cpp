#include <iostream>
#include <chrono>
#include <ctime>

long fibonacci(unsigned n)
{
	if (n < 2) return n;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	auto start = std::chrono::system_clock::now();
	std::cout << "f(42) = " << fibonacci(42) << std::endl;
	auto end = std::chrono::system_clock::now();
	
	std::chrono::duration<double> elapsedSeconds = end - start;
	std::time_t endTime = std::chrono::system_clock::to_time_t(end);
	
	std::cout << "finished computation at " << std::ctime(&endTime)
			  << "elapsed time: " << elapsedSeconds.count() << "s" << std::endl;
}