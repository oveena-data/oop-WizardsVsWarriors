#include "Enemy.h"
#include "Raider.h"
#include "Oathbreaker.h"

#include "Player.h"

#include <string>
using namespace std;

Oathbreaker::Oathbreaker()
{

}

Oathbreaker::Oathbreaker(string name){
    this->name = name;
    this->AC = 0;
    this->health = 120;
    this->base_damage = 9;
    this->speed = 3;
    this->chance_to_hit = 3;
    this->cleave_damage = 20;
    this->zealous_charge_damage = 30;
    this->stamina = 100;
    this->weapon = "Greatsword";
    this->subclass = "Oathbreaker";

    this->ability_name1 = "Cleave";
    this->ability_cost = 20;
    this->ability_name2 = "Zealous Charge";
    this->ability_cost = 35;
    this->ability_name3 = "Domination";
    this->ability_cost = 40;
    this->brace_duration = 2;
    this->brace_counter = 0;
    this->domination_duration = 2;
    this->domination_counter = 0;
}

void Oathbreaker::ability1(Player* player, int cost){
    if (does_it_hit_thePlayer(player) == true){
        //player->set_burnCounter(2);
        player->take_damage(base_damage);
        //player->is_poisoned(1); //sets poisoned boolean to true
        this->set_stamina((stamina - cost));
        cout << this->name << " cleaves " << player->get_name() << " for " << (base_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Oathbreaker::ability2(Player* player, int cost){
    if (does_it_hit_thePlayer(player) == true){
        player->take_damage(base_damage);
        this->set_stamina((stamina - cost));
        cout << this->name << " charges at " << player->get_name() << " with frenzied intent for " << (base_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Oathbreaker::ability3(Player* opponent, int cost){
    this->AC = (AC + 4);
    this->speed = (speed - 2);
    this->set_stamina(stamina-cost);
    cout << this->name << " braces behind their shield and increases their defence for 2 rounds!" << endl;
}

void Oathbreaker::ability4(Player* player, int cost){
    this->AC = (AC - 2);
    this->speed = (speed - 2);
    this->set_stamina(stamina-cost);
    cout << this->name << " bellows at " << player->get_name() << " reducing their speed and defence for 2 rounds!" << endl;
}



//GETTERS
int Oathbreaker::get_braceDuration()
{
    return brace_duration;
}

int Oathbreaker::get_dominationDuration()
{
    return domination_duration;
}

void Oathbreaker::get_subclass_attributes()
{
    cout << "Cleave damage: " << cleave_damage << endl;
    cout << "Zealous Charge damage: " << zealous_charge_damage << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Subclass: " << subclass << endl;
}

//SETTERS
void Oathbreaker::set_subclass_attributes()
{
    this->cleave_damage = 20;
    this->zealous_charge_damage = 30;
    this->stamina = 100;
    this->subclass = "Oathbreaker";

}

