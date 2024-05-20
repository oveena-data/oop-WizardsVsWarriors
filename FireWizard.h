#ifndef FIREWIZARD_H
#define FIREWIZARD_H

#include "Wizard.h"
#include <string>
using namespace std;

class FireWizard : public Wizard {
    public:
    int fireball_damage;
    int emberspit_damage;
    int burn_damage;
    int burn_duration;
    
    //int ability_cost;

    FireWizard();
    FireWizard(string name);

    void ability1 (Player* opponent, int cost);
    void ability2 (Player* opponent, int cost);
    void ability3 (Player* opponent, int cost);

    int get_burnDamage();
    int get_burnDuration();

};

#endif