#include "Warrior.h"
#include "Player.h"
#include <string>
using namespace std;

Warrior::Warrior(){
 this->subclass = "Undefined";
 this->weapon = "Unarmed";
 this->stamina = 0;
}

Warrior::Warrior(string s){
    this->subclass = s;
    this->weapon = "Loading...";
    this->stamina = 100;
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

