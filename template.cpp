#include <iostream>

using namespace std;

template <typename T, int M, int N>
struct Matrix
{
	union
	{
		T data[M * N] = { 0 };
		T m[M][N];
	};
	
};

template <typename T, int N>
T Function(const Matrix<T, N, N>& mat, int32_t i, int32_t j)
{
	Matrix<T, N - 1, N - 1> temp;
	
	return mat.m[0][0];
}

int main()
{
	Matrix<float, 3, 3> a;
	Function(a, 3, 3);
	
	cout << "This could be fine!" << endl;
	return 0;
}