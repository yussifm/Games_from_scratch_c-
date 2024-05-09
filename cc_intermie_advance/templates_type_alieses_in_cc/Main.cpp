#include <iostream>

#include "Resource.h"
#include "PairThree.h"
using namespace std;


// Metaprogramming
// Creating templates is sometimes referred to as metaprogramming, 
// which means writing code that writes code.The code we create(a class template)
// is used to create even more code(classes)


// Declaring Template Parameters

template <typename T>
class Pair {
public:
	Pair(T first, T second) :
		mFirst(first), mSecond{ second } {}

	T GetFirst() const { return mFirst; }
	void SetFirst(T first) { mFirst = first; }

	T GetSecond() const { return mSecond; }
	void SetSecond(T second) { mSecond = second; }

private:
	T mFirst;
	T mSecond;
};


// Class Template Argument Deduction (CTAD)
// Multiple Parameters

// As with functions, our templates can accept as many parameters
//  as we need We separate multiple parameters with a comma ,

//Below, we expand our Pair class to accept two type name parameters,
// which we’ve called T1 and T2.We then set the data type of first to be T1, 
// whilst second will have a type of T2.This replicates the behaviour of the std::pair type :
template <typename T1, typename T2>
class PairOne {
public:
	T1 first;
	T2 second;
};

int main() {


	Pair<int> MyPair{ 42, 5 };

	std::cout << "First: " << MyPair.GetFirst()
		<< "\nSecond: " << MyPair.GetSecond();

	// Multi
	PairOne<bool, int> pairOne{true, 34};
	std::cout << "Pair values: " << pairOne.first << "\n";
	// Nested Parameters
	PairOne<int, Pair<int>> nestPair{2,MyPair};

	// Making types simple to use 
	using myComType = PairOne<bool, Pair<int>>;

	myComType comPair{ true,MyPair };

	// Default Parameters
	PairOne<int, int> A;
	A.first = 42;
	A.second = 30;

	// Template Parameters vs Class Members

	// Note that a class template parameter is not the same as a class member. 
	// In the previous examples, we’ve been saving it as a class member 
	// (which we called Value) but we don’t need to.


	// Using Template Types
	
	// When we have a class template, we should remember that the name of the 
	// template is not, by itself, the name of a type.


	// Templates and Header Files 
	Resource<int> Object{ 42 };
	Object.Log();

	// 
	PairThree<int, bool> MyPairThree{ 42, true };

	std::cout << "First: " << MyPairThree.GetFirst();
	



	return 0;
}