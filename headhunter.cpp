#include "Enemy.h"
#include "Raider.h"
#include "Headhunter.h"

#include "Player.h"

#include <string>
using namespace std;

Headhunter::Headhunter()
{

}

Headhunter::Headhunter(string name){
    this->name = name;
    this->AC = 13;
    this->health = 70;
    this->base_damage = 7;
    this->speed = 4;
    this->chance_to_hit = 3;
    this->slice_damage = 10;
    this->savage_strike_damage = 20;
    this->stamina = 100;
    this->weapon = "Knives";
    this->subclass = "Headhunter";

    this->ability_name1 = "Slice";
    this->ability_cost = 20;
    this->ability_name2 = "Savage Strike";
    this->ability_cost = 30;
    this->ability_name3 = "Frenzy";
    this->ability_cost = 20;
    this->frenzy_duration = 2;
    this->frenzy_counter = 0;
}

void Headhunter::ability1(Player* player, int cost){
    if (does_it_hit(player) == true){
        //player->set_burnCounter(2);
        player->take_damage(base_damage);
        //player->is_poisoned(1); //sets poisoned boolean to true
        this->set_stamina((stamina - cost));
        cout << this->name << " slices " << player->get_name() << " with a rusty blade for " << (base_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Headhunter::ability2(Player* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(base_damage);
        this->set_stamina((stamina - cost));
        cout << this->name << " deals savage blows to " << player->get_name() << " with evil blades for " << (base_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Headhunter::ability3(Player* opponent, int cost){
    this->base_damage = (base_damage + 4);
    this->set_stamina(stamina-cost);
    cout << this->name << "'s blood boils in their veins and gains 4 extra damage for the next 2 rounds!" << endl;
}



//GETTERS
int Headhunter::get_frenzyDuration()
{
    return frenzy_duration;
}

void Headhunter::get_subclass_attributes()
{
    cout << "Slice damage: " << slice_damage << endl;
    cout << "Savage Strike damage: " << savage_strike_damage << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Subclass: " << subclass << endl;
}

//SETTERS
void Headhunter::set_subclass_attributes()
{
    this->slice_damage = 10;
    this->savage_strike_damage = 20;
    this->stamina = 100;
    this->subclass = "Headhunter";

}

