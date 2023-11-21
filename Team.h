#ifndef Team_h
#define Team_h
#endif
#include <iostream>
#include <string>
#include "Player.h"
#pragma once
using namespace std;

class Team{
    
public:
    Team();
    Team(string country);
    Team(string,int,vector<Player>*);
    void display();
    void addPlayer(Player);
    string getCountry() const{
        return this->country;
    };
    int getNumPlayers() const{
        return numPlayers;
    }
    vector<Player> getTeamPlayer(){
        return *teamPlayers;
    }
    void setPlayer(int index, vector<Player> vectPlayers){
        teamPlayers->at(index).setPoints( vectPlayers.at(index).getPoints());
    }
    
    
    //void addPointsToPlayer(string,string,int);
    
    Team(const Team& other) {
            country = other.country;
            numPlayers = other.numPlayers;
            teamPlayers = new vector<Player>(*other.teamPlayers);
        }
    
        ~Team() {
            delete teamPlayers;
        }
    
    
private:
    string country;
    int numPlayers;
    vector<Player> *teamPlayers;
};
