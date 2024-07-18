#ifndef PLAYERDATA_H
#define PLAYERDATA_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace sf;



class PlayerData
{
    private:
    string PlayerName;
    int HighScore;

 
  public:

void setPlayerName(string name);

string getPlayerName()const;

void setHighScore(int score);

int getHighScore()const; 

void SaveData(const string& fileName);

};


#endif
