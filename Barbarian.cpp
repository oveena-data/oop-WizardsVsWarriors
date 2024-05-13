#include "Player.h"
#include "Warrior.h"
#include "Barbarian.h"

#include <string>
using namespace std;

Barbarian::Barbarian(){

}

Barbarian::Barbarian(string name){
    this->name = name;
    this->AC = 13;
    this->health = 70;
    this->base_damage = 7;
    this->speed = 4;
    this->chance_to_hit = 3;
    this->stamina = 100;
    this->weapon = "Daggers";
    this->subclass = "Barbarian";

    this->ability_name1 = "Poison Jab";
    this->ability_cost = 30;
    this->poison_damage = 5;
    this->poison_duration = 2; //2 rounds
}

void Barbarian::ability1(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(base_damage + poison_damage);
        opponent->is_poisoned(1); //sets stunned boolean to true
        this->set_stamina((stamina - cost));
        cout << this->name << " jabs " << opponent->get_name() << " with a poisoned blade for " << (poison_damage+base_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

//GETTERS

int Barbarian::get_poisonDamage(){
    return poison_damage;
}
int Barbarian::get_poisonDuration(){
    return poison_duration;
}

//SETTERS