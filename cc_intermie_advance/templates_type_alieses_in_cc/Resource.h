#pragma once
#include <iostream>


template <typename T>
class Resource {
public:
	T value;

	// Declaration
	void Log();
};


//Definition
template <typename T>
void Resource<T>::Log() {
	std::cout << "Logging Resources value " << value;
}


