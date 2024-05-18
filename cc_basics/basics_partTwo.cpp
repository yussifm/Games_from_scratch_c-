#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main(){

    cout<< "Welcome to part Two of basics Cpp"<< endl;

    // C++ Strings 
    
    // String Concatenation 
    string firstName =  "Basit"; 
    string  secondName = "Junior"; 

    string playerName = "Awudu"; 
    string opponentName = "Sharif";

    string fullName = firstName + " " + secondName;
    string currentPlayers = playerName + " " + opponentName;

    

     

    cout << "Player One: "<< playerName << endl;
    cout << "Player Two: "<< opponentName << endl;
    cout << "Current players: " << currentPlayers<< endl;
    cout << fullName << endl;


    // String  Length / size 

    cout << "The length of full name :"<< fullName.length() << endl;
    cout << "The size of current Players :"<< currentPlayers.size() << endl;
 
   // Accessing Strings  in C++ 
   // You can access the characters in a string by
   // referring to its index number inside square brackets []
   // Behind the scenes strings an array characters 

  cout << "The first char of Full Name : " << fullName[0] << endl;
  cout << "The Full Name : " << fullName << endl;
  fullName[0] = 'm'; 
  cout << "The first char of Full Name : " << fullName[0] << endl;
  cout << "The Full Name : " << fullName << endl;


  // Special Characters 
  // \'  - allows include a single quote
  // \"  - allows include a double quote
  // \\  - allows include a backslash
  // \n  - newline  
  // \t  - insert tab 
  string story = "Am quoting from Steve Jobs \"Everyone should learn how to code, because it teaches you how to think\" \nbest quote";
  cout << story << endl;

 // Getting Strings from User
//  cout << "Enter First Name: " <<endl;
//  cin >> firstName;

 cout << "The Full Name : " << firstName << endl;

 // getline 
 // Allows read multiple lines (including spaces and tabs) from cin 
 // Highly recommended for strings inputs 
  cout << "Enter Second Name: " <<endl;
//   getline(cin, secondName);
 cout << "The Second  Name : " << secondName << endl;


 // Namespaces in Strings 
 std::string someone = "anyone";
// Example of namespace compared with python 
//  import connection from "mysql"  ==  std::string
//  import * from "mysql" == using namespace std;




// Basics Maths in C++
// Using the cmath Header file 
// provider standard or basic maths functions 

// int - store integers (wholes numbers), without decimals eg: 12, -12
    // 2 or 4 bytes

    // double  - store floating numbers with decimals and it is 8 bytes  19.99999
    //  store  15 decimal digits

    // float - float same as double, but is 4 bytes
    // store 6 decimal digits

    // abs() - absolute value of any number parameter passed : Eg. abs(2.3545)
    // acos(), asin(), 
    // pow(x, y) - Returns the value of x to the power of y
    // sin(0), tan(0), and so forth

double value = 2.0;
double squareRootValue = sqrt(value);  // return square root of any number type
cout <<"The square root of " << value << " is "<<squareRootValue <<endl; 

float x1 = 1.0; 
float y1 = 2.0; 
float x2 = 4.0; 
float y2 = 6.0;

float distance = sqrt(pow(x2 -x1, 2) + pow(y2 -y1, 2));

cout << "The distance between points x1 , y1 and points x2 , y2 is : "  << distance << endl;












}