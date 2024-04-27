#pragma once
#include "Random.h"

class Character {
    // Each attack can do between 15 and 25 damage
    int MinDamage{ 15 };
    int MaxDamage{ 25 };

    // Character has a 20% chance to avoid damage
    float DodgeChance{ 0.2 };

    int Health{ 100 };

    void TakeDamage(int Damage) {
        if (Random::Bool(DodgeChance)) {
            return; // Dodged!  No damage
        }
        Health -= Damage;
    }

    void Act(Character* Target) {
        Target->TakeDamage(
            Random::Int(MinDamage, MaxDamage)
        );
    }
};