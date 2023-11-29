#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Player.hpp"
#include "Team.hpp"
using namespace std;

bool operator < (const Player& lhs, const Player& rhs) {
    return lhs.getCountry() < rhs.getCountry();
}

bool operator > (const Player& lhs, const Player& rhs) {
    return lhs.getCountry() > rhs.getCountry();
}

bool operator > (const Player& lhs, string input) {
    return lhs.getfirstName() > input;
}

bool operator == (const Player& lhs, string rhs) {
    return lhs.getfirstName() == rhs;
}

bool operator <= (const Player& lhs, const  string& rhs) {
    return lhs.getfirstName() <= rhs;
}


int look(vector<Player> &v,string input){
    int i;
    //Run thru vector to find player name, if name is found call function getLastname and display the player
    for(i = 0; i < v.size(); i++){
        if(v.at(i).getfirstName() == input){
            return i;
        }
    }
    return -1;
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

void addPointsToPlayer(vector<Team> &teams, string tName, string pName, int pts) {
    for (int i = 0; i < teams.size(); i++) {
        if (teams[i].getCountry() == tName) {
            Player* players = teams[i].getTeamPlayer();
            for (int z = 0; z < teams[i].getNumPlayers(); z++) {
                if (players[z].getfirstName() == pName) {
                    players[z].addPoints(pts);
                    teams[i].setPlayer(z, players[z]);
                    return;
                }
            }
        }
    }
}

void menu(){
    cout<< "Select an option" << endl;
    cout << "0. TO QUIT " << endl;
    cout << "1. Display all teams " << endl;
    cout << "2. Search for team " << endl;
    cout << "3. Search for player " << endl;
    cout << "4. Add points " << endl;
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
    
    vector<Team> teams;
    int x = players.size();
    bubbleSort(players, x);

    string currCountry = players[0].getCountry();
    Team myTeam(currCountry);
    myTeam.addPlayer(players[0]);
    for (int i = 1; i < players.size(); i++) {
        if (players[i].getCountry() == currCountry) {
            myTeam.addPlayer(players[i]);
        } else {
            teams.push_back(myTeam);
            currCountry = players[i].getCountry();
            myTeam.setCountry(currCountry);
            myTeam.clearPlayers();

            Player* tempPlayers = new Player[1];
            tempPlayers[0] = players[i];
            myTeam.setPlayer(0, tempPlayers[0]);
            delete[] tempPlayers;
        }
    }

    int numPlayers = myTeam.getNumPlayers();
    Player* tempPlayers = new Player[numPlayers];
    Player* teamPlayers = myTeam.getTeamPlayer();
    for (int i = 0; i < numPlayers; i++) {
        tempPlayers[i] = teamPlayers[i];
    }
    Team newTeam(currCountry);
    for (int i = 0; i < numPlayers; i++) {
        newTeam.addPlayer(tempPlayers[i]);
    }
    teams.push_back(newTeam);
    delete[] tempPlayers;
    /*
    vector<Team> teams;
    int x = players.size();
    bubbleSort(players,x);
    
    string currCountry = players.at(0).getCountry();
    Team myTeam(currCountry);
    myTeam.addPlayer(players.at(0));
    for(int i = 1; i < players.size() ; i++){
        if(players.at(i).getCountry() == currCountry){
            myTeam.addPlayer(players.at(i));
        }else{
            teams.push_back(myTeam);
            currCountry = players.at(i).getCountry();
            myTeam.setCountry(currCountry);
            myTeam.clearPlayers();
            myTeam.addPlayer(players.at(i));
        }
}
    
    teams.push_back(myTeam);
     */
    // Display menu
    int selection;
    menu();
    // Get user input
    cout << "Enter your choice: ";
    cin >> selection;
    while(selection != 0){
        // Switch statement
        if(selection == 1){
            cout << "Displaying all teams..." << endl;
            for(int i = 0; i < teams.size(); i++){
                teams.at(i).display();
            }
            
            cout << " " << endl;
            menu();
            cout << "Enter your choice: ";
            cin >> selection;
            
        }else if (selection == 2){
            string look;
            cout << "Searching for team..." << endl;
            cout << "Enter a country name: ";
            cin >> look;
            cout << " ";
            for(int i = 0; i < teams.size(); i++){
                if(teams.at(i).getCountry() == look){
                    teams.at(i).display();
                }
            }
            
            cout << " " << endl;
            menu();
            cout << "Enter your choice: ";
            cin >> selection;
            
        }else if (selection == 3){
            cout << "Enter a first name in all caps: ";
            cin >> enteredFirstName;
            int foundIndex = look(players, enteredFirstName);
            if(foundIndex >=0) {
                players.at(foundIndex).display();
            }else{
                cout << "Player " << enteredFirstName << " NOT found" << endl;
            }
            cout << " " << endl;
            menu();
            cout << "Enter your choice: ";
            cin >> selection;
            
        }else if (selection == 4){
            cout << "Adding points..." << endl;
            string country,name;
            int points;
            cout << "Enter Country's name(ALL CAPS) " << endl;
            cin >> country;
            cout << "Enter Players name(ALL CAPS) " << endl;
            cin >> name;
            cout << "Enter Points: " << endl;
            cin >> points;
            Team backUpteam = myTeam;
            addPointsToPlayer(teams, country, name, points);
            backUpteam.display();
            myTeam.display();
            
            cout << " " << endl;
            menu();
            cout << "Enter your choice: ";
            cin >> selection;
            
        }else if (selection == 0){
            cout << "Exiting code" << endl;
            break;
        }else{
            cout << "not a choice";
        }
    }
}
        

