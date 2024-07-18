#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Enemy;
class Bullet;
class Lives;
class Add_On;
class Bomb;


class Player
{
public:
Texture tex;
Sprite sprite;
float speed=0.3;
int x,y;
Bullet *b;
Lives *lives; 

int numberOfLives;
bool hit;
SoundBuffer buffer;
Sound sound;


Add_On *life;
float life_delay;

Add_On *danger;
float danger_delay;

Add_On *fireAddon;
float fire_delay;

bool FireActive;

Add_On *powerUp;
float powerUp_delay;
bool PowerUpActive;

Texture destroy;
Sprite animation;



Player(std::string png_path);

void fire(Bullet *b, float time, int &count);


void destroyShip(Bomb *bomb, Enemy **enemy,float &timer);

//======life Add on==================



void life_Add_on(Add_On *Recievelife, float time,RenderWindow &window);

//====================

//=====Danger add on ===========

void Danger_Add_on(Add_On *NewDanger,float time,int &score,RenderWindow &window);

//==========================


//=====FIRE ADD ON ==============

void Fire_Add_on(Add_On *NewFire,float time,RenderWindow &window);

//=================

void PowerUp_Add_on(Add_On *NewPowerUp, float time, RenderWindow &window);


void move(std::string s);
void reset();


};


#endif
    
