#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

class Warrior : public Player {
    protected:
    string subclass;
    string weapon;
    int stamina;

    public:
    Warrior(); //default constructor
    Warrior(string subclass);
    ~Warrior();

    //virtual void ability1 (Player* opponent, int cost) = 0;
    // virtual void ability1 (Player* opponent, int cost);
    // virtual void ability2 (Player* opponent, int cost);

    void set_subclass(string subclass);
    void set_stamina(int s);

    int get_stamina();
    string stamina_or_mana();
    string get_subclass();

};

#endif