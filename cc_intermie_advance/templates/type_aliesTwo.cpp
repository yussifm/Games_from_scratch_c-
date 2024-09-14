#include <iostream>
#include <utility>
#include <cstdint>
#include <string>
#include <math.h>
#include <type_traits>
#include <typeinfo>



struct  Player
{
    std::string name;
};

struct Enemy
{
    std::string name;
};

struct MyType {
  MyType(int, float, bool) {}
  int Get(){};
};

constexpr bool use64BitInts{true};

using Integer = std::conditional<use64BitInts, int64_t, int32_t>::type;
int main() {
    Player coded{"coded"};
    Enemy boss{"Boss"};

  std::pair<const Player&, const Enemy&> Userone {coded, boss};

  // creating Alias with using
  using pairDaType = std::pair<const Player&, const Enemy&>;

  pairDaType userTwo {coded, boss};


  // decltype 
  // Occasionally, it will be easier (or necessary) to ask the
  // compiler to figure out what type an expression returns. 
  // We can do this using the decltype specifier.

  using someType = decltype(23);

  someType someValue {23};

  // declval
   // Will be int
  using SomeType = decltype(
    std::declval<MyType>().Get()
  );

  std::cout << Userone.first.name << " == " << Userone.second.name << std::endl;
  std::cout << userTwo.first.name << " == " << userTwo.second.name << std::endl;
  std::cout << "Integer size: " << sizeof(Integer) << " bytes" << std::endl;
  std::cout << typeid(someValue).name() << std::endl;
  return 0;
}

// Type aliases help simplify verbose or complex type declarations, making code easier to understand and maintain.
//The using keyword allows for the creation of type aliases.
//Type aliases can be scoped globally or locally, following normal C++ scoping rules to control visibility.
//Project-wide type aliases enable consistent type usage across a project and can be easily changed from a single location.
//The type an alias uses can be conditionally set at compile time, using the preprocessor or std::conditional.
//The decltype specifier is useful for deducing the type of an expression.
//Although typedef is supported for backward compatibility with C and legacy C++ code, using is generally preferred for its readability and compatibility with modern C++ features.