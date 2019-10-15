#include <iostream>
#include <cstdint>

using namespace std;

inline uint32_t FloatToBits(float f) {
    uint32_t ui;
    memcpy(&ui, &f, sizeof(float));
    return ui;
}
inline uint32_t FloatToBits1(float f)
{
	uint32_t ui;
	ui = *reinterpret_cast<uint32_t*>(&f);
	return ui;
}

inline float BitsToFloat(uint32_t ui) {
    float f;
    memcpy(&f, &ui, sizeof(uint32_t));
	return f;
}
inline float BitsToFloat1(uint32_t ui) {
    float f;
    f = *reinterpret_cast<float*>(&ui);
	return f;
}

int main()
{
	float f = 1.0f;

	cout << "f = " << f << std::endl;
	
	cout << "FloatToBits = " << FloatToBits(f) << endl;
	cout << "FloatToBits1 = " << FloatToBits1(f) <<endl;
	cout << endl << endl;
	
	uint32_t ui = 1065353216;
	cout << "ui = " << ui << endl;
	cout << "BitsToFloat = " << BitsToFloat(ui) << endl;
	cout << "BitsToFloat1 = " << BitsToFloat1(ui) << endl;
	
	return 0;
}