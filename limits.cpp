#include <iostream>
#include <climits>

int main()
{
	// epsilon value is almost 0.000000119209... which is 1.0 * 2^(-23)
	float t = std::numeric_limits<float>::epsilon();
	uint8_t* u = reinterpret_cast<uint8_t*>(&t);
	
	std::cout << t << std::endl;
	std::cout << std::hex << "0x" <<  +*u << " 0x" << +*(u + 1) << " 0x" << +*(u + 2) << " 0x" << +*(u + 3) << std::endl;
	std::cout << std::endl;
	
	std::cout.precision(15);
	
	uint8_t array[4] = {0};
	array[3] = 0x3F; array[2] = 0x80;
	float* f = reinterpret_cast<float*>(array);
	std::cout << "f = " << *f <<std::endl;
	
	uint8_t array1[4] = {0};
	array1[3] = 0x3F; array1[2] = 0x80; array1[0] = 0x1;
	float* f1 = reinterpret_cast<float*>(array1);
	std::cout << "f1 = " << *f1 << std::endl;
	
	uint8_t array2[4] = {0};
	array2[2] = 0x7F; array2[1] = 0xFF; array2[0] = 0xFF;
	float* f2 = reinterpret_cast<float*>(array2);
	std::cout << "f2 = " << *f2 << std::endl;
	
	uint8_t array3[4] = {0};
	array3[0] = 0x1;
	float* f3 = reinterpret_cast<float*>(array3);
	std::cout << "f3 = " << *f3 << std::endl;
	
	uint8_t array4[4] = {0};
	array4[3] = 0x7F; array4[2] = 0x80;
	float* f4 = reinterpret_cast<float*>(array4);
	std::cout << "f4 = " << *f4 << std::endl;
	
	uint8_t array5[4] = {0};
	array5[3] = 0x7F; array5[2] = 0x80; array5[0] = 0x3F;
	float* f5 = reinterpret_cast<float*>(array5);
	std::cout << "f5 = " << *f5 << std::endl;
	
	uint8_t array6[4] = {0};
	array6[3] = 0x7F; array6[2] = 0x7F; array6[1] = 0xFF; array6[0] = 0xFF;
	float* f6 = reinterpret_cast<float*>(array6);
	std::cout << "f6 = " << *f6 << std::endl;
	
	return 0;
}