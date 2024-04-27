#include <iostream>

#include <chrono>

int main() {
	using namespace std::chrono;
	duration Duration1{ weeks(2) };
	duration Duration2{ hours(5) };
	duration Duration3{ milliseconds(100) };
}