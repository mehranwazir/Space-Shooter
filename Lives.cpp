#include "Lives.h"



Lives::Lives()
{
 tex.loadFromFile("img/Heart.png");
 sprite.setTexture(tex);
 sprite.setScale(0.1,0.1);
 available = true;
 TimeGenerated = false;
}

bool Lives::Available() 
{
return available;
}


Sprite& Lives::getSprite() 
{
 return sprite;
}


void Lives::RandomTimeGenerate() 
{
  delay = rand() % 30 + 10;

  //delay = 5;
} 

float Lives::getDelay() 
{
    return delay;
}

void Lives::update()
{
    sprite.move(0,0.2);
}

bool Lives::getTimeBool() 
{
 return TimeGenerated;
}

void Lives::setTimeBool(bool set) 
{
TimeGenerated = set;

}
