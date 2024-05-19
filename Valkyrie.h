#ifndef VALKYRIE_H
#define VALKYRIE_H

#include <string>
#include <iostream>
#include "Player.h"
#include "Warrior.h"

using namespace std;

class Valkyrie : public Warrior {
    public:
    int smite_damage;
    int extra_armour;
    int armour_duration;
    //int ability_cost;

    Valkyrie();
    Valkyrie(string name);

    void ability1 (Enemy* opponent, int cost);
    void ability2 (Enemy* opponent, int cost);

    int get_smiteDamage();
    int get_extraArmour();

    int get_armourDuration();
};

#endif