#include "Wizard.h"
#include "WaterWizard.h"
#include <string>
using namespace std;

WaterWizard::WaterWizard(){

}

WaterWizard::WaterWizard(string name){
    this->name = name;
    this->AC = 13;
    this->health = 45;
    this->base_damage = 7;
    this->chance_to_hit = 5;
    this->mana = 100;
    this->element = "Water";
    this->subclass = "Water Wizard";

    this->burn_counter = 0;
    this->stun_counter = 0;

    this->ability_name1 = "Tidal Wave";
    this->spell1_cost = 20;

    this->ability_name2 = "Healing Waters";
    this->spell2_cost = 20;

    this->heal_amount = 20;
    this->heal_duration= 2; //2 rounds
}

void WaterWizard::ability1(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(wave_damage);
        this->set_mana((mana - spell1_cost));
        cout << this->name << " hits " << opponent->get_name() << " with a tidal wave for " << (wave_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_mana((mana - spell1_cost));
    }
}

void WaterWizard::ability2(Player* opponent, int cost){
    this->set_health(health + heal_amount);
    this->set_mana(mana-spell2_cost);
    //is_buffed(1);
    cout << this->name << " heals " << this->heal_amount << " hitpoints!" << endl;
}

void WaterWizard::ability3(Player* opponent, int cost){
    cout << "Water wizard ability 3." << endl;
}

// void WaterWizard::ability2(Player* opponent, int cost){
//     if (does_it_hit(opponent) == true){
//         opponent->take_damage(emberspit_damage);
//         this->set_mana((mana - spell2_cost));
//         cout << this->name << "'s fire fangs bite down on " << opponent->get_name() << " for " << (emberspit_damage) << " damage!" << endl;
//     } else {
//         cout << this->name << "'s "<< this->get_ability2() << " missed its target!" << endl;
//         this->set_mana((mana - spell2_cost));
//     }
// }
// class WaterWizard : public Wizard {
//     public:
//     int wave_damage;
//     int heal_amount;
//     int heal_duration;
    
//     //int ability_cost;

//     WaterWizard();
//     WaterWizard(string name);

//     void ability1 (Player* opponent, int cost);
//     void ability2 (Player* opponent, int cost);

//     int get_waveDamage();
//     int get_healAmount();
//     int get_healDuration();

// };
