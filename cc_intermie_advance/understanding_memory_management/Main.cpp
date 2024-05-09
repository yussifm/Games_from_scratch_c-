

// Memory Management in C++

#include <iostream>
#include <string>

// By including <memory>, we gain access to the std::make_unique function
#include <memory>
#include <format>

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
		std::cout << std::format("") << "Deleting " << Name << '\n' << '\n';
	}
};class CharacterThree {
public:
	virtual ~CharacterThree() = default;
};

class Monster : public CharacterThree {};

void Downcast(std::shared_ptr<CharacterThree> Attacker) {
	auto MonsterPtr{
	  std::dynamic_pointer_cast<Monster>(Attacker)
	};
	if (MonsterPtr) {
		std::cout
			<< "Cast Succeeded: It's a monster!\n";
	}
	else {
		std::cout
			<< "Cast Failed: It's not a monster!\n";
	}
}

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


void takeOwnerShipTwo(std::shared_ptr<int> num) {
	std::cout << *num << '\n';
}

void LogName(std::unique_ptr<CharacterTwo> C) {
	std::cout << C->Name << '\n';
}
void LogNameTwo(const Character* C) {
	std::cout << C->Name << '\n';
}

struct Resource {
	~Resource() { std::cout << "\nDeallocating"; }
};


int main() {

	// Topic 1: Allocating Dynamic Memory with 'new'

	std::cout << new Character << '\n'; // the new returns a pointer
	std::cout << (new Character)->Name << '\n';

	int* intPtr{ new int{42} };
	std::cout << *intPtr << '\n';

	Character* myCharacter{ new Character{"Studios"} };
	std::cout << myCharacter->Name << '\n';

	Character* myRandCharacter{ new Character{getARandomCharacter()} }; // init with a func call
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

	auto myUniquePtr{ std::make_unique<int>(42) };

	// Dereferencing Unique Pointers
	auto userOnePtr{ std::make_unique<CharacterTwo>("Unique Coded") };
	auto userTwoPtr{ std::make_unique<CharacterTwo>("Unique Coded Two") };

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

	auto SmartPointer{ std::make_unique<Character>() };

	Character* RawPointer{ SmartPointer.release() };

	// This will be a null pointer
	std::cout << "Smart: " << SmartPointer.get() << '\n';

	std::cout << "Raw: " << RawPointer << '\n';
	delete RawPointer;



	// Updating Smart Pointers with reset()

	/*
	The reset() function will also release ownership of the
	underlying resource, but will also delete it.
	After calling reset(), the get() function will return a nullptr:
	*/

	auto AbdulUniqPtr{ std::make_unique<CharacterTwo>() };

	AbdulUniqPtr.reset();

	// nullptr
	std::cout << AbdulUniqPtr.get() << '\n';


	// Swapping Unique Pointers
	//  we have swap(), which accepts another smart pointer as an argument,
	//  and swaps the object being managed between the two pointers

	auto Pointer1{ std::make_unique<Character>("Coded") };
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

	//Unlike std::unique_ptr, std::shared_ptr allows multiple pointers to share ownership
	//  of a single resource. The resource is only deallocated when the last std::shared_ptr
	//  pointing to it is destroyed or reset.

	//This shared ownership is managed through reference counting - an internal mechanism
	//  that keeps track of how many std::shared_ptr instances are managing the same resource.
	// This comes at a performance cost, so in general, std::unique_ptr, 
	// should be our default choice of smart pointer.

	auto shCharactOne{ std::make_shared<CharacterTwo>("Shared Character") };

	// Using Share pointers
	std::cout << (*shCharactOne).Name << '\n';
	std::cout << shCharactOne->Name << '\n';

	// Accessing raw Pointer using get()

	auto shPtr{ std::make_shared<Character>() };
	LogNameTwo(shPtr.get());

	// Transferring Ownership using std::move

	auto intShPtr{ std::make_shared<int>(87) };
	auto intShPtrTwo{ std::make_shared<int>(27) };

	takeOwnerShipTwo(std::move(intShPtr));

	// Swappping Ownership -> same as unique pointer
	intShPtr.swap(intShPtrTwo);
	// 
	// Resetting OWnership -> same as unique pointer
	// Unlike the unique pointer variation, the shared pointer’s reset() 
	// method may not cause the object to be deleted.

	//intShPtr.reset();

	//The reset() method can also be used to replace the managed object
	//  with a new one of the same type(or convertible to the same type):
	intShPtr.reset(new int(65));


	// Sharing OwnerShip

	auto cpyShPtr{ std::make_shared<int>(29) };

	auto cpyShPtrTwo{ cpyShPtr };

	auto cpyShPtrThree{ cpyShPtr };

	// Getting the Owner Count using use_count()

	auto cpyShPtrFour{ cpyShPtrTwo };
	std::cout << "Owner count: " << cpyShPtr.use_count() << '\n';
	cpyShPtrTwo.reset();
	std::cout << "Owner count: " << cpyShPtr.use_count() << '\n';
	cpyShPtrThree.reset();
	std::cout << "Owner count: " << cpyShPtr.use_count() << '\n';
	cpyShPtrFour.reset();
	std::cout << "Owner count: " << cpyShPtr.use_count() << '\n';
	cpyShPtr.reset();
	std::cout << "Owner count: " << cpyShPtr.use_count() << '\n';

	// Shared Pointer Casting 
	// Just like raw pointers can be cast to other types with dynamic_cast
	//  and static_cast, so too can shared pointers.

	// The only difference is, for shared pointers, we instead use std::dynamic_pointer_cast 
	// and std::static_pointer_cast. Rather than returning raw pointers,
	//  these functions return std::shared_ptr instances.

	// If std::dynamic_pointer_cast fails, it returns an "empty" 
	// shared pointer - that is, one that is not managing any underlying object.

	//	Such a pointer evaluates to false when converted to a boolean 
	// therefore code using std::dynamic_pointer_cast looks very similar to code using dynamic_cast:


	 // A character pointer pointing at a monster
	std::shared_ptr<CharacterThree> CharacterPtrA{ std::make_shared<Monster>() };
	Downcast(CharacterPtrA);

	// A character pointer pointing at a character
	std::shared_ptr<CharacterThree> CharacterPtrB{ std::make_shared<CharacterThree>() };
	Downcast(CharacterPtrB);


	// Owning and Pointing At Different Objects
	// Shared pointers have an interesting feature where the object they are sharing ownership
	//  over does not necessarily need to be the same object they are pointing at.

	// This is enabled through an alternative std::shared_ptr constructor, 
	// sometimes referred to as the aliasing constructor, that accepts two arguments:

	//The object to own, in the form of a std::shared_ptr to copy
	//	The object to point at, in the form of a memory address


	auto One{ std::make_shared<int>(1) };
	int Two{ 2 };
	std::shared_ptr<int> Alias{ One, &Two };

	std::cout << "Number Pointed At: " << *Alias << '\n';


	auto UserThree{ std::make_shared<CharacterTwo>() };
	std::shared_ptr<std::string> Name{ UserThree, &UserThree->Name };

	std::cout << "Name: " << *Name;
	std::cout << "\nOwners: "
		<< Name.use_count() << '\n';



	// Topic: Weak Pointers with std::weak_ptr

	// Weak pointers work closely with shared pointers, with one key difference:
	//  they do not actively participate in the ownership and lifecycle management
	//  of the objects they point to.

	//This means they have a view of the resource but do not affect its lifespan.
	// The life of the resource is governed solely by its shared pointer owners.

	//If all shared pointers to an object are destroyed, the object is deallocated,
	//and the weak pointer becomes expired - a reference to something that no longer exists.


	//  Creating Weak POinters
	// Commonly, weak pointers are initialized from a shared pointer:

	auto sharPtr{ std::make_shared<int>(32) };

	std::weak_ptr<int> wptr{sharPtr};

	//use_count() and expired() Methods

	auto SharedPtr{ std::make_shared<Resource>() };
	std::weak_ptr WeakPtr{ SharedPtr };

	std::cout << "Use count: " <<WeakPtr.use_count() << '\n';

	if (!WeakPtr.expired()) {
		std::cout << "The pointer hasn't expired" << '\n';
	}

	SharedPtr.reset();

	std::cout << "\nUse count: " <<	WeakPtr.use_count() << '\n';
	if (WeakPtr.expired()) {
		std::cout << "\nBut now it has" << '\n';
	}

	// Accessing Objects through a Weak Pointer

	auto exmShPtr{ std::make_shared<int>(65) };
	std::weak_ptr myWptr{ exmShPtr };

	std::shared_ptr LockedPtr{ myWptr.lock() };
	std::cout << "The number is: " << *LockedPtr << '\n';

	return 0;
}