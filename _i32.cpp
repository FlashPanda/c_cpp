#include <iostream>

constexpr int32_t i32 (const char* s, int32_t v)
{
	return *s? i32(s + 1, v * 256 + *s) : v;
}

constexpr int32_t operator "" _i32(const char* s, size_t)
{
	return i32(s, 0);
}

unsigned operator "" _w(const char*)
{
	return 16;
}

unsigned operator "" _w(unsigned long long)
{
	return 12;
}

enum e 
{
	kMesh = "MESH"_i32,
	kMaterial = "MATL"_i32
};

int main()
{
	int32_t m = kMesh;
	int32_t ma = kMaterial;
	
	std::cout << " m = " << m << std::endl;
	std::cout << " ma = " << ma << std::endl;
	std::cout << " 12_w = " << 12_w << std::endl; // 会输出12，如果没有那个unsigned long long的函数，会输出16
	
	return 0;
	
}