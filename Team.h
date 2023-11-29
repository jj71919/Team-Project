#ifndef Team_h
#define Team_h
#endif
#include <iostream>
#include <string>
#include "Player.hpp"
#pragma once
using namespace std;

class Team{
    
public:
    Team();
    Team(string country);
    Team(string,int,vector<Player>*);
    void display();
    void addPlayer(Player&);
    void setCountry(string);
    void clearPlayers();
    Team(const Team& other);
    ~Team();
    
    string getCountry() const{
        return this->country;
    };
    
    int getNumPlayers() const{
        return numPlayers;
    }
    
    Player* getTeamPlayer(){
        return teamPlayers;
    }
    
    void setPlayer(int index, const Player& player) {
            if (index >= 0 && index < numPlayers) {
                teamPlayers[index] = player;
            }
        }

private:
    string country;
    int numPlayers;
    Player* teamPlayers;
};

