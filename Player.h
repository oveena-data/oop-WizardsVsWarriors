#ifndef PLAYER_H
#define PLAYER_H

//#include "Enemy.h"

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
    int mana;
    int stamina;

    string ability_name1;
    string ability_name2;
    string ability_name3;
    string ability_name4;
    int ability_cost;
    int staminaOrMana;

    int burn_counter;
    int armour_counter;
    int stun_counter;

    public:
    Player(); //default constructor sets all values to 0, name to "unnamed"
    Player(string name); //constructor that takes a name, sets all other values to 0
    virtual ~Player() = 0;

    //ATTACKS
    //virtual void ability_attack(Player* opponent) = 0; //virtual function for polymorphed ability attacks.

    bool does_it_hit(Player* opponent); //does the attack hit the player/opponent?

    void basic_attack(Player* opponent); //basic weapon attack, costs no mana/stamina
    virtual void ability1 (Player* opponent, int cost) = 0;
    virtual void ability2 (Player* opponent, int cost) = 0;
    virtual void ability3 (Player* opponent, int cost) = 0;
    //virtual void ability2 (Player* opponent, int cost) = 0;
    // virtual void ability1(Player* opponent, string name, int damage, int cost) = 0;
    // virtual void ability2(Player* opponent, string name, int damage, int cost) = 0;

    void take_damage(int damage_total); //reduces player/opponent health by given amount
    int dice_roll(); //returns a random number from 1-20

    int get_staminaOrMana();
    void set_staminaOrMana(int c);


    //enemy subclasses
    void get_subclass_attributes();
    void set_attributes(string name, int AC, int health, int base_damage, int chance_to_hit);
    void set_subclass_attributes();

    //STATUS EFFECT BOOLS
    bool is_poisoned(int flag);
    bool is_stunned(int flag);
    bool is_burning(int flag);
    bool is_buffed(int flag);
    bool is_debuffed(int flag);

    void clear_status_effects();

    //GETTERS
    string get_name();
    int get_AC();
    int get_health();
    int get_abilityCost();
    int get_mana();
    int get_stamina();

    string get_ability1();
    string get_ability2();
    string get_ability3();

    int get_burnCounter();
    int get_stunCounter();
    int get_armourCounter();

    //SETTERS
    void set_health(int health);
    void set_name(string name);
    void set_abilityCost (int cost);
    void set_AC(int c);
    void set_mana(int c);
    void set_stamina(int c);

    void set_burnCounter (int c);
    void set_stunCounter(int c);
    void set_armourCounter(int c);

};

// class Enemy {
//     protected:
//     string name;
//     int health;
//     int base_damage; //basic attack damage for physical weapons e.g. warrior weapon, wizard staff
//     int speed; //speed that determines who starts the fight
//     int chance_to_hit; //number that effects how likely an attack is to hit the opponent (dice_roll + chance_to_hit)

//     int staminaOrMana;

//     string ability_name1;
//     string ability_name2;
//     string ability_name3;
//     string ability_name4;
//     int ability_cost;

//     int burn_counter;
//     int armour_counter;
//     int stun_counter;

//     public:
//     Enemy(); //default constructor sets all values to 0, name to "unnamed"
//     Enemy(string name); //constructor that takes a name, sets all other values to 0
//     virtual ~Enemy();
//     int AC; //physical defence such as armour
//     int stamina;
//     int mana;

//     //ATTACKS
//     //virtual void ability_attack(Player* opponent) = 0; //virtual function for polymorphed ability attacks.

//     bool does_it_hit_thePlayer(Player* player); //does the attack hit the player/opponent?

//     void basic_attack(Player* player); //basic weapon attack, costs no mana/stamina
//     virtual void ability1 (Player* player, int cost) = 0;
//     virtual void ability2 (Player* player, int cost) = 0;
//     virtual void ability3 (Player* player, int cost) = 0;
    
//     //virtual void ability2 (Player* opponent, int cost) = 0;
//     // virtual void ability1(Player* opponent, string name, int damage, int cost) = 0;
//     // virtual void ability2(Player* opponent, string name, int damage, int cost) = 0;

//     void take_damage(int damage_total); //reduces player/opponent health by given amount
//     int dice_roll(); //returns a random number from 1-20

//     //STATUS EFFECT BOOLS
//     bool is_poisoned(int flag);
//     bool is_stunned(int flag);
//     bool is_burning(int flag);
//     bool is_buffed(int flag);
//     bool is_debuffed(int flag);

//     void clear_status_effects();

//     //GETTERS
//     //void printAttributes();
//     string get_name();
//     string get_ability1();
//     string get_ability2();
//     string get_ability3();
//     string get_ability4();
    
//     int get_health();
//     int get_AC();
//     int get_mana();
//     int get_stamina();
//     int get_abilityCost();

//     int get_burnCounter();
//     int get_stunCounter();
//     int get_armourCounter();

//     void print_attributes();
//     int get_staminaOrMana();
//     virtual void get_subclass_attributes();

//     //SETTERS

//     virtual void set_attributes(string name, int AC, int health, int base_damage, int chance_to_hit);
//     virtual void set_subclass_attributes();

//     void set_health(int health);
//     void set_name(string name);
//     void set_AC(int c);
//     void set_abilityCost (int cost);
//     void set_mana(int c);
//     void set_stamina(int c);

//     void set_burnCounter (int c);
//     void set_stunCounter(int c);
//     void set_armourCounter(int c);

// };

#endif