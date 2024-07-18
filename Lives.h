#ifndef LIVES_H
#define LIVES_H


#include <SFML/Graphics.hpp>
using namespace std;

#include "Add_Ons.h"

class Lives:public Add_On
{
private:
Texture tex;
Sprite sprite;
bool available;
float delay;
bool TimeGenerated;

public:


Lives();

bool Available() override;

Sprite& getSprite() override;


void RandomTimeGenerate() override;

float getDelay() override;

void update();

bool getTimeBool() override;

void setTimeBool(bool set) override;


};


#endif
