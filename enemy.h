#ifndef ENEMY_H
#define ENEMY_H



#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Bullet;
class Bomb;
class Player;

class Enemy
{

public:


virtual void destroy(float x, float y, Bullet *b, int &score, int &level) = 0;

virtual void AddOndestroy(float x, float y, Bullet *b,int &score, int &level) = 0;
virtual void MonsterOrDragon_Attack(Player *p, float &time, int &score) = 0;

virtual void SetPosition(float x, float y) = 0;
virtual Sprite& GetSprite() = 0;
virtual bool hit() = 0;
virtual void setHit(bool h) = 0;
virtual void bomb(Bomb *b, float &timer, float &time, int level) = 0;
virtual Bomb* getbomb() = 0;

virtual Sprite& GetDamageSprite() = 0;

virtual void update() = 0;

virtual void DragonFire(float x, float y, float time, int &score, Player *p) = 0;
virtual bool MD_Spawned() = 0;
virtual void setMD_Spawned(bool Spawn) = 0;
virtual void DisplayMD(float time) = 0;
};



class Invaders: public Enemy
{

public:
virtual void destroy(float x, float y, Bullet *b,int &score, int &level) = 0;
virtual void SetPosition(float x, float y) = 0;



};


// bool checkifEnemyDestroyed(Enemy **enemy)
// {
//  for(int i=0; i<14; i++)
//  if(enemy[i]->hit())
//  return false;

// return true;
// }


#endif


