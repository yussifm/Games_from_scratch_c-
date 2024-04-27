#pragma once
#include "Random.h"



class Character {
	int MinDamage{ 15 };
	int MaxDamage{ 25 };
	int Health{ 100 };



	void TakeDamage(int Damage) {
		Health -= Damage;
	}

	void Act(Character* Target) {
		Target->TakeDamage(Random::Int(MinDamage, MaxDamage)
		);
	}
};