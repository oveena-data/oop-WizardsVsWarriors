#include "Player.h"
//#include "Enemy.h"
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

    this->burn_counter = 0;
    this->stun_counter = 0;
    this->armour_counter = 0;
}

Player::~Player(){
    cout << "Player is deleted." << endl;
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
    if ((dice_roll() + chance_to_hit) > opponent->get_AC()){ //if the sum beats the opponents defence it hits
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
void Player::set_burnCounter(int c){
    this->burn_counter = c;
}
void Player::set_stunCounter(int c){
    this->stun_counter = c;
}
void Player::set_armourCounter(int c){
    this->armour_counter = c;
}
void Player::set_AC(int c){
    this->AC = c;
}
void Player::set_stamina(int c){
    this->stamina = c;
}
void Player::set_mana(int c){
    this->mana = c;
}
void Player::set_staminaOrMana(int c){
    this->staminaOrMana = c;
}
void Player::set_attributes(string name, int AC, int health, int base_damage, int chance_to_hit)
{
    this->name = name;
    this->AC = AC;
    this->health = health;
    this->base_damage = base_damage;
    this->chance_to_hit = chance_to_hit;
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
string Player::get_ability3(){
    return ability_name3;
}
int Player::get_abilityCost(){
    return ability_cost;
}
int Player::get_burnCounter(){
    return burn_counter;
}
int Player::get_stunCounter(){
    return stun_counter;
}
int Player::get_armourCounter(){
    return armour_counter;
}
int Player::get_AC(){
    return AC;
}
int Player::get_stamina(){
    return stamina;
}
int Player:: get_mana(){
    return mana;
}

int Player::get_staminaOrMana(){
    return staminaOrMana;
}


// Enemy::Enemy(){
//     this->name = "Unnamed";
//     this->AC = 0;
//     this->base_damage = 0;
//     this->speed = 0;
//     this->health = 0;
// }

// Enemy::Enemy(string name){
//     this->name = name;
//     this->AC = 0;
//     this->base_damage= 0;
//     this->speed = 0;
//     this->health = 0;
//     this->stamina = 0;
//     this->mana = 0;

//     this->burn_counter = 0;
//     this->stun_counter = 0;
//     this->armour_counter = 0;
// }

// Enemy::~Enemy(){
//     cout << "Enemy is deleted." << endl;
// }

// void Enemy::take_damage(int damage){
//     int reduced_health = health - damage;
//     this->health = reduced_health;  
// }

// int Enemy::dice_roll(){
//     srand(time(0));  
//     //cout << "Random number between 1 and 20 is: " <<endl;   
//     int roll = (rand() % 20) + 1;
//     cout << "Dice roll: " << roll << endl;
//     sleep(1);
//     return roll;  //returns rand number between 1-20
// }

// bool Enemy::does_it_hit_thePlayer(Player* player){
//     if ((dice_roll() + chance_to_hit) > player->get_AC()){ //if the sum beats the opponents defence it hits
//         return true;
//     } else {
//         return false;
//     }
// }

// void Enemy::basic_attack(Player* player){
//     if (does_it_hit_thePlayer(player) == true){
//         player->take_damage(base_damage);
//         cout << this->name << " hits " << player->get_name() << " with a basic attack for " << this->base_damage << " damage!" << endl;
//     } else {
//         cout << this->name << " missed!" << endl;
//     }
// }

// //STATUS EFFECTS
// bool Enemy::is_poisoned(int flag){
//     if (flag == 0){
//         return false;
//     } else {
//         return true;
//     }
// }