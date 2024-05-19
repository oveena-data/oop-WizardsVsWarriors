#include "Enemy.h"
#include "Sorcerer.h"
#include <string>
using namespace std;

Sorcerer::Sorcerer(){

}

Sorcerer::Sorcerer(string s){
    this->subclass = s;
    this->mana = 100;
    this->element = "Undefined";
    this->staminaOrMana = 2; //set to 2, creating 'mana' attribute instead of 'stamina'
}

Sorcerer::~Sorcerer(){
    cout << "Sorcerer is deleted." << endl;
}

//SETTERS
void Sorcerer::set_subclass(string s){
    this->subclass = s;
}
void Sorcerer::set_mana(int m){
    this->mana = m;
}
//GETTERS
string Sorcerer::get_subclass(){
    return subclass;
}
int Sorcerer::get_mana(){
    return mana;
}
int Sorcerer::get_spell1_cost(){
    return spell1_cost;
}
int Sorcerer::get_spell2_cost(){
    return spell2_cost;
}
int Sorcerer::get_spell3_cost(){
    return spell3_cost;
}
int Sorcerer::get_spell4_cost(){
    return spell4_cost;
}
string Sorcerer::stamina_or_mana(){
    return "mana";
}