#include <iostream>
#include "Random.h"




/// <summary>
/// The ability to simulate randomness plays a surprisingly big role in creating software. 
/// In the context of graphics, for example, we often use randomness
///  to simulate natural phenomena, like wind and other random effects.

//In a role - playing game, it can be used to implement things like :
//Loot Drops
//Damage Ranges
//Dodge Chances


// This code allows 
// our Character does between 15 and 25 damage on each attack,
//  and has a 20% chance to dodge incoming damage


/// </summary>
/// <returns></returns>

int main() 

{
    Random::PrintSeed();
    using std::cout;
    // We can still get random numbers:
    cout << Random::Int(1, 100) << ", "
        << Random::Int(1, 100) << ", "
        << Random::Int(1, 100) << "\n\n";

    // But now we can create reproducible results:
    Random::Reseed(141102604);
    Random::PrintSeed();
    cout << Random::Int(1, 100) << ", "
        << Random::Int(1, 100) << ", "
        << Random::Int(1, 100) << "\n\n";

    cout << "Let's go again - ";
    Random::Reseed(141102604);
    Random::PrintSeed();
    cout << Random::Int(1, 100) << ", "
        << Random::Int(1, 100) << ", "
        << Random::Int(1, 100) << "\n\n";

    for (int i{ 0 }; i < 8; ++i) {
        if (Random::Bool(0.3)) {
            std::cout << "Dodge, ";
        }
        else {
            std::cout << "Hit, ";
        }
    }
	return 0;
}