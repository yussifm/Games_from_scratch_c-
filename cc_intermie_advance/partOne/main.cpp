
// Pointers and references 

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
};


int main(int argc, char* argv[]) {
	 
	Weapon weaponOne("Fire Sword");
	Character playerOne(weaponOne);

	std::cout << playerOne.getWeapon().mName << std::endl;

	weaponOne.mName = "Water Sword";
	std::cout << playerOne.getWeapon().mName << std::endl;

	int x{ 1 };
	std::cout << "Logging out the location of x in memory: " << &x << std::endl;


	return 0;
}
