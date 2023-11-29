#include <string>
#include <vector>
#include <stdio.h>
#include "Player.hpp"
#include "Team.hpp"



Team::Team(string country){
    this->country = country;
    this->numPlayers = 0;
    teamPlayers = nullptr;
}

void Team::setCountry(string nCountry){
    country = nCountry;
}

void Team::clearPlayers(){
    delete[] teamPlayers;
    teamPlayers = nullptr;
    numPlayers = 0;
 }

void Team::addPlayer(Player &aPlayer) {
    Player *temp = new Player[numPlayers + 1];
    for (int i = 0; i < numPlayers; ++i) {
        temp[i] = teamPlayers[i];
    }
    temp[numPlayers] = aPlayer;
    delete[] teamPlayers;
    teamPlayers = temp;
    numPlayers++;
}

void Team::display() {
    cout << "Team name: " << country << endl;
    for (int i = 0; i < numPlayers; ++i) {
        teamPlayers[i].display();
    }
}
/*
Team::Team(const Team& other) {
    this->country = other.country;
    this->numPlayers = other.numPlayers;
    if (other.numPlayers > 0) {
            this->teamPlayers = new Player[other.numPlayers];
            for (int i = 0; i < other.numPlayers; ++i) {
                this->teamPlayers[i] = other.teamPlayers[i];
            }
        } else {
            this->teamPlayers = nullptr;
        }
}
*/
Team::Team(const Team& other) {
    this->country = other.country;
    this->numPlayers = other.numPlayers;

    if (other.numPlayers > 0) {
        this->teamPlayers = new Player[other.numPlayers];

        // Perform a deep copy of each Player object
        for (int i = 0; i < other.numPlayers; ++i) {
            // Assuming Player class has its deep copy constructor defined
            this->teamPlayers[i] = Player(other.teamPlayers[i]); // Calls Player's copy constructor
        }
    } else {
        this->teamPlayers = nullptr;
    }
}
    
Team::~Team() {
    delete[] teamPlayers;
}





