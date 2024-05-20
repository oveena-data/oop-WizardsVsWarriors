#ifndef CULTIST_H
#define CULTIST_H

#include "Sorcerer.h"
#include <string>
using namespace std;

class Cultist : public Sorcerer {
    public:
    int demonic_flame_damage;
    int inferno_damage;
    int cinder_damage;
    int burn_counter;
    int burn_duration;

    Cultist();
    Cultist(string name);

    void ability1 (Player* player, int cost);
    void ability2 (Player* player, int cost);
    void ability3 (Player* player, int cost);
    //void ability4 (Player* opponent, int cost);

    //int set_burn_duration();
    int get_burn_duration();
    
    virtual void set_subclass_attributes();
    virtual void get_subclass_attributes();
    

};

#endif