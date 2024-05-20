#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
//#include "Enemy.h"
#include <string>
#include <iostream>
using namespace std;

class Warrior : public Player {
    protected:
    string subclass;
    string weapon;
    int stamina;

    int ability1_cost;
    int ability2_cost;
    int ability3_cost;

    public:
    Warrior(); //default constructor
    Warrior(string subclass);
    ~Warrior();

    //virtual void ability1 (Player* opponent, int cost) = 0;

    void set_subclass(string subclass);
    void set_stamina(int s);

    int get_stamina();
    int get_ability1_cost();
    int get_ability2_cost();
    int get_ability3_cost();
    string stamina_or_mana();
    string get_subclass();

};

#endif