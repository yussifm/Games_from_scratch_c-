#include <iostream>

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

int main() {
	Pair<int> MyPair{ 42, 5 };

	std::cout << "First: " << MyPair.GetFirst()
		<< "\nSecond: " << MyPair.GetSecond();
	return 0;
}