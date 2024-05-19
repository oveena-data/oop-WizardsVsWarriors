#include "Player.h"
#include "Warrior.h"
#include "Wizard.h"
#include "FireWizard.h"
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

    Player *player = NULL;
    Barbarian *barb = new Barbarian; 

    if (input_class == 1){
        system("clear");
        cout << "Please select a Warrior class: " << endl;
        cout << "{1: Hulk} {2: Barbarian} {3: Valkyrie}" << endl;
        cout << endl;
        cin >> input_subclass;

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
            cout << "Invalid input! Exiting..." << endl;
            delete barb;
            return 1;
        }

    } else if (input_class == 2){
        cout << "Please select a Wizard class: " << endl;
        cout << "{1: FireWizard} {2: ...} {3: ...}" << endl;
        cout << endl;
        cin >> input_subclass;

        if (input_subclass == 1){
            cout << "Please enter a name: ";
            cin >> player_name;
            player = new FireWizard(player_name);

        } else {
            cout << "Invalid input! Exiting..." << endl;
            delete barb;
            return 1;
        }

    } else {
        cout << "Invalid input! Exiting..." << endl;
        delete barb;
        return 1;
    }

    // Ensure player was created successfully
    if (player == NULL) {
        cout << "Failed to create player. Exiting..." << endl;
        delete barb;
        return 1;
    }

    Barbarian opponent("Bo");
    int round = 1;

    cout << "Subclass: " << player->get_subclass() << endl;
    sleep(3);
    system("clear");

    while(player->get_health() > 0 && opponent.get_health() > 0) {   
        cout << endl;
        cout << "-------------------------------------" << endl;
        cout << "Round " << round << "!" << endl;
        cout << "Player health: " << player->get_health() << " | Opponent health: " << opponent.get_health() << endl;
        cout << "Player stamina: " << player->get_stamina() << endl;
        cout << "Which action would you like to take?" << endl;
        cout << endl;
        cout << "{0: End Game Early} {1: Basic Attack (no stamina)} {2: " << player->get_ability1() << " (" << player->get_abilityCost() << " stamina)}" << endl;
        cout << "{3: " << player->get_ability2() << " (" << player->get_ability2Cost() << " stamina)}" << endl;

        int attack_input;
        cin >> attack_input;

        if (attack_input == 1 || attack_input == 2 || attack_input == 3 || attack_input == 0){
            switch (attack_input){
                case 0:
                    cout << "Exiting game... " << endl;
                    delete player;
                    delete barb;
                    exit(0);

                case 1:
                    player->basic_attack(&opponent);
                    player->set_stamina(player->get_stamina() + 15);
                    cout << endl;
                    break;

                case 2:
                    if (player->get_abilityCost() > player->get_stamina()){
                        cout << "Not enough stamina! Resting..." << endl;
                        cout << endl;
                        player->set_stamina(player->get_stamina() + 25);
                    } else {
                        player->ability1(&opponent, player->get_abilityCost());
                        cout << endl;
                    }
                    break;

                case 3:
                    if (player->get_ability2Cost() > player->get_stamina()){
                        cout << "Not enough stamina! Resting..." << endl;
                        cout << endl;
                        player->set_stamina(player->get_stamina() + 25);
                    } else {
                        player->ability2(&opponent, player->get_ability2Cost());
                        cout << endl;
                    }
                    break;
            }

            if(opponent.get_health() > 0){
                sleep(1);
                if (opponent.dice_roll() > 13 && (opponent.get_stamina() >= opponent.get_abilityCost())){
                    cout << "Opponent uses an ability attack!" << endl;
                    opponent.ability1(player, opponent.get_abilityCost());
                } else {
                    opponent.basic_attack(player);
                }
            }

            if(player->get_burnCounter() > 0 ){
                player->take_damage(barb->burn_damage);
                cout << player->get_name() << " burns for " << barb->get_burnDamage() << " damage."<< endl;
                player->set_burnCounter(player->get_burnCounter()-1);
                cout << player->get_name() << " is burning for " << player->get_burnCounter() << " more round(s)" << endl;
            }

            if(player->get_burnCounter() == 0){
                player->is_burning(0);
            }

            if(opponent.get_burnCounter() > 0){
                opponent.take_damage(barb->burn_damage);
                cout << opponent.get_name() << " burns for " << barb->get_burnDamage() << " damage."<< endl;
                opponent.set_burnCounter(opponent.get_burnCounter()-1);
                cout << opponent.get_name() << " is burning for " << opponent.get_burnCounter() << " more round(s)." << endl;
            }

            if(opponent.get_burnCounter() == 0){
                opponent.is_burning(0);
            }

            if(player->get_health() <= 0){
                cout << opponent.get_name() << " wins!" << endl;
            } else if (opponent.get_health() <= 0){
                cout << player->get_name() << " wins!" << endl;
            }

            round++;
        } else {
            cout << "Invalid input! Please enter the number of the corresponding ability: ";
        }
        sleep(3);
    }

    delete player;
    delete barb;
    return 0;
}

