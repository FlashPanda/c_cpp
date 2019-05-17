#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
T to_endian_native (T net_number)
{
	T result = 0;

	for(size_t i = 0; i < sizeof(net_number); i++) {
		result <<= CHAR_BIT;
		result += ((reinterpret_cast<uint8_t*>(&net_number))[i] & UCHAR_MAX);
	}

	return result;
}

template <typename T>
T to_endian_net(T native_number)
{
	T result = 0;

	size_t i = sizeof(native_number);
	do {
		i--;
		(reinterpret_cast<uint8_t*>(&result))[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT;
	} while (i != 0);

	return result;
}

int main()
{
	uint32_t nativeNumber = 0x01020304;
	uint32_t netNumber = 0;
	
	std::cout << "Native number in total(uint32_t): 0x" << hex << nativeNumber << std::endl;
	std::cout << "native number address and value: " << std::endl;
	uint8_t* pNative = reinterpret_cast<uint8_t*>(&nativeNumber);
	for(size_t i = 0; i < sizeof(nativeNumber); ++i)
	{
		std::cout << i << " th: ";
		std::cout << " address-0x" << hex << reinterpret_cast<uint32_t>(pNative + i);
		uint32_t bit = pNative[i];
		std::cout << " value-0x" << hex << bit << endl;
	}
	cout << endl;

	netNumber = to_endian_net(nativeNumber);
	std::cout << "Net number in total(uint32_t): 0x" << hex << netNumber << endl;
	std::cout << "Net number address and value: " << endl;
	uint8_t* pNet = reinterpret_cast<uint8_t*>(&netNumber);
	for (size_t i = 0; i < sizeof(netNumber); ++i)
	{
		std::cout << i << " th: ";
		std::cout << " address-0x" << hex << reinterpret_cast<uint32_t>(pNet + i);
		uint32_t bit = pNet[i];
		std::cout << " value-0x" << hex << bit << endl;
	}
	cout << endl;

	cout << "if i call the to endian native, it should be the same vlaue." << endl;
	uint32_t _netNumber = 0;
	_netNumber = to_endian_native(nativeNumber);
	std::cout << "Suppose to net number in total(uint32_t): 0x" << hex << _netNumber << endl;
	std::cout << "Suppose net number address and value: " << endl;
	uint8_t* _pNet = reinterpret_cast<uint8_t*>(&_netNumber);
	for (size_t i = 0; i < sizeof(_netNumber); ++i)
	{
		std::cout << i << " th: ";
		std::cout << " address-0x" << hex << reinterpret_cast<uint32_t>(_pNet + i);
		uint32_t bit = _pNet[i];
		std::cout << " value-0x" << hex << bit << endl;
	}
	cout << endl;

	
	getchar();
	return 0;
}