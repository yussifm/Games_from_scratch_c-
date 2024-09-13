#include <iostream>
#include <utility>

int main() {

  std::pair<int, float> MyPair;

  MyPair = {1, 2.5};

  std::cout << MyPair.first << " == " << MyPair.second << std::endl;
  return 0;
}