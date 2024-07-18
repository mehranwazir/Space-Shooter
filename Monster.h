#ifndef MONSTER_H
#define MONSTER_H

#include "enemy.h"

#include<iostream>
using namespace std;


class Bullet;
class Bomb;


class Monster:public Enemy
{

private:
Texture texture, light;
Sprite sprite, lightning;


bool fire;
bool right,left;

public:
float delay;
bool Spawned;
float SpawnTime;

SoundBuffer buffer1;
Sound sound1;

SoundBuffer buffer2;
Sound sound2;

bool Play1;
bool Play2;

Monster();

void update();

 void destroy(float x, float y, Bullet *b, int &score, int &level) override;

 void SetPosition(float x, float y) override;

 Sprite& GetSprite() override ;

 bool hit() override;

 void setHit(bool h) override;

 void bomb(Bomb *b, float &timer, float &time, int level) override;
void MonsterOrDragon_Attack(Player *p, float &time, int &score);

 Bomb* getbomb() override;

 Sprite& GetDamageSprite() override;

bool MD_Spawned();

void setMD_Spawned(bool Spawn) ;
void DisplayMD(float time);

void DragonFire(float x, float y, float time, int &score, Player *p) override;
void AddOndestroy(float x, float y, Bullet *b,int &score, int &level);
};
#endif