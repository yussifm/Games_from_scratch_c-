#include <iostream>
#include <utility>
#include <string>

struct  Player
{
    std::string name;
};

struct Enemy
{
    std::string name;
};


int main() {
    Player coded{"coded"};
    Enemy boss{"Boss"};

  std::pair<const Player&, const Enemy&> Userone {coded, boss};



  std::cout << Userone.first.name << " == " << Userone.second.name << std::endl;
  return 0;
}