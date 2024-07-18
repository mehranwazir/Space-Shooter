#ifndef BOMB_H
#define BOMB_H


#include <SFML/Graphics.hpp>
using namespace sf;

class Bomb
{
public:
Sprite sprite;
Texture texture;
bool fired;

Bomb();

void SetTexture(std::string png_path);

void SetPosition(float x, float y);


void update(float x,float y);
};

#endif
