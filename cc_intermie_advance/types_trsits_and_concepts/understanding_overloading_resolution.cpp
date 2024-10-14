#include <iostream>

using namespace std;


//Learn how the compiler decides which function 
//to call based on the arguments we provide.

 adder(int x, int y) {
	cout<<"Calling int func "<< x+y <<endl;
}


 adder(float x, float y) {
	cout<<"Calling float func "<< x+y <<endl;
}


 adder(double x, double y) {
	cout<<"Calling double func "<< x+y <<endl;
}

template <typename T, typename U>
adder(T x, U y) {
	cout<<"Calling template func "<< x+y <<endl;
}



int main(){

	adder(2,4);
	adder(4.6,4.6);
	adder(2.7f,4.0f);
	adder(2.888,4);


}