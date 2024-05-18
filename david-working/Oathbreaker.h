#ifndef OATHBREAKER_H
#define OATHBREAKER_H

#include "Enemy.h"
#include "Raider.h"
#include <string>
using namespace std;

class Oathbreaker : public Raider {
    public:
    int domination_duration;
    int domination_counter;
    int brace_duration;
    int brace_counter;
    int cleave_damage;
    int zealous_charge_damage;

    Oathbreaker();
    Oathbreaker(string name);

    void ability1 (Enemy* player, int cost);
    void ability2 (Enemy* player, int cost);
    void ability3 (Enemy* opponent, int cost);
    void ability4 (Enemy* opponent, int cost);
    
    int get_dominationDuration();
    int get_braceDuration();

    virtual void set_subclass_attributes();
    virtual void get_subclass_attributes();

};

#endif