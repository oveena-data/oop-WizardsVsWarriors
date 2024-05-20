#ifndef CRYOMANCER_H
#define CRYOMANCER_H

#include "Wizard.h"
#include "Player.h"
#include <string>
using namespace std;

class Cryomancer : public Wizard {
    public:
    int ice_spike_damage;
    int arctic_storm_damage;
    int ice_nova_damage;
    int ice_armour_counter;
    int blizzard_counter;
    int ice_armour_duration;
    int blizzard_duration;

    Cryomancer();
    Cryomancer(string name);

    void ability1 (Player* player, int cost);
    void ability2 (Player* player, int cost);
    void ability3 (Player* player, int cost);
    void ability4 (Player* opponent, int cost);

    int get_ice_armour_duration();
    int get_blizzard_duration();
    
    virtual void set_subclass_attributes();
    virtual void get_subclass_attributes();
    

};

#endif