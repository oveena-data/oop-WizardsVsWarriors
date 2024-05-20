#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "Warrior.h"
#include "Player.h"
//#include "Raider.h"
#include <string>
using namespace std;

class Assassin : public Warrior {
    public:
    int smokescreen_duration;
    int smokescreen_counter;
    int measured_cut_damage;
    int poison_stab_damage;
    int precision_strike_damage;

    Assassin();
    Assassin(string name);

    void ability1 (Player* player, int cost);
    void ability2 (Player* player, int cost);
    void ability3 (Player* player, int cost);
    void ability4 (Player* opponent, int cost);
    
    int get_smokescreenDuration();

    virtual void set_subclass_attributes();
    virtual void get_subclass_attributes();

};

#endif