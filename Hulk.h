#ifndef HULK_H
#define HULK_H

#include "Player.h"
#include "Warrior.h"
#include <string>
using namespace std;

class Hulk : public Warrior {
    protected:
    // int health;
    // int base_damage; //basic attack damage for physical weapons e.g. warrior weapon, wizard staff
    // int AC; //physical defence such as armour
    // int speed; //speed that determines who starts the fight
    

    public:
    int smash_damage;
    int stun_duration;
    
    Hulk();
    Hulk(string name);

    Hulk newHulk(){
        return Hulk(this->name);
    }

    // void Hulk_Smash(Player* Opponent);
    void ability1 (Player* opponent, int cost);



};

#endif