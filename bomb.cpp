#include "bomb.h"



Bomb::Bomb()
{

texture.loadFromFile("img/PNG/Lasers/laserBlue08.png");
sprite.setTexture(texture);
sprite.setScale(0.4,0.4);
fired = false;
}

void Bomb::SetTexture(std::string png_path)
{
  texture.loadFromFile(png_path);
  sprite.setTexture(texture);
  sprite.setScale(0.4,0.4);

}

void Bomb::SetPosition(float x, float y)
{
sprite.setPosition(x,y);
}


void Bomb::update(float x,float y)
{
  sprite.move(x,y);
  
}
