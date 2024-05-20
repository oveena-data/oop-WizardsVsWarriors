#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Variables
    string player_name = "Barry";
    int XP = 10;

    //Open file and pull name and XP
    ifstream infile("stats.txt");
    if (infile.is_open()) {
        infile >> player_name;
        infile >> XP;

        infile.close();
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
    ofstream outfile("stats.txt");
    if (outfile.is_open()) {

        outfile << player_name << endl;
        outfile << XP << endl;

        outfile.close();
        cout << "Data saved to stats.txt." << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    return 0;
}