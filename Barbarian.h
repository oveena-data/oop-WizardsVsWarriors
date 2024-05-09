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

    Barbarian();
    Barbarian(string name);

    void poison_attack(Player* opponent);

};

#endif