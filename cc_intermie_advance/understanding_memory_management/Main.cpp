

// Memory Management in C++

#include <iostream>
#include <string>

// By including <memory>, we gain access to the std::make_unique function
#include <memory>

// Transferring ownership with std::move()
#include <utility>

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

void someRandFunc(int* num) {
	std::cout << *num << '\n';
}
void takeOwnerShip(std::unique_ptr<int> num) {
	std::cout << *num << '\n';
}

void LogName(std::unique_ptr<CharacterTwo> C) {
	std::cout << C->Name << '\n';
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

	// Copying Unique Pointers 

	/*
	Given the design intent of unique pointers,
	it doesn’t make sense to copy them.As a result, the unique_ptr
    class takes some steps to prevent this.For example,
	the copy constructor has been deleted.

	Passing by values is also a form of copying, so it is also
	prevented.

	Of course, there are countless situations where we need to pass a pointer 
	to a function. For those scenarios, smart pointers implement the get() function,
	which returns the underlying raw pointer.This allows other parts of our code to 
	access our objects, without creating copies of our unique pointers:
	*/

	auto intUniqPtr{ std::make_unique<int>(32) };
	someRandFunc(intUniqPtr.get());




	// Transferring Ownership of Unique Pointers

	takeOwnerShip(std::move(intUniqPtr));
	LogName(std::move(userOnePtr));


	// Releasing Unique Pointers 

	/// <summary>
	/// A unique pointer can release ownership over a resource using the release() method.
	/// The release() method will not delete the underlying resource.Instead,
	///  it will return the raw pointer, which lets us decide what to do with it.
	/// After calling release(), the smart pointer’s get() function will return a nullptr:
	/// </summary>

	auto SmartPointer{std::make_unique<Character>()};

	Character* RawPointer{ SmartPointer.release()};

	// This will be a null pointer
	std::cout << "Smart: "<< SmartPointer.get() << '\n';

	std::cout << "Raw: " << RawPointer << '\n';
	delete RawPointer;

	

	// Updating Smart Pointers with reset()

	/*
	The reset() function will also release ownership of the 
	underlying resource, but will also delete it.
	After calling reset(), the get() function will return a nullptr:
	*/

	auto AbdulUniqPtr{std::make_unique<CharacterTwo>()};

	AbdulUniqPtr.reset();

	// nullptr
	std::cout << AbdulUniqPtr.get() << '\n';


	// Swapping Unique Pointers
	//  we have swap(), which accepts another smart pointer as an argument,
	//  and swaps the object being managed between the two pointers

	auto Pointer1{std::make_unique<Character>("Coded") };
	auto Pointer2{ std::make_unique<Character>("Studios") };

	std::cout << "1: " << Pointer1->Name << '\n';
	std::cout << "2: " << Pointer2->Name << '\n';

	Pointer1.swap(Pointer2);

	std::cout << "1: " << Pointer1->Name << '\n';
	std::cout << "2: " << Pointer2->Name << '\n';


	//Const Unique Pointers
	// 1: Non-const pointer to non-const 

	auto Pointer{ std::make_unique<int>(42) };

	// Modify the underlying object
	(*Pointer)++;

	// Modify the pointer
	Pointer.reset();

	// 2: Const Pointer to non-const

	const auto cstPtr{ std::make_unique<int>(29) };

	(*cstPtr)++;
	/*
	cstPtr.reset(); // Error
	*/

	// 3: Non const pointer to const

	auto PtrCst{ std::make_unique<const int>(24) };
	// (*cstPtrCst)++;  // Error

	PtrCst.reset();

	//4: const pointer to const

	const auto cstPtrToCst{ std::make_unique<const int>(100) };
	// Can't modify anything

	

	// SubTopic: Shared Pointers using std::shared_ptr







	return 0;
}