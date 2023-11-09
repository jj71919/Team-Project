#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    string enteredFirstName;
    fstream inFile;
    inFile.open("WomensSinglesSorted.txt");
    if(!inFile.is_open()){
        cout << "File is not open!" << endl;
        return 1;
    }
    //Create a vector that can hold player objects
    //Adds text from file into vector
    vector<Player> USA;
    vector<Player> players;
    int rank, points;
    string lastName, firstName, country;
    while(!inFile.eof()){
        inFile >> rank >> lastName >> firstName >> country >> points;
        Player aPlayer(rank, lastName, firstName, country, points);
        if(country == "USA"){
            USA.push_back(aPlayer);
        }
    }
    int i = 0;
    for(i = 0; i < USA.size() ; i++){
        USA.at(i).display();
    }
}

