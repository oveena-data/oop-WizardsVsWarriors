#ifndef RAIDER_H
#define RAIDER_H

#include "Enemy.h"
#include <string>
#include <iostream>
using namespace std;

class Raider : public Enemy {
    protected:
    string subclass;
    string weapon;
    int stamina;

    public:
    Raider(); //default constructor
    Raider(string subclass);
    ~Raider();

    //virtual void ability1 (Raider* player, int cost) = 0;

    void set_subclass(string subclass);
    void set_stamina(int s);

    int get_stamina();
    //string stamina_or_mana();
    string get_subclass();

};

#endif