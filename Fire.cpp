#include "Fire.h"


Fire::Fire()
{
 tex.loadFromFile("img/Fire.png");
 sprite.setTexture(tex);
 sprite.setScale(0.08,0.08);
 available = true;
 TimeGenerated = false;
}

bool Fire::Available() 
{
return available;
}


Sprite& Fire::getSprite() 
{
 return sprite;
}


void Fire::RandomTimeGenerate() 
{
  delay = rand() % 30 + 10;

  //delay = 5;
} 

float Fire::getDelay() 
{
    return delay;
}

void Fire::update()
{
    sprite.move(0,0.2);
}

bool Fire::getTimeBool() 
{
 return TimeGenerated;
}

void Fire::setTimeBool(bool set) {
TimeGenerated = set;

}


