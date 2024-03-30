#include <iostream>
#include <string>

using namespace std;
// Classes and OOP in C++ with Game dev

// Classes in C++ with Game
// A class is a blueprint for creating objects(instances) that encapsulate data and behaviors.
// class NameOfClass { ... }

// Data members
// They are variables within the class that store the state of objects.

// Member Functions (Method)
// These are functions within the class that operate on the objects data.

// Access Specifiers
// private, Public, and protected
// They determine the visibility of the class members.

// private -> members are accessible only within the class,
// public -> members are accessible from outside class,
// protected -> members are accessible by derived classes.

class Character
{
protected:
    int health;

public:
    Character(int initHealth) : health(initHealth) {}

    // virtual methods -> allows us to override the default implementation
    virtual void Attack() = 0; // Pure virtual function
    void TakeDamage(int damage)
    {
        health -= damage;
    }

    int GetHealth() const
    {
        return health;
    }
};

// Class with name Player
class Player : public Character
{
    //     // data members
    // private:
    //     int health;

public:
    Player(int initialHealth) : Character(initialHealth) {}

    void Attack() override
    {
        cout << "Attack Enemy" << endl;
    }
};

class Enemy : public Character
{
public:
    Enemy(int initHealth) : Character(initHealth) {}

    void Attack() override
    {
        cout << "Attack Player" << endl;
    }
};

class Person
{

    // Encapsulations
private:       // Access specifier
    string id; // Attribute (string variable)

public:          // Access specifier
    int age;     // Attributes (int variable)
    string name; // Attributes (string variable)
    // Constructor
    // is special method (functions) that is automatically called when an object/ instance of a class is created
    Person(int ageDefault, string nameDefault, string idDefault) // Constructor parameters
    {
        age = ageDefault;
        name = nameDefault;
        id = idDefault;
        cout << "Person Constructor is called" << endl;
    }

    void setId(string idStr)
    {
        id = idStr;
    }

    string getId()
    {
        return id;
    }
};

// Multiple inheritance

// Base class
class FatherClass
{
public:
    void fatherFunc()
    {
        cout << "father function" << endl;
    }
};

// Base class
class MotherClass
{
public:
    void motherFunc()
    {
        cout << "mother function" << endl;
    }
};

// Derived class (child)
class SonClass : public FatherClass
{
};

// Derived class (grandchild)
class GrandSonClass : public SonClass
{
};

// Derived class (child)
class SonTwoClass : public FatherClass, public MotherClass
{
};

// Protected Access Specifier
class Employee
{
protected:
    double salary;
};

class Programmer : public Employee
{
public:
    int bonus;
    void setSalary(double s)
    {
        salary = s;
    }

    double getSalary()
    {
        return salary;
    }
};

// Polymorphism
class Animal
{
public:
    void animalSound()
    {
        cout << "The animal makes a sound." << endl;
    };
};

class Sheep : public Animal
{
public:
    void animalSound()
    {
        cout << "The sheep says: nnbee nnbee" << endl;
    }
};
class Dog : public Animal
{
public:
    void animalSound()
    {
        cout << "The Dog says: waa waa" << endl;
    }
};

int main()
{

    cout << "Classes and OOP in C++ with Game" << endl;

    Person Anthony(12, "Johnie", "GH123456"); // create an object / instance of the Person

    // Anthony.age = 10;
    // Anthony.name = "Anthony";
    // string id = "GHc2734635563";
    // Anthony.setId(id);
    string idStr = Anthony.getId();

    cout << "Person name: " << Anthony.name << endl;
    cout << "Person age: " << Anthony.age << endl;
    cout << "Person ID: " << idStr << endl;

    // Multiple inheritance
    GrandSonClass gSon;
    SonTwoClass gTwoSon;
    gSon.fatherFunc();
    gTwoSon.fatherFunc();
    gTwoSon.motherFunc();

    //
    Programmer nayar;
    nayar.setSalary(5000);
    nayar.bonus = 1000;

    cout << "Programmer Salary: " << nayar.getSalary() << endl;
    cout << "Programmer bonus: " << nayar.bonus << endl;

    Animal genAnimal;
    Sheep mySheep;
    Dog myDog;

    genAnimal.animalSound();
    mySheep.animalSound();
    myDog.animalSound();
}