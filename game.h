#ifndef GAME_H
#define GAME_H

//#include <SFML/Graphics.hpp>
//#include <time.h>
#include <iostream>
using namespace std;

#include <SFML/Audio.hpp>
using namespace sf;

#include "Bullet.h"
#include "bomb.h"
#include "Levels.h"
#include "PlayerData.h"

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;


class Add_On;
class Enemy;
class Player;

class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player
//Bullet *bullet;
Bullet bullet[100];


int bulletCount;
bool pressed;
Enemy *enemy[16]; 

Bomb bomb[14]; //Bomb

//========== Add Ons =========
Add_On *life;
Add_On *danger;
Add_On *fire;
Add_On *powerUp;
Levels levels;
int SCORE;
//============SHOOT SOUND=========
SoundBuffer buffer;
Sound sound;
//=============================

//==========MUSIC==============
Music music;
//=============================


//==========DESTROY SPRITES SHEET====
Texture texture;
Sprite animation;
//IntRect rectSourceSprite;
//===================================


Font font;
Text text;

Font Score_font;
Text Score_text;

Font lives_font;
Text lives_text;

Font GameOver_font;
Text GameOver_text;

Font YourScore_font;
Text YourScore_text;

Text playerName;
string inputName;
bool NameEntered;
bool DataSaved;
Text YourName;
PlayerData playerData;

// Texture phase1_tex, phase2_tex,phase3_tex;
// Sprite phase1_back, phase2_back, phase3_back;

Game();

void start_game(RenderWindow &window);

};

bool checkifEnemyDestroyed(Enemy **enemy);

#endif

