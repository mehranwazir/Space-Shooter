#include "Bullet.h"


Bullet::Bullet()
{
   b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
  bullet.setTexture(b);
  bullet.setScale(0.65,0.65);
  fired = false;
  leftUp = false;
  rightUp = false;
  leftDown = false;
  rightDown = false;
  slightLeft = false;
  moreLeft = false;
  slightRight = false;
  moreRight = false;
}

Bullet::Bullet(float x  , float y)
{
 // b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
 // bullet.setTexture(b);
  bullet.setScale(0.65,0.65);
  bullet.setPosition(x+35,y-20);
}

void Bullet::set_Position(float x, float y)
{

bullet.setScale(0.65,0.65);
bullet.setPosition(x+35,y-20);

}

void Bullet::set_Texture(std::string png_path, float x, float y)
{
b.loadFromFile(png_path);
bullet.setTexture(b);
bullet.setScale(x,y); 

}

void Bullet::update(float move_x, float move_y)
{   
    
   bullet.move(move_x,move_y);  
}
