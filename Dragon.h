#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"


class Bomb;
class Bullet;
class Player;

class Dragon:public Enemy
{

private:
Texture texture, fire_tex;
Sprite sprite, fire_sprite;


bool fire;


public:
bool Spawned;
float SpawnTime;
float delay;

Dragon();

void update();

 void destroy(float x, float y, Bullet *b, int &score, int &level) override;


void DragonFire(float x, float y, float time, int &score, Player *p) override;


 void SetPosition(float x, float y) override;

 Sprite& GetSprite() override; 

 bool hit() override;

 void setHit(bool h) override;

 void bomb(Bomb *b, float &timer, float &time, int level) override;

 Bomb* getbomb() override;

 Sprite& GetDamageSprite() override;
 
void MonsterOrDragon_Attack(Player *p, float &time, int &score)
{

}

 bool MD_Spawned();

void DisplayMD(float time);

 void setMD_Spawned(bool Spawn); 

 void AddOndestroy(float x, float y, Bullet *b,int &score, int &level);

};

#endif