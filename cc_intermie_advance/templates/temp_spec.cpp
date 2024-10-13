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


int main(){
	
	cout<<"Tenplates specailization"<<endl;

	 Renderable<Monster> SomeMonster = Renderable<Monster>();
     SomeMonster.Render();


     Renderable<Tree> SomeTree = Renderable<Tree>();
     SomeTree.Render();
   
	return 0;
}