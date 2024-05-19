#include "Raider.h"
#include "Enemy.h"
#include <string>
using namespace std;

Raider::Raider(){
}

Raider::Raider(string s){
    this->subclass = s;
    this->weapon = "Undefined";
    this->stamina = 100;
}

Raider::~Raider(){
    cout << "Warrior is deleted." << endl;
}

//SETTERS
void Raider::set_subclass(string s){
    this->subclass = s;
}
void Raider::set_stamina(int st){
    this->stamina = st;
}
//GETTERS
string Raider::get_subclass(){
    return subclass;
}
int Raider::get_stamina(){
    return stamina;
}
/*
string stamina_or_mana(){
    return "stamina";
}
*/

