#include <iostream>
#include <string>

using namespace std;

void myFunc()
{
    cout << "I created my function" << endl;
}

// Declare functions
void declareFunc();

// Parameters
// void functName( data_type par1, data_type par2) {}
void myName(string name)
{
    cout << "Hello " << name << endl;
}

// Default parameters
void countryName(string country = "Ghana")
{
    cout << "Welcome to " << country << endl;
}

// Multiple parameters
void countNums(int num1, double num2)
{
    cout << "Numbers Pass " << num1 << " and " << num2 << endl;
}

// The return keyword
int adderFunc(int num1, int num2)
{
    return num1 + num2;
}

// Pass By Reference
void swapNums(int &num1, int &num2)
{
    cout << "Num1: " << num1 << " Num2: " << num2 << endl;
    int num3 = num1;
    num1 = num2;
    num2 = num3;
    cout << "Num1: " << num1 << " Num2: " << num2 << endl;
}

// Pass by Arrays to Function Parameters
void passByArrayFunc(int myArr[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << myArr[i] << endl;
    }
}

// Function OverLoading

//
void SpawnEnemy()
{
    cout << "Spawning Generic Enemy" << endl;
}
void SpawnEnemy(int posX, int posY, int posZ)
{
    cout << "Spawning Enemy with Positions: " << posX << " " << posY << " " << posZ << endl;
}
void SpawnEnemy(string typeOfEnemy)
{
    cout << "Spawning Enemy with Type of: " << typeOfEnemy << endl;
}
//
int main()
{
    // Game dev with C++ : Functions
    cout << "Welcome to functions in C++" << endl;

    // Understanding C++ Functions
    // Create a function

    // datatype  funcName (){ // code to execute}

    // Calling a function
    myFunc();
    declareFunc();

    // Calling a function multiple times
    myFunc();
    myFunc();
    myFunc();
    myFunc();

    // calling a function with a parameter
    myName("Coded");
    myName("Coded Studios");
    myName("Coded Two");

    // Calling a function with Default parameters
    countryName();
    countryName("USA");

    // calling a function with multiple parameters
    countNums(3, 5.8);

    // Return
    int result = adderFunc(5, 10);
    cout << "result: " << result << endl;

    // Calling a function with pass by reference
    int num1 = 4;
    int num2 = 10;

    swapNums(num1, num2);

    // By Array
    int arrVar[5] = {1, 2, 3, 4, 5};
    passByArrayFunc(arrVar);

    // Function Overloading
    SpawnEnemy();
    SpawnEnemy(3, 4, 5);
    SpawnEnemy("HardCore");

    return 0;
}

void declareFunc()
{
    cout << "Define functions here" << endl;
}