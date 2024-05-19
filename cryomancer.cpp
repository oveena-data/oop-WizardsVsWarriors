#include "Sorcerer.h"
#include "Cryomancer.h"

#include "Player.h"
#include <string>
using namespace std;

Cryomancer::Cryomancer()
{

}

Cryomancer::Cryomancer(string name){
    this->name = name;
    this->AC = 11;
    this->health = 60;
    this->base_damage = 7;
    this->ice_spike_damage = 10;
    this->arctic_storm_damage = 20;
    this->ice_nova_damage = 20;
    this->chance_to_hit = 5;
    this->mana = 100;
    this->element = "Ice";
    this->subclass = "Cryomancer";
    this->ice_armour_duration = 3;
    this->blizzard_duration = 3;
    this->ice_armour_counter = 0;
    this->blizzard_counter = 0;

    this->ability_name1 = "Ice Spike";
    this->spell1_cost = 20;

    this->ability_name2 = "Arctic Storm";
    this->spell2_cost = 30;

    this->ability_name3 = "Ice Nova";
    this->spell3_cost = 40;
    this->AC = AC + 2;
    this->ice_armour_duration = 3;
    /*
    this->ability_name4 = "Blizzard";
    this->spell4_cost = 30;
    this->AC = AC + 3;
    this->blizzard_duration = 3;
    */

    

}

int Cryomancer::get_ice_armour_duration()
{
    return ice_armour_duration;
}

int Cryomancer::get_blizzard_duration()
{
    return blizzard_duration;
}

void Cryomancer::set_subclass_attributes()
{
    this->ice_spike_damage = 10;
    this->arctic_storm_damage = 20;
    this->ice_nova_damage = 20;
    this->mana = 100;
    this->element = "Ice";
    this->subclass = "Cryomancer";

}

void Cryomancer::get_subclass_attributes()
{
    cout << "Ice Spike damage: " << ice_spike_damage << endl;
    cout << "Arctic Storm damage: " << arctic_storm_damage << endl;
    cout << "Ice Nova damage: " << ice_nova_damage << endl;
    cout << "Mana: " << mana << endl;
    cout << "Element: " << element << endl;
    cout << "Subclass: " << subclass << endl;
}

void Cryomancer::ability1(Player* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(ice_spike_damage);
        this->set_mana((mana - spell1_cost));
        cout << this->name << " pierces " << player->get_name() << " with an ice spike for " << (ice_spike_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_mana((mana - spell1_cost));
    }
}

void Cryomancer::ability2(Player* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(arctic_storm_damage);
        this->set_mana((mana - spell2_cost));
        cout << this->name << "'s icy storm rages around " << player->get_name() << " for " << (arctic_storm_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability2() << " missed its target!" << endl;
        this->set_mana((mana - spell2_cost));
    }
}

void Cryomancer::ability3(Player* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(ice_nova_damage);
        this->set_mana((mana - spell3_cost));
        
        cout << this->name << "'s icy ring cuts through to the bones of " << player->get_name() << " for " << (ice_nova_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability3() << " missed its target!" << endl;
        this->set_mana((mana - spell3_cost));
    }
}
/*
void Cryomancer::ability4(Enemy* opponent, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(emberspit_damage);
        this->set_mana((mana - spell2_cost));
        cout << this->name << "'s fire fangs bite down on " << player->get_name() << " for " << (emberspit_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability2() << " missed its target!" << endl;
        this->set_mana((mana - spell2_cost));
    }
    this->set_mana((mana - spell4_cost));
    opponent->set_ice_armour_counter(3);

}
*/