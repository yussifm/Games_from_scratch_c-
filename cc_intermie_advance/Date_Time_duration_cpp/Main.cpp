#include <iostream>

#include <chrono>
#include <thread>

int main() {
	using namespace std::chrono;
	duration Duration1{ weeks(2) };
	duration Duration2{ hours(5) };
	duration Duration3{ milliseconds(100) };
	duration Hours{ 5h };
	duration Minutes{ 5min };
	duration Seconds{ 5s };
	duration Milliseconds{ 5ms };
	duration Microseconds{ 5us };
	duration Nanoseconds{ 5ns };

	std::cout << Duration1.count() << " Hours";

	std::cout << "Starting\n";
	std::this_thread::sleep_for(5s);
	std::cout << "Done!";

	time_point CurrentTime{
   system_clock::now()
	};


	time_point ThreeWeeksAgo{
	system_clock::now() - weeks(3)
	};
}