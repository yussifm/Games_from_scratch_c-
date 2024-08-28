#include <array>
#include <iostream>
#include <vector>



// Compile time constants using constexpr
  constexpr int GetCompileTimeResult(
  int x, int y
){ return x + y; }


int main(int argc, char const *argv[]) {

  /*
  The C++ standard library’s version of a dynamic, resizable array is
  available as a std::vector after including the <vector> header.
  Below, we create a vector containing 5 elements - the integers from 1 to 5.
  Here's a list of common C++ vector functions with brief explanations:

  1. push_back(value)
     Adds an element to the end of the vector.

  2. pop_back()
     Removes the last element from the vector.

  3. size()
     Returns the number of elements in the vector.

  4. empty()
     Checks if the vector is empty, returns true if it is.

  5. clear()
     Removes all elements from the vector.

  6. resize(new_size)
     Changes the size of the vector, can increase or decrease.

  7. capacity()
     Returns the current capacity of the vector (allocated memory).

  8. reserve(new_capacity)
     Requests a change in capacity, useful for optimizing performance.

  9. front()
     Returns a reference to the first element.

  10. back()
      Returns a reference to the last element.

  11. at(index)
      Returns a reference to the element at the specified index with bounds
  checking.

  12. operator[]
      Accesses elements directly, no bounds checking.

  13. begin()
      Returns an iterator pointing to the first element.

  14. end()
      Returns an iterator pointing to one past the last element.

  15. insert(position, value)
      Inserts an element at the specified position.

  16. erase(position)
      Removes the element at the specified position.

  17. emplace_back(args...)
      Constructs an element in-place at the end of the vector.

  18. emplace(position, args...)
      Constructs an element in-place at the specified position.

  19. swap(other_vector)
      Swaps the contents of two vectors.

  20. assign(count, value)
      Assigns new contents to the vector, replacing current ones.


  */

  std::vector<int> myvec{1, 2, 3, 4};

  std::vector<double> myvecTwo{1.2, 4.5, 23.6};

  std::cout << myvec[0] << std::endl;
  std::cout << myvec.back() << std::endl;

  myvec[0] = 100;

  std::cout << myvec.front() << std::endl;
  std::cout << myvecTwo[0] << std::endl;
  std::cout << "Capacity: " << myvecTwo.capacity() << std::endl;
  std::cout << myvecTwo[1] << std::endl;


// Compile time constants using constexpr
std::cout << "Compile time constants using constexpr: " << GetCompileTimeResult(1, 2) << std::endl;

  return 0;
}