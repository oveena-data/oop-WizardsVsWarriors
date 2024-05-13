#include "Player.h"
#include <string>
#include <unistd.h>
using namespace std;

Player::Player(){
    this->name = "Unnamed";
    this->AC = 0;
    this->base_damage = 0;
    this->speed = 0;
    this->health = 0;
}

Player::Player(string name){
    this->name = name;
    this->AC = 0;
    this->base_damage= 0;
    this->speed = 0;
    this->health = 0;
}

void Player::take_damage(int damage){
    int reduced_health = health - damage;
    this->health = reduced_health;  
}

int Player::dice_roll(){
    srand(time(0));  
    //cout << "Random number between 1 and 20 is: " <<endl;   
    int roll = (rand() % 20) + 1;
    cout << "Dice roll: " << roll << endl;
    sleep(1);
    return roll;  //returns rand number between 1-20
}

bool Player::does_it_hit(Player* opponent){
    if ((dice_roll() + chance_to_hit) > opponent->AC){ //if the sum beats the opponents defence it hits
        return true;
    } else {
        return false;
    }
}

void Player::basic_attack(Player* opponent){
    if (does_it_hit(opponent) == true){
        opponent->take_damage(base_damage);
        cout << this->name << " hits " << opponent->get_name() << " with a basic attack for " << this->base_damage << " damage!" << endl;
    } else {
        cout << this->name << " missed!" << endl;
    }
}

//STATUS EFFECTS
bool Player::is_poisoned(int flag){
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}

bool Player::is_stunned(int flag){
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}

bool Player::is_burning(int flag){
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}
bool Player::is_buffed(int flag){
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}
// bool Player::is_debuffed(int flag){
//     if (flag = 0){
//         return false;
//     } else {
//         return true;
//     }
// }
void Player::clear_status_effects(){
    is_poisoned(0);
    is_stunned(0);
    is_burning(0);
    is_buffed(0);
}

//SETTERS
void Player::set_health(int h){
    this->health = h;
}
void Player::set_name(string n){
    this->name = n;
}
void Player::set_abilityCost(int cost){
    this->ability_cost = cost;
}

//GETTERS
int Player::get_health(){
    return health;
}
string Player::get_name(){
    return name;
}
string Player::get_ability1(){
    return ability_name1;
}
string Player::get_ability2(){
    return ability_name2;
}
int Player::get_abilityCost(){
    return ability_cost;
}