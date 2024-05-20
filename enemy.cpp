#include "Enemy.h"
#include "Player.h"
#include <string>
#include <unistd.h>
using namespace std;

Enemy::Enemy(){
    this->name = "Unnamed";
    this->AC = 0;
    this->base_damage = 0;
    this->speed = 0;
    this->health = 0;
}

Enemy::Enemy(string name){
    this->name = name;
    this->AC = 0;
    this->base_damage= 0;
    this->speed = 0;
    this->health = 0;
    this->stamina = 0;
    this->mana = 0;

    this->burn_counter = 0;
    this->stun_counter = 0;
    this->armour_counter = 0;
}

Enemy::~Enemy(){
    cout << "Enemy is deleted." << endl;
}

void Enemy::take_damage(int damage){
    int reduced_health = health - damage;
    this->health = reduced_health;  
}

int Enemy::dice_roll(){
    srand(time(0));  
    //cout << "Random number between 1 and 20 is: " <<endl;   
    int roll = (rand() % 20) + 1;
    cout << "Dice roll: " << roll << endl;
    sleep(1);
    return roll;  //returns rand number between 1-20
}

bool Enemy::does_it_hit_thePlayer(Player* player){
    if ((dice_roll() + chance_to_hit) > player->get_AC()){ //if the sum beats the opponents defence it hits
        return true;
    } else {
        return false;
    }
}

void Enemy::basic_attack(Player* player){
    if (does_it_hit_thePlayer(player) == true){
        player->take_damage(base_damage);
        cout << this->name << " hits " << player->get_name() << " with a basic attack for " << this->base_damage << " damage!" << endl;
    } else {
        cout << this->name << " missed!" << endl;
    }
}

//STATUS EFFECTS
bool Enemy::is_poisoned(int flag){
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}

bool Enemy::is_stunned(int flag){
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}

bool Enemy::is_burning(int flag){
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}
bool Enemy::is_buffed(int flag){
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}
// bool Enemy::is_debuffed(int flag){
//     if (flag = 0){
//         return false;
//     } else {
//         return true;
//     }
// }
void Enemy::clear_status_effects(){
    is_poisoned(0);
    is_stunned(0);
    is_burning(0);
    is_buffed(0);
}

//SETTERS

void Enemy::set_attributes(string name, int AC, int health, int base_damage, int chance_to_hit)
{
    this->name = name;
    this->AC = AC;
    this->health = health;
    this->base_damage = base_damage;
    this->chance_to_hit = chance_to_hit;
}

void Enemy::set_subclass_attributes()
{

}

void Enemy::set_health(int h){
    this->health = h;
}
void Enemy::set_name(string n){
    this->name = n;
}
void Enemy::set_mana(int c){
    this->mana = c;
}
void Enemy::set_stamina(int c){
    this->stamina = c;
}
void Enemy::set_AC(int c){
    this->AC = c;
}
void Enemy::set_abilityCost(int cost){
    this->ability_cost = cost;
}
void Enemy::set_burnCounter(int c){
    this->burn_counter = c;
}
void Enemy::set_stunCounter(int c){
    this->stun_counter = c;
}
void Enemy::set_armourCounter(int c){
    this->armour_counter = c;
}

//GETTERS
void Enemy::print_attributes()
{
    cout << "Name: " << name << endl;
    cout << "AC: " << AC << endl;
    cout << "Health: " << health << endl;
    cout << "Base damage: " << base_damage << endl;
    cout << "Chance to hit: " << chance_to_hit << endl;
}

void Enemy::get_subclass_attributes()
{

}


int Enemy::get_health(){
    return health;
}
int Enemy::get_AC(){
    return AC;
}
int Enemy::get_stamina(){
    return stamina;
}
int Enemy::get_mana(){
    return mana;
}
string Enemy::get_name(){
    return name;
}
string Enemy::get_ability1(){
    return ability_name1;
}
string Enemy::get_ability2(){
    return ability_name2;
}
string Enemy::get_ability3(){
    return ability_name3;
}
string Enemy::get_ability4(){
    return ability_name4;
}
int Enemy::get_abilityCost(){
    return ability_cost;
}
int Enemy::get_burnCounter(){
    return burn_counter;
}
int Enemy::get_stunCounter(){
    return stun_counter;
}
int Enemy::get_armourCounter(){
    return armour_counter;
}

int Enemy::get_staminaOrMana(){
    return staminaOrMana;
}
