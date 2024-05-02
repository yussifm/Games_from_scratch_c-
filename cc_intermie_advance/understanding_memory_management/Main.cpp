

// Memory Management in C++

#include <iostream>

class Character {
public:
	std::string Name{ "Coded" };

	~Character() {
		std::cout << "Destroy Character" << '\n';
	}
};

Character getARandomCharacter() {
	return Character{ "Yussif" };
}

Character* selectedCharacter() {
	return new Character{ "Return from Func" };
}

int main() {

	// Topic 1: Allocating Dynamic Memory with 'new'

	std::cout << new Character << '\n'; // the new returns a pointer
	std::cout << (new Character)->Name << '\n';

	int* intPtr{ new int{42} };
	std::cout << *intPtr << '\n';

	Character* myCharacter{ new Character{"Studios"} };
	std::cout << myCharacter->Name << '\n';
	
	Character* myRandCharacter{ new Character{getARandomCharacter()}}; // init with a func call
	std::cout << myRandCharacter->Name << '\n';


	// Topic 2:  Returning Memory addresses from functions

	Character* myFuncRCharacter{ selectedCharacter() };
	std::cout << myFuncRCharacter->Name << '\n';

	// Topic 3: Freeing memory using 'delete'


	return 0;
}