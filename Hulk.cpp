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
    this->ability1_cost = 50;

    this->ability_name2 = "Hulk Slap";
    this->ability2_cost = 30;

    this->ability_name3 = "Hulk Rumble";
    this->ability3_cost = 30;

    this->stun_duration = 1; //1 round
    this->smash_damage = 25;
    this->slap_damage = 15;
    this->rumble_damage = 5;

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
    if (does_it_hit(opponent) == true){
        opponent->take_damage(slap_damage);
        //opponent->is_stunned(1); //sets stunned boolean to true
        this->set_stamina(stamina - cost);
        cout << this->name << " backhands " << opponent->get_name() << " with a hefty slap for " << slap_damage << " damage!" << endl;
    } else {
        cout << this->name << " hulk smash missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Hulk::ability3 (Player* opponent, int cost) {
    if (does_it_hit(opponent) == true){
        opponent->take_damage(rumble_damage);
        opponent->is_stunned(1); //sets stunned boolean to true
        this->set_stamina(stamina - cost);
        cout << this->name << " pounds the earth, stunning " << opponent->get_name() << " for " << rumble_damage << " damage!" << endl;
    } else {
        cout << this->name << " hulk smash missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}