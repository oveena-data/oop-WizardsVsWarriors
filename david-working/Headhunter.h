#ifndef HEADHUNTER_H
#define HEADHUNTER_H

#include "Enemy.h"
#include "Raider.h"
#include <string>
using namespace std;

class Headhunter : public Raider {
    public:
    int frenzy_duration;
    int frenzy_counter;
    int slice_damage;
    int savage_strike_damage;
    int frenzy;

    Headhunter();
    Headhunter(string name);

    void ability1 (Enemy* player, int cost);
    void ability2 (Enemy* player, int cost);
    void ability3 (Enemy* player, int cost);
    
    int get_frenzyDuration();

    virtual void set_subclass_attributes();
    virtual void get_subclass_attributes();

};

#endif