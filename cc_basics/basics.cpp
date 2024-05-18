
// C++ Syntax

/*
Basics of C++ for beginners
and advances users
 */

#include <iostream>  // Header file library - > lets work input and output objects (cin and cout)
#include <string>  // String header file

using namespace std;  //

int main() {
    // called "see-out" is an object
    // "<<" we call them insertion operator
    // endl -> returning new line
    cout << "Hello world!" << endl;
    cout << 4 + 5 << endl;
    cout << "addition " << 6.0 + 3.4 << endl;

    // Variables
    /*
    Data types

    int - store integers (wholes numbers), without decimals eg: 12, -12
    2 or 4 bytes

    double  - store floating numbers with decimals and it is 8 bytes  19.99999
     store  15 decimal digits

    float - float same as double, but is 4 bytes
    store 6 decimal digits

    char - stores single characters, eg:  'a', 'B', or char values 65 = a
    1 bytes

    string - store text eg: "Hello world"

    bool - store boolean values or true or false states.
     1 byte or 8bits
    */

    int age = 25;
    int score = 10;
    double amount = 0.0;

    double hight = 222.3;
    float width = 55.6;

    char a = 65; //A
    char b = 'b';

    string name = "Anthony";
    string firstName = "Saga";
    string lastName = "baki";

    bool canDrive = true;

    cout << "Int values : " << age << " " << score << endl;
    cout << "Double and floats values : " << hight << " " << width << endl;

    cout << "Char values : " << a << " " << b << endl;
    cout << "String values : " << name << " " << firstName << " " << lastName
         << endl;
    cout << "Boolean values : " << canDrive << endl;

    //  Declare variables
    // first type
    int x = 6, y = 10, z = 2;  // with comma-separated list
    cout << x << " " << y << " " << z << endl;

    // second type
    int w, s, f;
    w = s = f = 100;
    /*
     int w = 100;
     int s = 100;
     int f = 100;
    */
    cout << w + s + f << endl;

    // Constants
    const int AGE = 20;
    cout << AGE << endl;

    // Error here
    //  const double hightConst;
    //  hightConst = 10.6;

    // Getting User inputs from console

    double amountToPay = 0.0;
    cout << "Enter amount to pay" << endl;

    //  Cin basically allows to get User input
    //  is a predefined variable that reads data from the keyboard
    //  '>>'  is extraction operator
    // 'see-in'
    cin >> amountToPay;

    cout << "Amount to pay is : "
         << "$" << amountToPay << endl;

    // Operators in C++

    // Operators in C++ allows to perform operations on variables and values

    // Eg:
    int optAddTwo = 200 + 500;
    cout << optAddTwo << endl;  // 700

    int sum = 12 + 15;
    cout << sum << endl;  // 27

    //  Arithmetic Operators
    // Are used for basic maths operations
    /*
       + (Addition), - (Subtraction), * (Multiplication) , /, % (Modulus), ++
       (Increment operator), -- (Decrement operator)

    */
    // Eg
    sum++;        // sum += 1;
    optAddTwo--;  // optAddTwo -= 1;

    // Assignment operator
    /*
       =, +=, -=, *=, %=, /= , &= , |=, ^= (Bitwise exclusive),
        >>= (Right Shift AND assignment), <<=  (Left Shift AND assignment),

    */

    sum += 3;
    sum -= 2;

    // Comparison operators
    // used to compare two values or variables

    /*
     == (Equal to),  != (Not equal), > (Greater Than),

      < (Less Than), >= (Greater or equal to),
       <= (Less than or equal to),

    */

    // x == y
    // x != y
    //  x > y

    // Logical Operators
    /*
     && (AND),  || (OR),  ! (NOT)

    */

    return 0;
}