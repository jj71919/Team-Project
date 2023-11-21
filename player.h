// Player.cpp
// Matthew Keeler and Joe LaBarbera

// This program creates a default constructor and the display sequence
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

// Default that will put variables into the Player object
Player::Player(int rank, string lastName, string firstName, string country, int points){
    mrank = rank;
    mlastName = lastName;
    mfirstName = firstName;
    mcountry = country;
    mpoints = points;
}
Player::Player(){
    
}
// Print method that will dispay the player object and corresponding variables
void Player::display(){
    cout << mfirstName << " " << mlastName << " " << mrank << " " << mcountry << " " << mpoints <<endl;
}
void Player::addPoints(int value){
    mpoints += value;
}

Player::Player(const Player &pPlayer){
    this->mrank = pPlayer.mrank;
    this->mfirstName = pPlayer.mfirstName;
    this->mlastName = pPlayer.mlastName;
    this->mcountry = pPlayer.mcountry;
    this->mpoints = pPlayer.mpoints;
}

