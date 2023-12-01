#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
//Main.cpp
//Matthew Keeler and Joe LaBarbera
using namespace std;
// Overloaded Operators
bool operator < (const Player& lhs, const Player& rhs) {
    return lhs.getLastName() < rhs.getLastName();
}
bool operator < (const Player& lhs, const  string& rhs) {
    return lhs.getLastName() < rhs;
}
bool operator > (const string& lhs, const Player& rhs) {
    return lhs > rhs.getLastName();
}
bool operator > (const Player& lhs, const Player& rhs) {
    return lhs.getLastName() > rhs.getLastName();
}
bool operator > (const Player& lhs, const string& rhs) {
    return lhs.getLastName() > rhs;
}
bool operator <= (const Player& lhs, const  string& rhs) {
    return lhs.getLastName() <= rhs;
}
bool operator == (const Player& lhs, string rhs) {
    return lhs.getLastName() == rhs;
}

//RECURSIVE BINARY SEARCH
template <typename TYPE>
int binarySearch(vector<TYPE> &v,string name,int low,int high){
    int mid;
    if (high >= low){
        mid = (high+low)/2;
    }else{
        return -1;
    }
    if(v.at(mid) == name){
        return mid;
    }else if(v.at(mid) > name){
        return binarySearch(v, name, low, mid - 1);
    }else{
        return binarySearch(v, name, mid + 1, high);
    }
    return -1;
}
//BUBBLESORT to sort players
template <typename TYPE>
void bubbleSort(vector <TYPE> &v, int size){
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (v.at(j) > v.at(j+1)) {
                swap(v.at(j), v.at(j+1));
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
}

int main(int argc, char *argv[]){
    // Overloaded operators
    bool operator <(const Player &lhs,const Player &rhs);
    bool operator ==(const Player &lhs, string rhs);
    // Open and make sure file has been opened using command line argument
    string input;
    string enteredLastName;
    string fileName = argv[1];
    fstream inFile;
    inFile.open(fileName);
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
    // Call the bubbleSort on the players vector
    bubbleSort(players, players.size());
    
    //Initialize values to use for the binary search
    int low = 0;
    int high = players.size()-1;
    int mid = (high+low)/2;
    
    // Prompt user to enter a last name, if not "QUIT", then look for player in players using search function "look"
    cout << "Enter a last name in all caps (or 'QUIT' to exit): ";
    cin >> enteredLastName;
    
    // Loop so if not "QUIT", then look for player in players using search function "look" and repeat process until "QUIT"
    while (enteredLastName != "QUIT") {
        int low = 0;
        int high_num = players.size()-1;
        int foundIndex = binarySearch(players, enteredLastName, 0, players.size());
        if(foundIndex >=0) {
            cout << players[foundIndex]; // use cout to display the player
        }
        // Message if the player name was not found in the list
        else
           cout << "Player " << enteredLastName << " NOT found" << endl;
        cout << "Enter a last name in all caps (or 'QUIT' to exit): ";
        cin >> enteredLastName;
    }
    cout << "You have quit the program" << endl;
    }

  

  
