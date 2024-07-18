#ifndef LEVELS_H
#define LEVELS_H


#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;
using namespace sf;

class Levels
{
public:
//Sprite level;
//Texture l;
int phase;
int gameLevel;

Texture phase_texture[3];
Sprite phase_img[3];

Texture phase1_tex, phase2_tex,phase3_tex;
Sprite phase1_back, phase2_back, phase3_back;
bool phaseChange;

bool once;

Texture level3_Texture[8];
Sprite level3_sprites[8];

Texture l[3];
Sprite level[3];

Levels();

void DisplayLevels(Enemy **enemy, float &timer, float &t, float &bombDelay, float &time);

};




#endif