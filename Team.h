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
    Team(string,int,vector<Player>*);
    void display();
    void add(Player);
    
private:
    string country;
    int numPlayers;
    vector<Player> *teamPlayers;
};

