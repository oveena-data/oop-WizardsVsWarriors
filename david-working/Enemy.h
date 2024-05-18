#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
using namespace std;

class Enemy {
    protected:
    string name;
    int health;
    int base_damage; //basic attack damage for physical weapons e.g. warrior weapon, wizard staff
    int AC; //physical defence such as armour
    int speed; //speed that determines who starts the fight
    int chance_to_hit; //number that effects how likely an attack is to hit the opponent (dice_roll + chance_to_hit)

    string ability_name1;
    string ability_name2;
    string ability_name3;
    string ability_name4;
    int ability_cost;

    int burn_counter;
    int armour_counter;
    int stun_counter;

    public:
    Enemy(); //default constructor sets all values to 0, name to "unnamed"
    Enemy(string name); //constructor that takes a name, sets all other values to 0
    virtual ~Enemy();

    //ATTACKS
    //virtual void ability_attack(Player* opponent) = 0; //virtual function for polymorphed ability attacks.

    bool does_it_hit(Enemy* player); //does the attack hit the player/opponent?

    void basic_attack(Enemy* player); //basic weapon attack, costs no mana/stamina
    virtual void ability1 (Enemy* player, int cost) = 0;
    virtual void ability2 (Enemy* player, int cost) = 0;
    
    //virtual void ability2 (Player* opponent, int cost) = 0;
    // virtual void ability1(Player* opponent, string name, int damage, int cost) = 0;
    // virtual void ability2(Player* opponent, string name, int damage, int cost) = 0;

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
    //void printAttributes();
    string get_name();
    string get_ability1();
    string get_ability2();
    string get_ability3();
    string get_ability4();
    int get_health();
    int get_abilityCost();
    int get_burnCounter();
    int get_stunCounter();
    void print_attributes();
    virtual void get_subclass_attributes();

    //SETTERS

    virtual void set_attributes(string name, int AC, int health, int base_damage, int chance_to_hit);
    virtual void set_subclass_attributes();
    void set_health(int health);
    void set_name(string name);
    void set_abilityCost (int cost);
    void set_burnCounter (int c);
    void set_stunCounter(int c);

};

#endif