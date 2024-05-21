#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Variables
    string player_name = "Barry"; //Replace the "Barry" with the actual input from the player
    int XP = 10; //Default XP value to be gained after every battle.

    //Open file and pull name and XP
    ifstream infile("stats.txt");  //Opens the file stats.txt to retrieve data
    if (infile.is_open()) {
        infile >> player_name;  //Retrieve the name stored in stats.txt
        infile >> XP;   //Retrieve the XP value stored in stats.txt

        infile.close();  // Closes stats.txt
        // Print name and XP
        cout << "Data read from stats.txt:" << endl;
        cout << "Name: " << player_name << endl;
        cout << "XP: " << XP << endl;
    } else {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    //Update XP stat
    XP = XP + 10;


    // Write data to stats.txt
    ofstream outfile("stats.txt"); //Opens stats.txt to send data to file
    if (outfile.is_open()) {

        //Overwrites values inside stats.txt
        outfile << player_name << endl;
        outfile << XP << endl;

        outfile.close(); // Close file
        cout << "Data saved to stats.txt." << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    return 0;
}