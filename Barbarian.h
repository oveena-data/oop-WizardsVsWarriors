#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Player.h"
#include "Warrior.h"
#include <string>
using namespace std;

class Barbarian : public Warrior {
    public:
    int burn_damage;
    int burn_duration;
    //int ability_cost;

    Barbarian();
    Barbarian(string name);

    void ability1 (Enemy* opponent, int cost);
    void ability2 (Enemy* opponent, int cost);

    int get_burnDamage();
    int get_burnDuration();

};

#endif