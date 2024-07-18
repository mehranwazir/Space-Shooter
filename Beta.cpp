#include "Beta.h"
#include "bomb.h"
#include "Bullet.h"

Beta::Beta()
{

tex.loadFromFile("img/enemy_2.png");
sprite.setTexture(tex);

damage.loadFromFile("img/explosion.png");
animation.setTexture(damage);
animation.setScale(0.45,0.45);


 buffer.loadFromFile("Digital_SFX_Set/Destroy.wav");
  sound.setBuffer(buffer);
  sound.setVolume(25);
  
  
sprite.setScale(0.40,0.40);
h = true;
delay = 3;
}

Sprite& Beta::GetDamageSprite()
{
  return animation;
}

void Beta::destroy(float x, float y, Bullet *b, int &score, int &level)
{
 //if(x == sprite.getGlobalBounds().width && y == sprite.getGlobalBounds().height)
 
 /*
 if(x >= sprite.getGlobalBounds().left && 
    x <= sprite.getGlobalBounds().left + sprite.getGlobalBounds().width &&  y >= sprite.getGlobalBounds().top && 
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
      score += level * 20;
      animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);

     }


}





 bool Beta::hit() 
 {
  return h;
 }


 void Beta::setHit(bool h) 
 {
  this->h = h;
 }
 
void Beta::SetPosition(float x, float y) 
{ 
 sprite.setPosition(x,y);
}


Sprite& Beta::GetSprite() 
{
 return sprite;
}

void Beta::bomb(Bomb *bomb, float &timer,float &time, int level) 
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

Bomb* Beta::getbomb() 
{
  return b;
}

void Beta::update()
{

}
void Beta::DragonFire(float x, float y, float time,int &score, Player *p)  {}
bool Beta::MD_Spawned(){}
void Beta::setMD_Spawned(bool Spawn) {}
void Beta::DisplayMD(float time){}
void Beta::AddOndestroy(float x, float y, Bullet *b,int &score, int &level)
{
 FloatRect enemyBox = sprite.getGlobalBounds();
  FloatRect bulletBox = b->bullet.getGlobalBounds();

     if(bulletBox.intersects(enemyBox) && h)
     {
       sound.play();
       //b->fired = false;
       h = false;
      animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);
     score += level * 20;   
     }

}