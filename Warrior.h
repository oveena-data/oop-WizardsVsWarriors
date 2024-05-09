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

    void set_subclass(string subclass);
    void set_stamina(int s);

    int get_stamina();
    string get_subclass();

};

#endif