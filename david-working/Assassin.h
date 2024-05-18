#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "Enemy.h"
#include "Raider.h"
#include <string>
using namespace std;

class Assassin : public Raider {
    public:
    int smokescreen_duration;
    int smokescreen_counter;
    int measured_cut_damage;
    int poison_stab_damage;
    int precision_strike_damage;

    Assassin();
    Assassin(string name);

    void ability1 (Enemy* player, int cost);
    void ability2 (Enemy* player, int cost);
    void ability3 (Enemy* player, int cost);
    void ability4 (Enemy* opponent, int cost);
    
    int get_smokescreenDuration();

    virtual void set_subclass_attributes();
    virtual void get_subclass_attributes();

};

#endif