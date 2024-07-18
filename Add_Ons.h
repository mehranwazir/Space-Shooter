#ifndef ADDONS_H
#define ADDONS_H

#include <SFML/Graphics.hpp>
using namespace sf;


class Add_On
{

public:
virtual void RandomTimeGenerate() = 0;
virtual bool getTimeBool()=0;
virtual void setTimeBool(bool set)=0;
virtual float getDelay() = 0;
virtual void update() = 0;
virtual bool Available()=0;
virtual Sprite& getSprite()=0;

};

#endif

