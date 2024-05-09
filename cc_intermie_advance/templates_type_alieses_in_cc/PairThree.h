#pragma once



template <typename T1, typename T2>
class PairThree {
public:
	PairThree(T1 first, T2 second)
		: mFirst(first), mSecond{ second } {}

	// Declarations
	T1 GetFirst() const;
	T2 GetSecond() const;

private:
	T1 mFirst;
	T2 mSecond;
};

