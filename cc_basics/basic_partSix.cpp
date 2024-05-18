#include <iostream>

class Enemy
{
public:
    Enemy() { std::cout << "Constructor" << std::endl; } // Constructor
    ~Enemy() { std::cout << "Destructor" << std::endl; } // Destructor

    void setHealth(int newHealth) { health = newHealth; } // Set health
    void setPosition(float newX, float newY)
    {
        posX = newX;
        posY = newY;
    } // Set position

    int getHealth() const { return health; }    // Get health
    float getPositionX() const { return posX; } // Get position
    float getPositionY() const { return posY; } // Get position

private:
    int health;
    float posX, posY;
};

void spawnEnemy()
{
    // Allocate memory for an enemy object at runtime using new keyword
    Enemy *enemy = new Enemy();

    // Now access enemy data through the pointer
    enemy->setHealth(50);
    enemy->setPosition(4.5f, 6.5f);

    // delete enemy or deallocate the memory
    std::cout << "Enemy is spawned" << std::endl;
    std::cout << enemy->getHealth() << std::endl;
    std::cout << enemy->getPositionX() << std::endl;
    std::cout << enemy->getPositionY() << std::endl;
    delete enemy;
}

class Player
{
public:
    int score;
    float posX, posY;
};

void updatePlayer(Player &player)
{
    player.score = 40;
    player.posX = 2.9f;
    player.posY = 5.3f;

    std::cout << player.score << std::endl;
    std::cout << player.posX << std::endl;
    std::cout << player.posY << std::endl;
}

int main()
{

    // Pointers and References in C++
    // Pointers
    // Symbolic representation of addresses, Store the address of variables or memory location.
    // dataType *var_name;

    int x = 10;
    int *intPtr;

    std::cout << "Value of x: " << x << std::endl;

    intPtr = &x;

    std::cout << "Address of Pointer: " << intPtr << std::endl;
    std::cout << "Value of Pointer: " << *intPtr << std::endl;

    // Pointers in game development

    // References
    // reference is like an alias for an existing variable.

    int y = 10;

    // ref
    int &yRef = y;

    // Difference between reference and Pointers
    //  nullptr;

    spawnEnemy();

    Player thePlayer;
    updatePlayer(thePlayer);
    return 0;
}