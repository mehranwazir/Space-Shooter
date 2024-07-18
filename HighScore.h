#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace sf;



class HighScore
{
public:

Texture bg;
Sprite background;


Texture rank_texture[3];
Sprite rank_sprite[3];

Text playerText[3];
Font font;

HighScore();

void LoadPlayerData();

void highscore(RenderWindow &window);

};





#endif