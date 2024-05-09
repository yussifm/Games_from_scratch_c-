#include "PairThree.h"

// Definitions

template <typename T1, typename T2>
T1 PairThree<T1, T2>::GetFirst() const {
	return mFirst;
}

template <typename T1, typename T2>
T2 PairThree<T1, T2>::GetSecond() const {
	return mSecond;
}



template class PairThree<int, bool>;
template class PairThree<bool, bool>;
template class PairThree<float, int>;

/*
In this lesson, we've expanded on class templates, particularly focusing on how to separate 
their declarations from definitions. The key takeaways include:

Much like regular classes, class templates can be split into declarations and definitions

However, separating the declaration and definition of a class template into separate files
can lead to linker errors due to the way templates are instantiated at compile time.

A common solution to this problem is to provide the template definitions within 
the header file directly, or through an included .ipp or .tpp file to ensure
the compiler has access to them when needed.

An alternative, less commonly used method involves explicitly instantiating templates
in a source file for each required type combination, which helps in cases where the
template types are known in advance, and limited in quantity.



*/