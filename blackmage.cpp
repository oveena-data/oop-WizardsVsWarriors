#include "Wizard.h"
#include "Blackmage.h"
#include "Player.h"

#include "Player.h"
#include <string>
using namespace std;

BlackMage::BlackMage()
{

}

BlackMage::BlackMage(string name){
    this->name = name;
    this->AC = 11;
    this->health = 60;
    this->base_damage = 7;
    this->dark_bolt_damage = 10;
    this->dark_storm_damage = 20;
    this->creeping_death_damage = 20;
    this->chance_to_hit = 5;
    this->mana = 100;
    this->element = "Shadow";
    this->subclass = "Black Mage";
    this->shadow_duration = 3;
    this->shadow_counter = 0;

    this->ability_name1 = "Dark Bolt";
    this->spell1_cost = 20;

    this->ability_name2 = "Dark Storm";
    this->spell2_cost = 30;

    this->ability_name3 = "Creeping Death";
    this->spell3_cost = 40;
    this->AC = AC + 10;

    /*
    this->ability_name4 = "Blizzard";
    this->spell4_cost = 30;
    this->AC = AC + 3;
    this->blizzard_duration = 3;
    */

    

}

int BlackMage::get_shadow_duration()
{
    return shadow_duration;
}

void BlackMage::set_subclass_attributes()
{
    this->dark_bolt_damage = 10;
    this->dark_storm_damage = 25;
    this->creeping_death_damage = 10;
    this->mana = 100;
    this->element = "Shadow";
    this->subclass = "Black Mage";

}

void BlackMage::get_subclass_attributes()
{
    cout << "Dark Bolt damage: " << dark_bolt_damage << endl;
    cout << "Dark Storm damage: " << dark_storm_damage << endl;
    cout << "Creeping Death damage: " << creeping_death_damage << endl;
    cout << "Mana: " << mana << endl;
    cout << "Element: " << element << endl;
    cout << "Subclass: " << subclass << endl;
}

void BlackMage::ability1(Player* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(dark_bolt_damage);
        this->set_mana((mana - spell1_cost));
        cout << this->name << " hits " << player->get_name() << " with a dark bolt for " << (dark_bolt_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_mana((mana - spell1_cost));
    }
}

void BlackMage::ability2(Player* player, int cost){
    if (does_it_hit(player) == true){
        player->take_damage(dark_storm_damage);
        this->set_mana((mana - spell2_cost));
        cout << this->name << "'s evil storm courses around " << player->get_name() << " and deals " << (dark_storm_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability2() << " missed its target!" << endl;
        this->set_mana((mana - spell2_cost));
    }
}

void BlackMage::ability3(Player* player, int cost){
    this->AC = AC + 5;
    if (does_it_hit(player) == true){
        player->take_damage(creeping_death_damage);
        this->set_mana((mana - spell3_cost));
        cout << this->name << "'s dread spell spills forth at " << player->get_name() << " for " << (creeping_death_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability3() << " missed its target!" << endl;
        this->set_mana((mana - spell3_cost));
    }
    this->AC = AC - 5;
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