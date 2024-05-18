#include <iostream>
#include "Enemy.h"
#include "Sorcerer.h"
#include "Raider.h"
#include "Cryomancer.h"
#include "Headhunter.h"
#include "Blackmage.h"
#include "Cultist.h"
#include "Oathbreaker.h"
#include "Assassin.h"
//#include "Player.h"
//#include "Warrior.h"
//#include "Wizard.h"
//#include "FireWizard.h"
//#include "Hulk.h"
//#include "Barbarian.h"
//#include "Valkyrie.h"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
int enemyChoice;
int main() 
{
    // Create enemy 
    srand(time(0));
    int enemyChoice = rand() % 6;
    //cout << "Choose enemy class" << endl;
    //cout << "Headhunter (1), Cryomancer (2)" << endl;
    //cin >> enemyChoice;
    Enemy* opponent;
    if (enemyChoice == 0)
    {
        opponent = new Headhunter();
        Headhunter* headhunter = static_cast<Headhunter*> (opponent);
        opponent->set_attributes("Headhunter", 100, 15, 10, 8);
        opponent->print_attributes(); 
        headhunter->set_subclass_attributes(); 
        opponent->get_subclass_attributes();
    }   else if (enemyChoice == 1)
    {
        opponent = new Oathbreaker();
        Oathbreaker* oathbreaker = static_cast<Oathbreaker*> (opponent);
        opponent->set_attributes("Oathbreaker", 100, 15, 10, 8);
        opponent->print_attributes(); 
        oathbreaker->set_subclass_attributes(); 
        opponent->get_subclass_attributes();
    }   else if (enemyChoice == 2)
    {
        opponent = new Assassin();
        Assassin* assassin = static_cast<Assassin*> (opponent);
        opponent->set_attributes("Assassin", 100, 15, 10, 8);
        opponent->print_attributes(); 
        assassin->set_subclass_attributes(); 
        opponent->get_subclass_attributes();
    }   else if (enemyChoice == 3)
    {
        opponent = new Cryomancer();
        Cryomancer* cryomancer = static_cast<Cryomancer*> (opponent);    
        opponent->set_attributes("Cryomancer", 11, 60, 7, 5);
        opponent->print_attributes(); 
        cryomancer->set_subclass_attributes(); 
        opponent->get_subclass_attributes();
    } else if (enemyChoice == 4)
    {
        opponent = new BlackMage();
        BlackMage* blackmage = static_cast<BlackMage*> (opponent);
        opponent->set_attributes("Blackmage", 11, 60, 7, 5);
        opponent->print_attributes(); 
        blackmage->set_subclass_attributes(); 
        opponent->get_subclass_attributes();
    } else if (enemyChoice == 5)
    {
        opponent = new Cultist();
        Cultist* cultist = static_cast<Cultist*> (opponent);
        opponent->set_attributes("Cultist", 11, 60, 7, 5);
        opponent->print_attributes(); 
        cultist->set_subclass_attributes(); 
        opponent->get_subclass_attributes();
    }




    /*
    switch (enemyChoice)
    {
        case 1:
            enemy = new blackMage();
            enemy->setName("Black Mage");
            enemy->setHealth(50);
            break;
        case 2:
            break;
    */
    return 0;
}