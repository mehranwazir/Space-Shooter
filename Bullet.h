#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

using namespace sf;



class Bullet
{
public:
Texture b;
Sprite bullet;
bool fired;
bool leftUp, rightUp, leftDown, rightDown; // if the player move in these direction

// For the PowerUp Add on
bool slightRight, moreRight;
bool slightLeft , moreLeft;

Bullet();

Bullet(float x  , float y);

void set_Position(float x, float y);

void set_Texture(std::string png_path, float x, float y);

void update(float move_x, float move_y);



};


#endif
