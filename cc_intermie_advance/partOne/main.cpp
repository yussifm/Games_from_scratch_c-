
// Pointers and references 

// the arrow operator ->
//When we’re working with pointers to our custom types, a 
// common requirement we’ll have is to dereference the pointer,
//  and then access one of its members


// The This Pointer
// The `this` keyword stores a pointer to the
// object that our member function was called on.
//  Use cases 
//  1: CHaining Function Calls
//  2: Identifying the caller -> allowing func to know who call them
//  3: Overloading Operators
// 



#include <iostream>
#include <string>


class Weapon {
public:
	std::string mName;
	Weapon(std::string name ): mName(name){}
};

class Character {
private:
	Weapon& mWeapon; 
	

public:
	Character(Weapon& weaponProp): mWeapon(weaponProp){}

	Weapon getWeapon() { return mWeapon; }
	int* mhealth{ nullptr }; // NUll Pointer

	//We should never attempt to dereference a nullptr using the * or -> operator.
	//  If we need to dereference a pointer, 
	// and we think it may be a nullptr, we can 
	// first check for that condition using an if statement:
};


void HandlePointers(int* pot) {
	int deRef{ *pot };

	std::cout << "Pointer value: " << pot << std::endl;
	std::cout << "Referenced value: " << &pot << std::endl;
	std::cout << "Dereferenced value: " << deRef << std::endl;

}

void increamRef(int& value) {
	value++;
}

void increamPointer(int* value) {
	(*value)++;
}


// The this keyword example
struct someType {
	void someFunc() {
		std::cout << this << std::endl;
	}
};


int main(int argc, char* argv[]) {
	 
	Weapon weaponOne("Fire Sword");
	Character playerOne(weaponOne);
	std::cout << playerOne.getWeapon().mName << std::endl;

	// References 
	Character& playeroneRef = playerOne;
	std::cout << playeroneRef.getWeapon().mName << std::endl;


	weaponOne.mName = "Water Sword";

	//Pointers 
	Character* playOnePtr = &playerOne;
	std::cout << (*playOnePtr).getWeapon().mName << std::endl; // derefercing with *
	std::cout << playOnePtr->getWeapon().mName << std::endl; // derefercing with the arrow operator

	
	std::cout << playerOne.getWeapon().mName << std::endl;

	int x{ 1 };
	std::cout << "Logging out the location of x in memory: " << &x << std::endl;

	int y{ 43 };
	increamRef(y);
	std::cout << y << std::endl;
	increamPointer(&y);
	std::cout << y << std::endl;

	HandlePointers(&y);

	if(!playerOne.mhealth){ // checking to see if pointer is null
		std::cout << "No health" << std::endl;
	}

	int health = 100;
	playerOne.mhealth = &health; // give a value to the null ptr

	if (playerOne.mhealth) {  // if it is not null
		std::cout << "Health Restored" << std::endl; 
	}

	//// The this keyword example
	someType someObject;
	someObject.someFunc();

	// same as using pointing to the memory location 
	std::cout << &someObject << std::endl;


	return 0;
}
