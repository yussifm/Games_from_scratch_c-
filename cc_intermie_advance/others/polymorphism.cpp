#include <iostream>
using namespace std;

class Monster {
   public: 
         virtual void BaseFunction(){
         std::cout<< "Monster"<<std::endl;
       }
       virtual ~Monster(){}
};

class Dragon : public Monster {
     public: 
        void BaseFunction(){
         std::cout<< "Dragon"<<std::endl;
       }
};

void someFunction(Monster& m){
    m.BaseFunction();
}

void anotherFuncWithDynamic(Monster& m) {
    Dragon* d = dynamic_cast<Dragon*>(&m);
    if (d) {
        d->BaseFunction();  // Safe to call as the cast succeeded
    } else {
        std::cout << "m is not a Dragon" << std::endl;
    }
}

void functWithPtr(Monster* m) {
    Dragon* d = dynamic_cast<Dragon*>(m);

    if(d){
        d->BaseFunction(); // Safe to call as the cast succeeded
    }
    else {
         std::cout  <<"m is not a Dragon" << std::endl;
    }
}

int main(int argc, char const *argv[]){

    Monster m;
    Dragon d;

    someFunction(m);
    someFunction(d);

    anotherFuncWithDynamic(m);
    anotherFuncWithDynamic(d);

    functWithPtr(&m);
    functWithPtr(&d);
    return 0;
}


// Polymorphism is a powerful concept that allows for flexible and extensible code. By utilizing virtual functions and dynamic casting, we can write code that adapts to different object types at runtime. Key takeaways:

// Polymorphism enables code to interact with objects of derived classes through base class references or pointers
// Virtual functions are bound at runtime, allowing the most derived implementation to be called
// The override keyword helps ensure that derived classes properly override base class functions
// dynamic_cast allows for safe downcasting of polymorphic objects, enabling access to derived class members