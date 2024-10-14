#include <iostream>
#include <string>
using namespace std;


class Monster{
public:
	string name;
	Monster(){
		name = "Monster";
	}

};

class Tree{
public:
	string name;
	Tree(){
		name = "Tree";
	}

};
template <typename T> 
class Renderable{
public:
	void Render();
	T object;
};

template <typename T>
void Renderable<T>::Render(){
	cout << "Rendring " << object.name <<endl;
}

// normal template 
template <typename T, typename U>
auto adder(T x, U y) {
return x + y;
}

// getting return type from template
template <typename T, typename U>
auto adderTwo(T x, U y) -> decltype(x + y) {
return x + y;
}


int main(){
	
	cout<<"Tenplates specailization"<<endl;

	 Renderable<Monster> SomeMonster = Renderable<Monster>();
     SomeMonster.Render();


     Renderable<Tree> SomeTree = Renderable<Tree>();
     SomeTree.Render();

	 auto num = adder(2, 5);
	 auto numTwo = adderTwo(4.5, 6.0);

	 cout << "Number: "<<num<<endl;
     cout << "Number Two: " << numTwo <<endl;
	return 0;
}