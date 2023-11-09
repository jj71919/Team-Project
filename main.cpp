#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Player.h"
#include "Team.h"
using namespace std;

bool operator < (const Player& lhs, const Player& rhs) {
    return lhs.getCountry() < rhs.getCountry();
}

bool operator > (const Player& lhs, const Player& rhs) {
    return lhs.getCountry() > rhs.getCountry();
}


template <typename TYPE>
void bubbleSort(vector<TYPE> &z, int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (z.at(j) > z.at(j+1)) {
                swap(z.at(j), z.at(j+1));
                swapped = true;
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

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
    vector<Player> players;
    int rank, points;
    string lastName, firstName, country;
    while(!inFile.eof()){
        inFile >> rank >> lastName >> firstName >> country >> points;
        Player aPlayer(rank, lastName, firstName, country, points);
        players.push_back(aPlayer);
        
    }
    int x = players.size();
    bubbleSort(players,x);
    int i = 0;
    string currCountry = players.at(0).getCountry();
    Team myTeam(currCountry);
    for(i = 1; i < players.size() ; i++){
        //players.at(i).display();
        if(players.at(i).getCountry() == currCountry){
            myTeam.addPlayer(players.at(i));
        }else{
            currCountry = players.at(i).getCountry();
            Team myTeam(currCountry);
            //Add new team to  TEAM vector here
            myTeam.addPlayer(players.at(i));
        }
        
    }
    //Make vector of teams
    //every time u make team add to vector and increase counter
    
}
