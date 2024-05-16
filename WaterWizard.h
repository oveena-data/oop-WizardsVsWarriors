#ifndef WATERWIZARD_H
#define WATERWIZARD_H

#include "Wizard.h"
#include <string>
using namespace std;

class WaterWizard : public Wizard {
    public:
    int wave_damage;
    int heal_amount;
    int heal_duration;
    int heal_counter;
    
    //int ability_cost;

    WaterWizard();
    WaterWizard(string name);

    void ability1 (Player* opponent, int cost);
    void ability2 (Player* opponent, int cost);

    int get_waveDamage();
    int get_healAmount();
    int get_healDuration();

};

#endif