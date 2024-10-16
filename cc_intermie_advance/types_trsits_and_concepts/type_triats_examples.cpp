// to use type traits we to include the header file
#include <type_traits>
#include <iostream>




// Static in Structs and classes
struct StructOneExam
{
  using type = bool;
  static const int value{44}; 
	
};


// Using Type Traits with Template
template <typename T>
void FunctionOne(T Param) {
  if (std::is_arithmetic_v<T>) {
    std::cout << Param << " is arithmetic\n";
  } else {
    std::cout << Param << " is not arithmetic\n";
  }
}


int main (){
    
    // this will be a boolean value
    StructOneExam::type boolValue;
      
     // this is going to be an int value of 42
    int num = StructOneExam::value;

    std::cout<< num <<std::endl;

    FunctionOne(42);
    FunctionOne("Hello World");


    
	return 0;
}