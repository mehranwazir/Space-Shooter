#ifndef MENU_H
#define MENU_H


#include "game.h"
#include "HighScore.h"


#define MAX_ITEMS 4

class Menu{
private:
Font font;
Text menu[MAX_ITEMS];
Texture b;
Sprite background;

Texture logo;
Sprite logoSprite;

Texture Instruction_tex;
Sprite Instructions;

HighScore score;

public:
static int IndexSelected;
Menu();
Menu(float width, float height);

void MoveUp();

void MoveDown();

void draw(RenderWindow &window);

void instructions(RenderWindow &window);

void display_menu();
void display_menu(RenderWindow &window);

};




#endif
