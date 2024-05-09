#ifndef PLAYER_H
#define PLAYER_H

#include "Ability.h"
#include <string>
#include <iostream>
using namespace std;

class Player {
    protected:
    string name;
    int health;
    int base_damage; //basic attack damage for physical weapons e.g. warrior weapon, wizard staff
    int AC; //physical defence such as armour
    int speed; //speed that determines who starts the fight
    int chance_to_hit; //number that effects how likely an attack is to hit the opponent (dice_roll + chance_to_hit)

    public:
    Player(); //default constructor sets all values to 0, name to "unnamed"
    Player(string name); //constructor that takes a name, sets all other values to 0

    //ATTACKS
    //virtual void ability_attack(Player* opponent) = 0; //virtual function for polymorphed ability attacks.

    bool does_it_hit(Player* opponent); //does the attack hit the player/opponent?

    void basic_attack(Player* opponent, int base_damage); //basic weapon attack, costs no mana/stamina
    void take_damage(int damage_total); //reduces player/opponent health by given amount
    int dice_roll(); //returns a random number from 1-20

    //STATUS EFFECT BOOLS
    bool is_poisoned(int flag);
    bool is_stunned(int flag);
    bool is_burning(int flag);
    bool is_buffed(int flag);
    bool is_debuffed(int flag);

    void clear_status_effects();

    //GETTERS
    string get_name();
    int get_health();
    //SETTERS
    void set_health(int health);
    void set_name(string name);

};

#endif