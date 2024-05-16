#include "Player.h"
#include "Warrior.h"
#include "Valkyrie.h"

#include <string>
using namespace std;

Valkyrie::Valkyrie(){

}

Valkyrie::Valkyrie(string name){
    this->name = name;
    this->AC = 15;
    this->health = 60;
    this->base_damage = 7;
    //this->speed = 4;
    this->chance_to_hit = 3;
    this->stamina = 100;
    this->weapon = "Longsword";
    this->subclass = "Valkyrie";

    this->burn_counter = 0;
    this->stun_counter = 0;

    this->ability_name1 = "Divine Smite";
    this->ability_name2 = "Holy Armour";
    this->ability_cost = 30;
    this->smite_damage = 10;
    this->extra_armour = 3; //valkyrie can give herself extra armour using her second ability
}

void Valkyrie::ability1(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(base_damage + smite_damage);
        this->set_stamina((stamina - cost));
        cout << this->name << " smites " << opponent->get_name() << " with holy light for " << (smite_damage+base_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Valkyrie::ability2(Player*opponent, int cost){
    this->AC = (AC + extra_armour);
    this->set_stamina(stamina-cost);
    is_buffed(1);
    cout << this->name << "magically ups her defence by " << this->extra_armour << "!" << endl;
}

int Valkyrie::get_smiteDamage(){
    return smite_damage;
}
int Valkyrie::get_extraArmour(){
    return extra_armour;
}
int Valkyrie::get_armourDuration(){
    return armour_duration;
}