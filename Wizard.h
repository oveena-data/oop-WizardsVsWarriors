#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"
#include <string>
using namespace std;

class Wizard : public Player{
    protected:
    string subclass;
    string element;
    int mana;

    int spell1_cost;
    int spell2_cost;

    public:
    Wizard(); //default constructor
    Wizard(string subclass);

    //void ability1 (Player* opponent, int cost);

    void set_subclass(string subclass);
    void set_mana(int m);

    int get_mana();
    int get_spell1_cost();
    int get_spell2_cost();

    string stamina_or_mana();
    string get_subclass();

};

// class Opponent : public subclass1 : public subclass 2 : public subclass 3

#endif