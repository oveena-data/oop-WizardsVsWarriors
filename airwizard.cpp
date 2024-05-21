#include "Wizard.h"
#include "AirWizard.h"
#include <string>
using namespace std;

AirWizard::AirWizard(string name){
    this->name = name;
    this->AC = 15;
    this->health = 50;
    this->base_damage = 5;
    this->chance_to_hit = 6;
    this->mana = 100;
    this->element = "Air";
    this->subclass = "Air Wizard";

    this->burn_counter = 0;
    this->stun_counter = 0;

    this->ability_name1 = "Howling Tornado";
    this->spell1_cost = 10;
    this->gust_damage = 10;

    this->ability_name2 = "Wind Evasion";
    this->spell2_cost = 20;
    this->extra_armour = 3;

    this->ability_name3 = "Lightning storm";
    this->ability_cost = 30;
    this->lightning_damage = 30;

    this->armour_duration = 1; //lasts for 1 round
    this->armour_counter = 0;

}

void AirWizard::ability1(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(gust_damage);
        this->set_mana((mana - spell1_cost));
        cout << this->name << " unleashes a tornado on " << opponent->get_name() << " for " << (gust_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_mana((mana - spell1_cost));
    }
}

void AirWizard::ability2(Player* opponent, int cost){
    this->AC = (AC + extra_armour);
    this->set_mana(mana-cost);
    this->armour_counter = 1;
    cout << this->name << " floats in the air, increasing their armour by " << this->extra_armour << "!" << endl;
}

void AirWizard::ability3(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(lightning_damage);
        this->set_mana((mana - spell1_cost));
        cout << this->name << " throws a mighty lightning bolt at " << opponent->get_name() << " for " << (lightning_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_mana((mana - spell1_cost));
    }
}


int AirWizard::get_extraArmour(){
    return extra_armour;
}
int AirWizard::get_armourDuration(){
    return armour_duration;
}