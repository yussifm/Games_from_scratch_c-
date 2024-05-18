#include <iostream>
#include <string>

using namespace std;

struct Enemy {
    string name;
    int health;
    int attackDamage;
};

int main() {
    cout << "Welcome to Structs \\ Structures in Cpp" << endl;

    // Struct \ Structures in C++
    // Structures (structs) are user-defined data types in C++ used to group
    // different variables under a single name. A variable in a struct is called
    // a member of the struct struct { int member1; int variable string member2;
    // string variable
    //}

    // Creating a struct
    struct {
        int age;
        string firstName;

    } personStruct;

    // assigning a values to members of a struct
    personStruct.age = 30;
    personStruct.firstName = "Anthony";

    // Output the values of a struct
    cout << "Person Struct age: " << personStruct.age << endl;
    cout << "Person Struct firstName: " << personStruct.firstName << endl;

    // One struct in multiple variables names

    struct {
        int year;
        string color;
        double miles;
        float speed;
    } toyota, tesla, crv;

    // Toyota structure
    toyota.year = 2010;
    toyota.color = "red";
    toyota.miles = 100.54;
    toyota.speed = 200.65;

    // Tesla
    tesla.year = 2023;
    tesla.color = "black";
    tesla.miles = 1000.45;
    tesla.speed = 20003.45;

    // crv struct
    crv.year = 2000;
    crv.color = "white";
    crv.miles = 200.8;
    crv.speed = 500.4;

    //
    cout << "Tesla is have more speed of " << tesla.speed
         << " than Toyota which have a speed of " << toyota.speed << endl;

    // Named Structs
    // There are names to a struct, you can treat it as a data type.

    struct mammals {
        int age;
        string name;
    };

    mammals goat;
    goat.age = 5;
    goat.name = "messi";

    cout << "Goat Name: " << goat.name << endl;

    // struct games

    struct Character {
        string name;
        int health;
        int attackDamage;
    };

    // create an instance of the character
    Character player1;
    player1.name = "Shaibu";
    player1.health = 10;
    player1.attackDamage = 20;

    // Print out the player's information
    std::cout << "Player Name: " << player1.name << std::endl;
    std::cout << "Health: " << player1.health << std::endl;
    std::cout << "Attack Damage: " << player1.attackDamage << std::endl;

    // Structs with Arrays
    const int numEnemies = 3;

    Enemy enemies[numEnemies] = {
        {"Goblin", 10, 20},
        {"Snake", 30, 10},
        {"Dragon", 200, 40},
    };

    for (int i = 0; i < numEnemies; i++) {
        std::cout << "Enemy Name: " << enemies[i].name << std::endl;
        std::cout << "Health: " << enemies[i].health << std::endl;
        std::cout << "Attack Damage: " << enemies[i].attackDamage << std::endl;
        std::cout << std::endl;
    }

    //
    struct GameObject {
        float x, y;    // Position
        float vx, vy;  // Velocity
        int health;
    };

    struct InventoryItem {
        string name;
        string type;
        int strength;
    };

    struct WeaponData {
        string name;
        int damage;
        int range;
        int bulletAmount;
    };
}