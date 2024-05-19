#ifndef SORCERER_H
#define SORCERER_H

#include "Enemy.h"
#include <string>
using namespace std;

class Sorcerer : public Enemy{
    protected:
    string subclass;
    string element;
    int mana;

    int spell1_cost;
    int spell2_cost;
    int spell3_cost;
    int spell4_cost;

    public:
    Sorcerer(); //default constructor
    Sorcerer(string subclass);
    ~Sorcerer();

    //void ability1 (Enemy* opponent, int cost);

    void set_subclass(string subclass);
    void set_mana(int m);

    int get_mana();
    int get_spell1_cost();
    int get_spell2_cost();
    int get_spell3_cost();
    int get_spell4_cost();

    string stamina_or_mana();
    string get_subclass();

};

// class PLayer : public subclass1 : public subclass 2 : public subclass 3

#endif