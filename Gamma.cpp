#include "Gamma.h"
#include "bomb.h"
#include "Bullet.h"

Gamma::Gamma()
{

tex.loadFromFile("img/enemy_3.png");
sprite.setTexture(tex);

damage.loadFromFile("img/explosion.png");
animation.setTexture(damage);
animation.setScale(0.45,0.45);


 buffer.loadFromFile("Digital_SFX_Set/Destroy.wav");
  sound.setBuffer(buffer);
  sound.setVolume(25);

sprite.setScale(0.30,0.30);
h = true;
delay = 2;
}

Sprite& Gamma::GetDamageSprite()
{
  return animation;
}

void Gamma::destroy(float x, float y, Bullet *b, int &score, int &level)
{
 //if(x == sprite.getGlobalBounds().width && y == sprite.getGlobalBounds().height)
 

 /*
 if(x >= sprite.getGlobalBounds().left && 
    x <= sprite.getGlobalBounds().left + sprite.getGlobalBounds().width &&  
    y <= sprite.getGlobalBounds().top + sprite.getGlobalBounds().height)
{
 //cout<<"Bullet HIt the target)"<<endl;
 sound.play();
 b->fired = false;
 h = false;

 animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);

 }
 */

FloatRect enemyBox = sprite.getGlobalBounds();
FloatRect bulletBox = b->bullet.getGlobalBounds();

     if(bulletBox.intersects(enemyBox) )
     {
       sound.play();
      b->fired = false;
      h = false;
      score += level * 30;
      animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);

     }

}





 bool Gamma::hit() 
 {
  return h;
 }
 
 
 void Gamma::setHit(bool h) 
 {
  this->h = h;
 }
 
void Gamma::SetPosition(float x, float y) 
{ 
 sprite.setPosition(x,y);
}


Sprite& Gamma::GetSprite() 
{
 return sprite;
}


void Gamma::bomb(Bomb *bomb, float &timer,float &time, int level) 
{
 b = bomb;
  
  static int t=0;
 
  if(!b->fired)
  t = timer + delay;
  
  

  if(!b->fired && h) //if bomb is not fired
   {
   b->SetPosition(sprite.getPosition().x+20, sprite.getPosition().y+35);
   b->fired = true;
   }
   
   float x = 0.0;
   float y;

   if(level == 1)
   y = 0.2;

   else if(level == 2)
   y = 0.25;
   
   else if(level == 3)
   y = 0.35;
  
  //if(b->fired )
  b->update(x,y); 
  
   if(b->sprite.getPosition().y > 680 && timer>t )
   b->fired = false;

  
}

Bomb* Gamma::getbomb() 
{
  return b;
}

void Gamma::update()
{

}

void Gamma::DragonFire(float x, float y, float time,int &score, Player *p)  {}
bool Gamma::MD_Spawned(){}
void Gamma::setMD_Spawned(bool Spawn) {}
void Gamma::DisplayMD(float time){}

void Gamma::AddOndestroy(float x, float y, Bullet *b,int &score, int &level){
   FloatRect enemyBox = sprite.getGlobalBounds();
  FloatRect bulletBox = b->bullet.getGlobalBounds();

     if(bulletBox.intersects(enemyBox) && h)
     {
       sound.play();
       //b->fired = false;
       h = false;
      animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);
     score += level * 30;   
     }
}
