

// Memory Management in C++

#include <iostream>

// By including <memory>, we gain access to the std::make_unique function
#include <memory>

class Character {
public:
	std::string Name{ "Coded" };

	~Character() {
		std::cout << "Destroy Character" << '\n';
	}
};

class CharacterTwo {
public:
	std::string Name;
	CharacterTwo(std::string Mname = "Abdul") : Name{ Mname } {
		std::cout << "Creating " << Name << '\n' << '\n';
	}

	~CharacterTwo() {
		std::cout << "Deleting " << Name<< '\n' << '\n';
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

	delete myFuncRCharacter;
	delete myRandCharacter;
	delete myCharacter;

	// Topic 4: Problems with 'new' and 'delete'
	// 
	//In complex programs, managing memory manually using new and delete can become very difficult.
	//  This is particularly true when many different components of our system
	//  rely on the same objects stored in the free store.

	/*If we do not call delete, we have a memory leak
		If we call delete on a resource that was already deleted,
		we cause memory corruption and defects(this is called a double - free error)
		If we call delete too early, a component that was still using 
		that resource will stop functioning*/


    // Topic 5: Memory ownership and Smart Pointers

	// Topic 5.1: Smart Pointers and std::unique_ptr

	//Like any pointer, a unique pointer points to an object in memory.
	// The "unique" refers to the idea that it should be the only unique
	//  pointer that points to that object.

	//	As such, we can imagine that the function or object that owns 
	// the unique pointer has exclusive ownership of the object that the pointer points at.

	// SubTopic: Creating Unique Pointers with make_unique

	auto myUniquePtr{std::make_unique<int>(42)};

	// Dereferencing Unique Pointers
	auto userOnePtr{std::make_unique<CharacterTwo>("Unique Coded")};
	auto userTwoPtr{std::make_unique<CharacterTwo>("Unique Coded Two")};

	std::cout << userTwoPtr->Name << '\n';
	std::cout << userOnePtr->Name << '\n';






	return 0;
}