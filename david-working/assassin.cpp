#include "Enemy.h"
#include "Raider.h"
#include "Assassin.h"

#include <string>
using namespace std;

Assassin::Assassin()
{

}

Assassin::Assassin(string name){
    this->name = name;
    this->AC = 4;
    this->health = 70;
    this->base_damage = 12;
    this->speed = 7;
    this->chance_to_hit = 5;
    this->measured_cut_damage = 15;
    this->poison_stab_damage = 10;
    this->precision_strike_damage = 25;
    this->stamina = 120;
    this->weapon = "Poison dagger";
    this->subclass = "Assassin";

    this->ability_name1 = "Measured Cut";
    this->ability_cost = 15;
    this->ability_name2 = "Poison Stab";
    this->ability_cost = 35;
    this->ability_name3 = "Precision Strike";
    this->ability_cost = 40;
    this->ability_name4 = "Smokescreen";
    this->ability_cost = 20;
    this->smokescreen_duration = 2;
    this->smokescreen_counter = 0;
}

void Assassin::ability1(Enemy* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(base_damage);
        
        this->set_stamina((stamina - cost));
        cout << this->name << " swipes at " << player->get_name() << " with a measured cut for " << (base_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Assassin::ability2(Enemy* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(base_damage);
        //player->is_poisoned(1); //sets poisoned boolean to true
        //this->set_poisonCounter(2);
        this->set_stamina((stamina - cost));
        cout << this->name << " stabs " << player->get_name() << " with a poisoned blade for " << (base_damage) << " damage!" << endl;
        cout << player->get_name() << "is poisoned for 2 rounds!";
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Assassin::ability3(Enemy* player, int cost){
    this->chance_to_hit = (chance_to_hit + 3);
    this->set_stamina(stamina-cost);
    this->chance_to_hit = (chance_to_hit - 3);
    if (does_it_hit(player) == true){
        player->take_damage(base_damage);
        this->set_stamina((stamina - cost));
        cout << this->name << " strikes at " << player->get_name() << " with precision for " << (base_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Assassin::ability4(Enemy* opponent, int cost){
    this->AC = (AC + 2);
    this->set_stamina(stamina-cost);
    cout << this->name << " throws a smokebomb on the ground, the smoke makes them harder to hit for 2 rounds!" << endl;
}



//GETTERS
int Assassin::get_smokescreenDuration()
{
    return smokescreen_duration;
}

void Assassin::get_subclass_attributes()
{
    cout << "Measured Cut damage: " << measured_cut_damage << endl;
    cout << "Poison Stab damage: " << poison_stab_damage << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Subclass: " << subclass << endl;
}

//SETTERS
void Assassin::set_subclass_attributes()
{
    this->measured_cut_damage = 20;
    this->poison_stab_damage = 30;
    this->stamina = 100;
    this->subclass = "Assassin";

}

