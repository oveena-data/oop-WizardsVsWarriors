#include "Sorcerer.h"
#include "Cultist.h"
#include <string>
using namespace std;

Cultist::Cultist()
{

}

Cultist::Cultist(string name){
    this->name = name;
    this->AC = 8;
    this->health = 50;
    this->base_damage = 7;
    this->demonic_flame_damage = 20;
    this->inferno_damage = 30;
    this->cinder_damage = 20;
    this->chance_to_hit = 5;
    this->mana = 100;
    this->element = "Fire";
    this->subclass = "Cultist";
    this->burn_duration = 3;
    this->burn_counter = 0;

    this->ability_name1 = "Demonic Flame";
    this->spell1_cost = 20;

    this->ability_name2 = "Inferno";
    this->spell2_cost = 30;

    this->ability_name3 = "Cinder";
    this->spell3_cost = 30;
    this->burn_duration = 3;
    /*
    this->ability_name4 = "Blizzard";
    this->spell4_cost = 30;
    this->AC = AC + 3;
    this->blizzard_duration = 3;
    */

    

}

int Cultist::get_burn_duration()
{
    return burn_duration;
}


void Cultist::set_subclass_attributes()
{
    this->demonic_flame_damage = 20;
    this->inferno_damage = 30;
    this->cinder_damage = 20;
    this->mana = 100;
    this->element = "Fire";
    this->subclass = "Cultist";

}

void Cultist::get_subclass_attributes()
{
    cout << "Demonic Flame damage: " << demonic_flame_damage << endl;
    cout << "Inferno damage: " << inferno_damage << endl;
    cout << "Cinder damage: " << cinder_damage << endl;
    cout << "Mana: " << mana << endl;
    cout << "Element: " << element << endl;
    cout << "Subclass: " << subclass << endl;
}

void Cultist::ability1(Enemy* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(demonic_flame_damage);
        this->set_mana((mana - spell1_cost));
        cout << this->name << " blasts " << player->get_name() << " with a demonic flame for " << (demonic_flame_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_mana((mana - spell1_cost));
    }
}

void Cultist::ability2(Enemy* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(inferno_damage);
        this->set_mana((mana - spell2_cost));
        cout << this->name << "'s fiery inferno blasts " << player->get_name() << " for " << (inferno_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability2() << " missed its target!" << endl;
        this->set_mana((mana - spell2_cost));
    }
}

void Cultist::ability3(Enemy* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(cinder_damage);
        this->set_mana((mana - spell3_cost));
        
        cout << this->name << " burns the ground around " << player->get_name() << " for " << (cinder_damage) << " damage!" << endl;
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