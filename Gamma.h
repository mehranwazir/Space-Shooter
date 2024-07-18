#ifndef GAMMA_H
#define GAMMA_H


#include "enemy.h"


class Bomb;
class Bullet;

//GAMMA
class Gamma: public Invaders
{

public:

Gamma();

Sprite& GetDamageSprite();

void destroy(float x, float y, Bullet *b, int &score, int &level)override;


 bool hit() override;
 
 
 void setHit(bool h) override;
 
void SetPosition(float x, float y) override;


Sprite& GetSprite() override;


void bomb(Bomb *bomb, float &timer,float &time, int level) override;
Bomb* getbomb() override;

void update()override;

void DragonFire(float x, float y, float time, int &score, Player *p) override;
bool MD_Spawned();
void setMD_Spawned(bool Spawn); 
void DisplayMD(float time);

void AddOndestroy(float x, float y, Bullet *b,int &score, int &level);
void MonsterOrDragon_Attack(Player *p, float &time, int &score){}
private:
Sprite sprite;
Texture tex;
bool h;
Bomb *b;
float delay;
SoundBuffer buffer;
Sound sound;
Texture damage;
Sprite animation;
};
#endif