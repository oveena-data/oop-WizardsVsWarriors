#include "Wizard.h"
#include "WaterWizard.h"
#include <string>
using namespace std;

WaterWizard::WaterWizard(){

}

WaterWizard::WaterWizard(string name){
    this->name = name;
    this->AC = 13;
    this->health = 50;
    this->base_damage = 7;
    this->wave_damage = 25;
    this->chance_to_hit = 5;
    this->mana = 100;
    this->element = "Water";
    this->subclass = "Water Wizard";

    this->burn_counter = 0;
    this->stun_counter = 0;
    this->heal_counter - 0;

    this->ability_name1 = "Tidal Wave";
    this->spell1_cost = 20;

    this->ability_name2 = "Healing Waters";
    this->spell2_cost = 20;

    this->heal_amount = 20;
    this->heal_duration= 2; //2 rounds
}
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
