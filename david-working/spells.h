#ifndef SPELLS_H
#define SPELLS_H
#include <string>
#include "enemy.h"
using namespace std;


class Spells
{
    //will the data members in private of mother class be in private or public domain of daughter class if we declare public like this
    protected:
        int a; 
        //Need items such as a staff and potions

    public:
        using Enemy::Enemy;
        int setSpell(int a);

};

#endif //SORCERER