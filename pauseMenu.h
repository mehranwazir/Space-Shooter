#ifndef PAUSEMENU_H
#define PAUSEMENU_H


#include<SFML/Graphics.hpp>
#include "HighScore.h"
//#include "menu.h"
//#include "game.h"
using namespace sf;

const int MAX_ITEMS = 5;

class PlayerData;

class pauseMenu
{

   public:
    
 Font font;
Text menu[MAX_ITEMS];
Texture b;
Sprite background;

Texture logo;
Sprite logoSprite;

HighScore score;

public:
static int IndexSelected;

pauseMenu();
pauseMenu(float width, float height);

void MoveUp();

void MoveDown();


void draw(RenderWindow &window);

 bool Display_PauseMenu(RenderWindow &window, PlayerData &playerData, int &SCORE);
};







#endif

