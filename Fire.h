#ifndef FIRE_H
#define FIRE_H

#include "Add_Ons.h"



class Fire:public Add_On
{

private:
Texture tex;
Sprite sprite;
bool available;
float delay;
bool TimeGenerated;


public:


Fire();
bool Available() override;

Sprite& getSprite() override;

void RandomTimeGenerate() override;
float getDelay() override;
void update();
bool getTimeBool() override;
void setTimeBool(bool set) override;



};

#endif