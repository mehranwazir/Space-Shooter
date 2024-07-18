
#include "Alpha.h"
#include "bomb.h"
#include "Bullet.h"

Alpha::Alpha()
{

tex.loadFromFile("img/enemy_1.png");
sprite.setTexture(tex);

damage.loadFromFile("img/explosion.png");
animation.setTexture(damage);
animation.setScale(0.45,0.45);


  buffer.loadFromFile("Digital_SFX_Set/Destroy.wav");
  sound.setBuffer(buffer);
  sound.setVolume(25);
            
sprite.setScale(0.45,0.45);
h = true;
b = nullptr;
delay = 5;
}
Sprite& Alpha::GetDamageSprite()
{
  return animation;
}

void Alpha::destroy(float x, float y, Bullet *b, int &score, int &level)
{


FloatRect enemyBox = sprite.getGlobalBounds();
FloatRect bulletBox = b->bullet.getGlobalBounds();

     if(bulletBox.intersects(enemyBox) )
     {
       sound.play();
       b->fired = false;
       h = false;

      animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);
       
       score += level * 10; 
     }

}




 bool Alpha::hit() 
 {
  return h;
 }
 
 void Alpha::setHit(bool h) 
 {
  this->h = h;
 }

void Alpha::SetPosition(float x, float y) 
{ 
 sprite.setPosition(x,y);
}


Sprite& Alpha::GetSprite() 
{
 return sprite;
}

void Alpha::bomb(Bomb *bomb, float &timer,float &time, int level) 
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
  
  
  if(b->fired  )
  b->update(x,y); 
  
   if(b->sprite.getPosition().y > 680 && timer>t )
   b->fired = false;

}


Bomb* Alpha::getbomb() 
{
  return b;
}

void Alpha::update()
{

}

void Alpha::DragonFire(float x, float y, float time, int &score, Player *p) {}
bool Alpha::MD_Spawned(){}
void Alpha::setMD_Spawned(bool Spawn) {}
void Alpha::DisplayMD(float time){}
void Alpha::AddOndestroy(float x, float y, Bullet *b,int &score, int &level)
{

  FloatRect enemyBox = sprite.getGlobalBounds();
  FloatRect bulletBox = b->bullet.getGlobalBounds();

     if(bulletBox.intersects(enemyBox) && h)
     {
       sound.play();
       //b->fired = false;
       h = false;
      animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);
     score += level * 10;   
     }


}
