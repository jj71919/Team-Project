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

void Team:: addPlayer(Player aPlayer){
    teamPlayers->push_back(aPlayer);
    numPlayers++;
}

void Team::display(){
    for(int i =0; i < teamPlayers->size(); i++){
        teamPlayers->at(i).display();
    }
}
