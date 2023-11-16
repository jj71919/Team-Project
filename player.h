#ifndef Player_h
#define Player_h
#endif
#include <iostream>
#include <string>
#pragma once
using namespace std;

//Player.H
class Player{
    //public files that have default constructor
  public:
    Player();
    Player(int, string, string, string, int );
    string getLastName(){
        return mlastName;
    };
    //Getters and Setters
    string getfirstName() const{
        return mfirstName;
    }

    string getCountry() const{
        return mcountry;
    }
    
    int getPoints()const{
        return mpoints;
    }
    
    int getRank()const{
        return mrank;
    }
    
    Player operator+ (int);
    
    void display();
    
    void addPoints(int);

    //void selectionSort(vector<Player> z);
    
  private:
    //Private variables
    string mlastName;
    string mfirstName;
    string mcountry;
    int mrank;
    int mpoints;
};

      

      


