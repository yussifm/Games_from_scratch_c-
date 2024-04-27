#pragma once
#include <random>


// Generating a Random Number
//Generating our random numbers involves 3 steps:
//
//A seeder, that will create an initial "random" number for us
//An engine, that will use the initial seed value to efficiently
//  generate an endless supply of more random numbers
//A distributor that will convert these random numbers into the desired range,
//  such as from 15 to 25 in our combat example


namespace Random {
	using namespace std;

	random_device seeder;
	mt19937 engine{ seeder() };


	int Int(int min, int max) {
		uniform_int_distribution get(min, max);
		return get(engine);
	}



}
