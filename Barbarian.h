#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Player.h"
#include "Warrior.h"
#include <string>
using namespace std;

class Barbarian : public Warrior {
    public:
    int poison_damage;
    int poison_duration;
    //int ability_cost;

    Barbarian();
    Barbarian(string name);

    void ability1 (Player* opponent, int cost);

    int get_poisonDamage();
    int get_poisonDuration();

};

#endif