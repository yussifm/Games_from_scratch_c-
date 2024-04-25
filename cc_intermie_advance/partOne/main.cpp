
// Pointers and references 

// the arrow operator ->
//When we’re working with pointers to our custom types, a 
// common requirement we’ll have is to dereference the pointer,
//  and then access one of its members

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
	int mhealth;

public:
	Character(Weapon& weaponProp): mWeapon(weaponProp){}

	Weapon getWeapon() { return mWeapon; }
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

	return 0;
}
