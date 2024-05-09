#include "Hulk.h"
#include "Warrior.h"
#include "Player.h"

#include <string>
using namespace std;

Hulk::Hulk(){

}

Hulk::Hulk(string name){
    this->name = name;
    this->AC = 12;
    this->health = 100;
    this->base_damage = 10;
    this->speed = 2;
    this->chance_to_hit = 2;
    this->weapon = "Club";
    this->subclass = "Hulk";

    this->stamina = 100; //stamina a meter from 0-100

    this->stun_duration = 1; //1 round
    this->smash_damage = 25;
}

void Hulk::Hulk_Smash (Player* opponent){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(smash_damage);
        opponent->is_stunned(1); //sets stunned boolean to true
        this->set_stamina((stamina - 30));
        cout << this->name << " smashes down on " << opponent->get_name() << " for " << smash_damage << " damage!" << endl;
    } else {
        cout << this->name << " hulk smash missed its target!" << endl;
    }
}
