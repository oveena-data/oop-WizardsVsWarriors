#include <iostream>
//include enemy paths
#include "Enemy.h"
#include "Sorcerer.h"
#include "Raider.h"
#include "Cryomancer.h"
#include "Blackmage.h"
#include "Cultist.h"
#include "Headhunter.h"
#include "Oathbreaker.h"
#include "Assassin.h"
//include player paths
#include "Player.h"
#include "Warrior.h"
#include "Wizard.h"
#include "FireWizard.h"
#include "WaterWizard.h"
#include "AirWizard.h"
#include "Hulk.h"
#include "Barbarian.h"
#include "Valkyrie.h"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(){
    //initialise input variables and player name
    int input_class;
    int input_subclass;
    string player_name;

    //Player *player = NULL;

    //initialise classes that use status effects
    Barbarian *barb = new Barbarian; 
    Sorcerer *sorc = new Cultist;
    
    // Create enemy 
    srand(time(0)); // reseeds the rand() function
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
        //opponent->print_attributes(); 
        headhunter->set_subclass_attributes(); 
        //opponent->get_subclass_attributes();
        cout << "You face a " << opponent->get_name() << endl;
    }   else if (enemyChoice == 1)
    {
        opponent = new Oathbreaker();
        Oathbreaker* oathbreaker = static_cast<Oathbreaker*> (opponent);
        opponent->set_attributes("Oathbreaker", 100, 15, 10, 8);
        //opponent->print_attributes(); 
        oathbreaker->set_subclass_attributes(); 
        //opponent->get_subclass_attributes();
        cout << "You face a " << opponent->get_name() << endl;
    }   else if (enemyChoice == 2)
    {
        opponent = new Assassin();
        Assassin* assassin = static_cast<Assassin*> (opponent);
        opponent->set_attributes("Assassin", 100, 15, 10, 8);
        //opponent->print_attributes(); 
        assassin->set_subclass_attributes(); 
        //opponent->get_subclass_attributes();
        cout << "You face a " << opponent->get_name() << endl;
    }   else if (enemyChoice == 3)
    {
        opponent = new Cryomancer();
        Cryomancer* cryomancer = static_cast<Cryomancer*> (opponent);    
        opponent->set_attributes("Cryomancer", 11, 60, 7, 5);
        //opponent->print_attributes(); 
        cryomancer->set_subclass_attributes(); 
        //opponent->get_subclass_attributes();
        cout << "You face a " << opponent->get_name() << endl;
    } else if (enemyChoice == 4)
    {
        opponent = new BlackMage();
        BlackMage* blackmage = static_cast<BlackMage*> (opponent);
        opponent->set_attributes("Blackmage", 11, 60, 7, 5);
        //opponent->print_attributes(); 
        blackmage->set_subclass_attributes(); 
        //opponent->get_subclass_attributes();
        cout << "You face a " << opponent->get_name() << endl;
    } else if (enemyChoice == 5)
    {
        opponent = new Cultist();
        Cultist* cultist = static_cast<Cultist*> (opponent);
        opponent->set_attributes("Cultist", 11, 60, 7, 5);
        //opponent->print_attributes(); 
        cultist->set_subclass_attributes(); 
        //opponent->get_subclass_attributes();
        cout << "You face a " << opponent->get_name() << endl;
    }
    

    //prompt the player for the choice between warrior or wizard
    cout << "Do you want to be a Warrior or a Wizard?" << endl;
    cout << "{1: Warrior} {2: Wizard}"<< endl;
    cin >> input_class;

    
    
    

    if (input_class == 1){ //IF WARRIOR BEGIN IF STATEMENT

        Warrior *player = NULL; //Initialise an empty warrior
        system("clear"); //clear the terminal for tidiness
        cout << "Please select a Warrior class: " << endl;
        cout << "{1: Hulk} {2: Barbarian} {3: Valkyrie}" << endl;
        cout << endl;
        cin >> input_subclass;

        //initialise bool to repeat input loop ** (seg fault???) **
        bool valid = false;

        while (!valid){
            if (input_subclass == 1){
                cout << "Please enter a name: ";
                cin >> player_name;
                player = new Hulk(player_name); //reassign player to hulk object
                valid = true;

            } else if (input_subclass == 2){
                cout << "Please enter a name: ";
                cin >> player_name;
                player = new Barbarian(player_name); //reassign player to barbarian object
                valid = true;

            } else if (input_subclass == 3){
                cout << "Please enter a name: ";
                cin >> player_name;
                player = new Valkyrie(player_name); //reassign player to valkyrie object
                valid = true;

            } else {
                cout << "Invalid input! Please enter a subclass." << endl;
                //delete player;
                //valid = false;
                break; 
            }

        }
        if (player == NULL){
            cout << "Failed to create player. Terminating..." << endl;
            delete barb;
            return 1;
        }

        //initialise round 1
        int round = 1;

        //subclass testing
        cout << "Subclass: " << player->get_subclass() << endl;
        sleep(3); //pause terminal for 3 seconds to allow player to read
        system("clear"); //clear terminal for tidiness

        //while both players have health above 0
        while(player->get_health() > 0 && opponent->get_health() > 0)
        {   
            //visuals
            cout << endl;
            cout << "-------------------------------------" << endl;
            cout << "Round " << round << "!" << endl; //displays round number
            cout << "Player health: " << player->get_health() << " | Opponent health: " << opponent->get_health() << endl;
            cout << "Player stamina: " << player->get_stamina() << endl;
            cout << "Which action would you like to take?" << endl;
            cout << endl;
            //listing actions player can take
            cout << "{0: End Game Early} {1: Basic Attack (no stamina)} {2: " << player->get_ability1() << " ("<<player->get_abilityCost()<< " stamina)}"<< endl;
            cout << "{3: " << player->get_ability2() <<player->get_ability2()<<" stamina)}" << endl;

            int attack_input;
            cin >> attack_input;

            //defensive programming to make sure input is as expected
            if (attack_input == 1 || attack_input == 2 || attack_input == 3 || attack_input == 0){
                switch (attack_input){
                    case 0:
                    cout << "Exiting game... " << endl;
                    exit(0); //terminates the program. mainly used for testing.
 
                    case 1:
                    player->basic_attack(opponent);
                    player->set_stamina(player->get_stamina() + 15); //stamina refills slightly on basic attack
                    cout << endl;
                    break;

                    case 2:
                    //warrior can only use special ability if they have enough stamina
                    if (player->get_abilityCost() > player->get_stamina()){
                        cout << "Not enough stamina! Resting..." << endl;
                        cout << endl;
                        player->set_stamina(player->get_stamina() + 25);
                        break; //***at this point this code forfeits the player's turn, i'm not sure how to fix this yet.***
                    } else {
                        player->ability1(opponent, player->get_abilityCost());
                        cout << endl;
                        break; 
                    }  
                } //switch statement end bracket

                //if opponent is not out of health,
                if(opponent->get_health() > 0){
                    sleep(1); //pauses runtime for 1 second for new dice result (die result relies on time(0))

                    if (opponent->get_staminaOrMana() == 1){ //if opponent uses stamina
                        //rolls a die to determine whether the opponent will use a basic attack or a special attack
                        if (opponent->dice_roll() > 13 && (opponent->get_stamina() >= opponent->get_abilityCost())){
                            cout << "Opponent uses an ability attack!" << endl;
                            opponent->ability1(player, opponent->get_abilityCost());
                        } else {
                            opponent->basic_attack(player);
                            opponent->set_stamina(opponent->get_stamina() + 15);
                        }
                    } else if (opponent->get_staminaOrMana() == 2){
                        //rolls a die to determine whether the opponent will use a basic attack or a special attack
                        if (opponent->dice_roll() > 13 && (opponent->get_mana() >= opponent->get_abilityCost())){
                            cout << "Opponent uses an ability attack!" << endl;
                            srand(time(0)); // reseeds the rand() function
                            int enemyAbility = rand() % 3;
                            cout << enemyAbility << endl;
                            
                            switch (enemyAbility){
                                case 1:
                                opponent->ability1(player, opponent->get_abilityCost());

                                case 2:
                                opponent->ability2(player, opponent->get_abilityCost());

                                case 3:
                                opponent->ability3(player, opponent->get_abilityCost());

                                default:
                                cout << "fix this";
                                return 1;
                            }
                        } else {
                            opponent->basic_attack(player);
                            opponent->set_stamina(opponent->get_stamina() + 15);
                        }
                    }
                } //if opponent health > 0

                //after each round, determine whether the player is burning 
                if(player->get_burnCounter() > 0 ){
                    //if yes, the player will take the burning damage
                    player->take_damage(barb->burn_damage);
                    cout << player->get_name() << " burns for " << barb->get_burnDamage() << " damage."<< endl;
                    //burning counter will be decreased after each round
                    player->set_burnCounter(player->get_burnCounter()-1);
                    cout << player->get_name() << " is burning for " << player->get_burnCounter() << " more round(s)" << endl;
                }
                //if the burning counter has reached 0 they will no longer be burning
                if(player->get_burnCounter() == 0){
                    player->is_burning(0);
                }

                //after each round, determine whether the opponent is burning
                if(opponent->get_burnCounter() > 0){
                    opponent->take_damage(barb->burn_damage);
                    cout << opponent->get_name() << " burns for " << barb->get_burnDamage() << " damage."<< endl;
                    opponent->set_burnCounter(opponent->get_burnCounter()-1);
                    cout << opponent->get_name() << " is burning for " << opponent->get_burnCounter() << " more round(s)." << endl;
                }
                if(opponent->get_burnCounter() == 0){
                    opponent->is_burning(0);
                }

                //after each round determine whether the player continues to have extra armour
                if(player->get_armourCounter() > 0){
                    player->set_armourCounter(player->get_armourCounter()-1);
                    //should only use this if statement if there was an existing buff, hence nested if-statement
                    if(player->get_armourCounter() == 0){
                        player->set_AC(player->get_AC()-3);
                        cout << player->get_name() << " has lost their bonus armour." << endl;
                    }
                }
                //after each round determine whether the opponent continues to have extra armour
                if(opponent->get_armourCounter() > 0){
                    player->set_armourCounter(opponent->get_armourCounter() -1);
                    //should only use this if statement if there was an existing buff, hence nested if-statement
                    if(opponent->get_armourCounter() == 0){
                        opponent->set_AC(opponent->get_AC()-3);
                        cout << opponent->get_name() << " has lost their bonus armour." << endl;
                    }
                }

                if(player->get_health() <= 0){
                    cout << opponent->get_name() << " wins!" << endl;
                } else if (opponent->get_health() <= 0){
                    cout << player->get_name() << " wins!" << endl;
                }

                round++; //aggregates round number

                //clears status effects caused by ability attacks. Will edit status effects later.
                // player->clear_status_effects();
                // opponent->clear_status_effects();
            
            } else {
                cout << "Invalid input! Please enter the number of the corresponding ability: ";
                //break;

            } //attack_input if-statment end bracket
            sleep(3);
            
        } //While-loop end bracket
        delete barb; //subclasses used for status conditions must be deleted at end of game

        return 0;

//WARRIOR CODE ^ ^ ^ 









//WIZARD CODE \/  \/ \/


    } else if (input_class == 2){
        Wizard *player = NULL;
        cout << "Please select a Wizard class: " << endl;
        cout << "{1: FireWizard} {2: ...} {3: ...}" << endl;
        cout << endl;
        cin >> input_subclass;

        if (input_subclass == 1){
            cout << "Please enter a name: ";
            cin >> player_name;
            player = new FireWizard(player_name);

        } else if (input_subclass == 2){
            cout << "Please enter a name: ";
            cin >> player_name;
            player = new WaterWizard(player_name);

        } else if (input_subclass == 3){
            cout << "Please enter a name: ";
            cin >> player_name;
            //player = new Valkyrie(player_name);

        } else {
         cout << "Invalid input! Please enter a subclass." << endl;
        }

        if (player == NULL){
            cout << "Failed to create player. Terminating..." << endl;
            delete barb;
            return 1;
        }

        //Hulk player("Bertha");
        //Barbarian opponent("Bo");
        //initialise round 1
        int round = 1;

        //subclass testing
        cout << "Subclass: " << player->get_subclass() << endl;

        //while both players have health above 0
        while(player->get_health() > 0 && opponent->get_health() > 0)
        {   
            //visuals
            cout << endl;
            cout << "Round " << round << "!" << endl;
            cout << "Player health: " << player->get_health() << " | Opponent health: " << opponent->get_health() << endl;
            cout << "Player stamina: " << player->get_mana() << endl;
            cout << "Which action would you like to take?" << endl;
            cout << endl;
            //player menu
            cout << "{0: End Game Early} {1: Basic Attack} {2: " << player->get_ability1() << " ("<<player->get_spell1_cost()<<" mana)}"<< endl;
            cout << "{3: " << player->get_ability2() <<" ("<<player->get_spell2_cost()<<" mana)}" << endl;
        
            int attack_input;
            cin >> attack_input;

            //defensive programming to make sure input is as expected
            if (attack_input == 1 || attack_input == 2 || attack_input == 3 || attack_input == 0){
                switch (attack_input){
                    case 0:
                    cout << "Exiting game... " << endl;
                    exit(0); //terminates the program
 
                    case 1:
                    player->basic_attack(opponent);
                    player->set_mana(player->get_mana() + 15);
                    cout << endl;
                    break;

                    case 2:
                    //wizard can only use special ability if they have enough mana
                    if (player->get_spell1_cost() > player->get_mana()){
                        cout << "Not enough mana! Resting..." << endl;
                        cout << endl;
                        player->set_mana(player->get_mana() + 25);
                        break; //***at this point this code forfeits the player's turn, i'm not sure how to fix this yet.***
                    } else {
                        player->ability1(opponent, 0);
                        cout << endl;
                        break; 
                    }  

                    case 3:
                    //wizard can only use special ability if they have enough mana
                    if (player->get_spell2_cost() > player->get_mana()){
                        cout << "Not enough mana! Resting..." << endl;
                        cout << endl;
                        player->set_mana(player->get_mana() + 25);
                        break; //***at this point this code forfeits the player's turn, i'm not sure how to fix this yet.***
                    } else {
                        player->ability2(opponent, 0);
                        cout << endl;
                        break; 
                    }  

                } //switch statement end bracket

                //if opponent is not out of health,
                if(opponent->get_health() > 0){
                    sleep(1); //pauses runtime for 1 second for new dice result (die result relies on time(0))

                    if (opponent->get_staminaOrMana() == 1){ //if opponent uses stamina
                        //rolls a die to determine whether the opponent will use a basic attack or a special attack
                        if (opponent->dice_roll() > 13 && (opponent->get_stamina() >= opponent->get_abilityCost())){
                            cout << "Opponent uses an ability attack!" << endl;
                            opponent->ability1(player, opponent->get_abilityCost());
                        } else {
                            opponent->basic_attack(player);
                            opponent->set_stamina(opponent->get_stamina() + 15);
                        }
                    } else if (opponent->get_staminaOrMana() == 2){
                        //rolls a die to determine whether the opponent will use a basic attack or a special attack
                        if (opponent->dice_roll() > 13 && (opponent->get_mana() >= opponent->get_abilityCost())){
                            cout << "Opponent uses an ability attack!" << endl;
                            srand(time(0)); // reseeds the rand() function
                            int enemyAbility = rand() % 3;
                            cout << enemyAbility << endl;
                            
                            switch (enemyAbility){
                                case 1:
                                opponent->ability1(player, opponent->get_abilityCost());

                                case 2:
                                opponent->ability2(player, opponent->get_abilityCost());

                                case 3:
                                opponent->ability3(player, opponent->get_abilityCost());

                                default:
                                cout << "fix this";
                                return 1;
                            }
                        } else {
                            opponent->basic_attack(player);
                            opponent->set_stamina(opponent->get_stamina() + 15);
                        }
                    }
                } //if opponent health > 0

                //after each round, determine whether the player is burning 
                if(player->get_burnCounter() > 0 ){
                    //if yes, the player will take the burning damage
                    player->take_damage(barb->burn_damage);
                    cout << player->get_name() << " burns for " << barb->get_burnDamage() << " damage."<< endl;
                    //burning counter will be decreased after each round
                    player->set_burnCounter(player->get_burnCounter()-1);
                    cout << player->get_name() << " is burning for " << player->get_burnCounter() << " more round(s)" << endl;
                }
                //if the burning counter has reached 0 they will no longer be burning
                if(player->get_burnCounter() == 0){
                    player->is_burning(0);
                }

                //after each round, determine whether the opponent is burning
                if(opponent->get_burnCounter() > 0){
                    opponent->take_damage(barb->burn_damage);
                    cout << opponent->get_name() << " burns for " << barb->get_burnDamage() << " damage."<< endl;
                    opponent->set_burnCounter(opponent->get_burnCounter()-1);
                    cout << opponent->get_name() << " is burning for " << opponent->get_burnCounter() << " more round(s)." << endl;
                }
                if(opponent->get_burnCounter() == 0){
                    opponent->is_burning(0);
                }

                //after each round determine whether the player continues to have extra armour
                if(player->get_armourCounter() > 0){
                    player->set_armourCounter(player->get_armourCounter()-1);
                    //should only use this if statement if there was an existing buff, hence nested if-statement
                    if(player->get_armourCounter() == 0){
                        player->set_AC(player->get_AC()-3);
                        cout << player->get_name() << " has lost their bonus armour." << endl;
                    }
                }
                //after each round determine whether the opponent continues to have extra armour
                if(opponent->get_armourCounter() > 0){
                    player->set_armourCounter(opponent->get_armourCounter() -1);
                    //should only use this if statement if there was an existing buff, hence nested if-statement
                    if(opponent->get_armourCounter() == 0){
                        opponent->set_AC(opponent->get_AC()-3);
                        cout << opponent->get_name() << " has lost their bonus armour." << endl;
                    }
                }

                if(player->get_health() <= 0){
                    cout << opponent->get_name() << " wins!" << endl;
                } else if (opponent->get_health() <= 0){
                    cout << player->get_name() << " wins!" << endl;
                }

                round++; //aggregates round number

                //clears status effects caused by ability attacks. Will edit status effects later.
                // player->clear_status_effects();
                // opponent->clear_status_effects();
            
            } else {
                cout << "Invalid input! Please enter the number of the corresponding ability: ";
                //break;

            } //attack_input if-statment end bracket
            sleep(3);
            
        } //While-loop end bracket
        delete barb; //subclasses used for status conditions must be deleted at end of game
        return 0;

    } else {
        cout << "Invalid input! Terminating..." << endl;
    } // WARRIOR OR WIZARD end bracket
} //main end bracket
