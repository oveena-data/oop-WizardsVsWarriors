#include "Player.h"
#include "Warrior.h"
#include "Hulk.h"
#include "Barbarian.h"
#include "Valkyrie.h"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main(){
    int input_class;
    int input_subclass;
    string player_name;

    cout << "Do you want to be a Warrior or a Wizard?" << endl;
    cout << "{1: Warrior} {2: Wizard}"<< endl;
    cin >> input_class;

    // Player *player;
    // player = new Player;

    Warrior *player = NULL;

    cout << "Please select a Warrior class: " << endl;
    cout << "{1: Hulk} {2: Barbarian} {3: Valkyrie}" << endl;
    cout << endl;
    cin >> input_class;

    //Warrior *player = NULL;

    if (input_subclass == 1){
        cout << "Please enter a name: ";
        cin >> player_name;
        player = new Hulk(player_name);

    } else if (input_subclass == 2){
        cout << "Please enter a name: ";
        cin >> player_name;
        player = new Barbarian(player_name);

    } else if (input_subclass == 3){
        cout << "Please enter a name: ";
        cin >> player_name;
        player = new Valkyrie(player_name);

    } else {
        cout << "Invalid input! Please enter a subclass." << endl;
    }

    //Hulk player("Bertha");
    Barbarian opponent("Bo");
    //initialise round 1
    int round = 1;

    //subclass testing
    //cout << "Subclass: " << player.get_subclass() << endl;

    //while both players have health above 0
    while(player->get_health() > 0 && opponent.get_health() > 0)
    {   
        cout << endl;
        cout << "Round " << round << "!" << endl;
        cout << "Player health: " << player->get_health() << " | Opponent health: " << opponent.get_health() << endl;
        cout << "Player stamina: " << player->get_stamina() << endl;
        cout << "Which action would you like to take?" << endl;
        cout << endl;
        cout << "{0: End Game Early} {1: Basic Attack} {2: " << player->get_ability1() << "}"<< endl;
        
        int attack_input;
        cin >> attack_input;

        //defensive programming to make sure input is as expected
        if (attack_input == 1 || attack_input == 2 || attack_input == 3 || attack_input == 0){
            switch (attack_input){
                case 0:
                cout << "Exiting game... " << endl;
                exit(0); //terminates the program
 
                case 1:
                player->basic_attack(&opponent);
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
                    player->ability1(&opponent, player->get_abilityCost());
                    cout << endl;
                    break; 
                }  
            } //switch statement end bracket

            if(opponent.get_health() > 0){
                sleep(1); //pauses runtime for 1 second for new dice result (die result relies on time(0))

                //rolls a die to determine whether the opponent will use a basic attack or a special attack
                if (opponent.dice_roll() > 13 && (opponent.get_stamina() >= opponent.get_abilityCost())){
                    cout << "Opponent uses an ability attack!" << endl;
                    opponent.ability1(player, opponent.get_abilityCost());
                } else {
                    opponent.basic_attack(player);
                }
            }
            if(player->get_health() <= 0){
                cout << opponent.get_name() << " wins!" << endl;
            } else if (opponent.get_health() <= 0){
                cout << player->get_name() << " wins!" << endl;
            }

            //after each round, allow for stamina regeneration if an ability has not been used

            round++; //aggregates round number

            //clears status effects caused by ability attacks. Will edit status effects later.
            player->clear_status_effects();
            opponent.clear_status_effects();
            
        } else {
            cout << "Invalid input! Please enter the number of the corresponding ability: ";
            //break;

        } //attack_input if-statment end bracket
    } //While-loop end bracket

    return 0;
}//main end bracket