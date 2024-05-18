#pragma once
#include <iostream>
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
	unsigned int seed{ seeder() };
	mt19937 engine{ seed };

	void PrintSeed() {
		cout << "Seed: " << seed << endl;
	}

	void Reseed(unsigned int NewSeed) {
		seed = NewSeed;
		engine.seed(NewSeed);
	}

	int Int(int min, int max) {
		uniform_int_distribution get(min, max);
		return get(engine);
	}

	bool Bool(float probability) {
		uniform_real_distribution get{ 0.0, 1.0 };
		return probability > get(engine);
	}


}
