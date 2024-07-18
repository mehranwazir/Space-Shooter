#include "Danger.h"



Danger::Danger()
{
 tex.loadFromFile("img/Danger.png");
 sprite.setTexture(tex);
 sprite.setScale(0.1,0.1);
 available = true;
 TimeGenerated = false;
}

bool Danger::Available() 
{
return available;
}


Sprite& Danger::getSprite() 
{
 return sprite;
}


void Danger::RandomTimeGenerate() 
{
  delay = rand() % 30 + 10;

  //delay = 5;
} 

float Danger::getDelay() 
{
    return delay;
}

void Danger::update()
{
    sprite.move(0,0.2);
}

bool Danger::getTimeBool() 
{
 return TimeGenerated;
}

void Danger::setTimeBool(bool set) {
TimeGenerated = set;

}
