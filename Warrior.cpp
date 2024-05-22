#include "Warrior.h"
#include "Player.h"
#include <string>
using namespace std;

Warrior::Warrior(){
 this->subclass = "Undefined";
 this->weapon = "Unarmed";
 this->stamina = 0;
 this->staminaOrMana = 1;
}

Warrior::Warrior(string s){
    this->subclass = s;
    this->weapon = "Loading...";
    this->stamina = 100;
}

Warrior::~Warrior(){
    cout << "Warrior is deleted." << endl;
}

//SETTERS
void Warrior::set_subclass(string s){
    this->subclass = s;
}
void Warrior::set_stamina(int st){
    this->stamina = st;
}
//GETTERS
string Warrior::get_subclass(){
    return subclass;
}
int Warrior::get_stamina(){
    return stamina;
}
string stamina_or_mana(){
    return "stamina";
}
int Warrior::get_ability1_cost(){
    return ability1_cost;
}
int Warrior::get_ability2_cost(){
    return ability2_cost;
}

int Warrior::get_ability3_cost(){
    return ability3_cost;
}
