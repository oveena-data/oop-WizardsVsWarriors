#include "Hulk.h"
#include "Warrior.h"
#include "Player.h"

#include <string>
using namespace std;

Hulk::Hulk(){

}

Hulk::Hulk(string name){
    this->name = name;
    this->AC = 11;
    this->health = 100;
    this->base_damage = 10;
    this->speed = 2;
    this->chance_to_hit = 2;
    this->stamina = 100;
    this->weapon = "Club";
    this->subclass = "Hulk";

    // this->stamina = 100; //stamina a meter from 0-100
    this->ability_name1 = "Hulk Smash";
    this->ability_cost = 50;
    this->stun_duration = 1; //1 round
    this->smash_damage = 25;

    this->burn_counter = 0;
    this->stun_counter = 0;
}

void Hulk::ability1 (Player* opponent, int cost) {
    if (does_it_hit(opponent) == true){
        opponent->take_damage(smash_damage);
        opponent->is_stunned(1); //sets stunned boolean to true
        this->set_stamina(stamina - cost);
        cout << this->name << " smashes down on " << opponent->get_name() << " for " << smash_damage << " damage!" << endl;
    } else {
        cout << this->name << " hulk smash missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Hulk::ability2 (Player* opponent, int cost) {

}
