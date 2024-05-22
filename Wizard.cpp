#include "Player.h"
#include "Wizard.h"

//#include "Enemy.h"
#include <string>
using namespace std;

Wizard::Wizard(){
    this->staminaOrMana = 2;

}

Wizard::Wizard(string s){
    this->subclass = s;
    this->mana = 100;
    this->element = "Undefined";
    this->staminaOrMana = 2;
}

Wizard::~Wizard(){
    cout << "Wizard is deleted." << endl;
}

//SETTERS
void Wizard::set_subclass(string s){
    this->subclass = s;
}
void Wizard::set_mana(int m){
    this->mana = m;
}
//GETTERS
string Wizard::get_subclass(){
    return subclass;
}
int Wizard::get_mana(){
    return mana;
}
int Wizard::get_spell1_cost(){
    return spell1_cost;
}
int Wizard::get_spell2_cost(){
    return spell2_cost;
}
int Wizard::get_spell3_cost(){
    return spell3_cost;
}
string Wizard::stamina_or_mana(){
    return "mana";
}