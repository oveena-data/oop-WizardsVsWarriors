#include "Wizard.h"
#include "FireWizard.h"
//#include "Enemy.h"
#include <string>
using namespace std;

FireWizard::FireWizard(string name){
    this->name = name;
    this->AC = 11;
    this->health = 60;
    this->base_damage = 7;
    this->fireball_damage = 25;
    this->emberspit_damage = 15;
    this->chance_to_hit = 5;
    this->mana = 100;
    this->element = "Fire";
    this->subclass = "Fire Wizard";

    this->burn_counter = 0;
    this->stun_counter = 0;

    this->ability_name1 = "Fireball";
    this->spell1_cost = 40;

    this->ability_name2 = "Ember Spit";
    this->spell2_cost = 20;
    this->burn_damage = 5;
    this->burn_duration = 2; //2 rounds
}

void FireWizard::ability1(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(fireball_damage);
        this->set_mana((mana - spell1_cost));
        cout << this->name << " blasts " << opponent->get_name() << " with a fireball for " << (fireball_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_mana((mana - spell1_cost));
    }
}

void FireWizard::ability2(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(emberspit_damage);
        this->set_mana((mana - spell2_cost));
        cout << this->name << "'s fire fangs bite down on " << opponent->get_name() << " for " << (emberspit_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability2() << " missed its target!" << endl;
        this->set_mana((mana - spell2_cost));
    }
}

void FireWizard::ability3(Player* opponent, int cost){
    cout << "Fire wizard ability 3." << endl;
}