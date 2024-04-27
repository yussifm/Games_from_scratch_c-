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

int main() {

	std::cout << Random::Int(1, 10) << ", " << Random::Int(1, 10) << ", " << Random::Int(1, 10) << std::endl;
	return 0;
}