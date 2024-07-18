#include "PowerUp.h"

PowerUp::PowerUp()
{
 tex.loadFromFile("img/PowerUp.png");
 sprite.setTexture(tex);
 sprite.setScale(0.08,0.08);
 available = true;
 TimeGenerated = false;
}

bool PowerUp::Available() 
{
return available;
}


Sprite& PowerUp::getSprite() 
{
 return sprite;
}


void PowerUp::RandomTimeGenerate() 
{
  delay = rand() % 30 + 20;

  } 

float PowerUp::getDelay() 
{
    return delay;
}

void PowerUp::update()
{
    sprite.move(0,0.2);
}

bool PowerUp::getTimeBool() 
{
 return TimeGenerated;
}

void PowerUp::setTimeBool(bool set) {
TimeGenerated = set;

}
