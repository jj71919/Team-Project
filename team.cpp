#include <string>
#include <vector>
#include <stdio.h>
#include "Player.h"
#include "Team.h"



Team::Team(string country){
    this->country = country;
    this->numPlayers = 0;
    teamPlayers = new vector<Player>();
}

void Team::clearPlayers(){
    teamPlayers = new vector<Player>();
 }

void Team:: addPlayer(Player aPlayer){
    this->teamPlayers->push_back(aPlayer);
    this->numPlayers++;
}

void Team::display(){
    cout << "Team name: " << country <<  endl;
    for(int i =0; i < teamPlayers->size(); i++){
        teamPlayers->at(i).display();
    }
}

Team::Team(const Team& other) {
    this->country = other.country;
    this->numPlayers = other.numPlayers;
    this->teamPlayers = other.teamPlayers;
    //this->teamPlayers = new vector<Player>();
        /*for (int i = 0; i < other.teamPlayers->size(); i++) {
            Player copiedPlayer = other.teamPlayers->at(i);
            this->teamPlayers->push_back(copiedPlayer);
        }
         */
    
}
    
Team::~Team() {
    delete teamPlayers;
}

void Team::setCountry(string nCountry){
    this->country = nCountry;
}


