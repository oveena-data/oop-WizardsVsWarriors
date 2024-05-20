#ifndef AIRWIZARD_H
#define AIRWIZARD_H

#include "Wizard.h"
//#include "Enemy.h"
#include <string>
using namespace std;

class AirWizard : public Wizard {
    public:
    int gust_damage;
    int extra_armour;
    int armour_duration;
    //int armour_counter;
    
    //int ability_cost;

    AirWizard();
    AirWizard(string name);

    void ability1 (Player* opponent, int cost);
    void ability2 (Player* opponent, int cost);
    void ability3 (Player* opponent, int cost);

    int get_gustDamage();
    int get_extraArmour();
    int get_armourDuration();
    // int get_armourCounter();

    // void set_armourCounter(int c);

};

#endif