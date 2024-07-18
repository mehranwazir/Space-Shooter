#include "Dragon.h"
#include "Bullet.h"
#include "player.h"
#include <iostream>

Dragon::Dragon()
{
    texture.loadFromFile("img/dragon1.png");
    sprite.setTexture(texture);
    
    fire_tex.loadFromFile("img/PNG/Lasers/3.png"); //PNG/Lasers/laserRed02.png");
    fire_sprite.setTexture(fire_tex);
    fire_sprite.setScale(1,1.25);
    fire_sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width - 50  , sprite.getPosition().y + sprite.getGlobalBounds().height+50);  
    
    Spawned = false;
    SpawnTime = 0;
    delay = 0;
    fire = true;
    sprite.setPosition(100,20);
    sprite.setScale(1.15,1.15);
  
 
    

    
}

void Dragon::update()
{

}

 void Dragon::destroy(float x, float y, Bullet *b, int &score, int &level) 
{
    FloatRect DragonBox = sprite.getGlobalBounds();
    FloatRect bulletBox = b->bullet.getGlobalBounds();

if(bulletBox.intersects(DragonBox))
b->fired = false;

}


void Dragon::DragonFire(float x, float y, float time, int &score, Player *p) 
{

 static bool updateScore = false;
 if(x >=166 && x<= 332 && y>= 300 && delay>1)
 {
    // fire_tex.loadFromFile("img/PNG/Lasers/3.png"); //PNG/Lasers/laserRed02.png");
    // fire_sprite.setTexture(fire_tex);
    // fire_sprite.setScale(1,1.25);
    fire_sprite.setRotation(0);
    fire_sprite.setScale(1,1.25);
    fire_sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width/2 -45, sprite.getPosition().y + sprite.getGlobalBounds().height - 5);  

    //fire_sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width - 50  , sprite.getPosition().y + sprite.getGlobalBounds().height+50);  

    //fire_sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width/2 - 165, sprite.getPosition().y + sprite.getGlobalBounds().height-20);  
    delay = 0;
  
   
    updateScore = true;
 }
 else if(x>=0 && x<166 && y>= 300 && delay>1)
{
    // fire_tex.loadFromFile("img/PNG/Lasers/1new.png"); //PNG/Lasers/laserRed02.png");
    // fire_sprite.setTexture(fire_tex);
    // fire_sprite.setScale(0.85,1.75);
    
     fire_sprite.setRotation(25);
     fire_sprite.setScale(1,1.25);
     //fire_sprite.setPosition(sprite.getPosition().x - 20 + sprite.getGlobalBounds().width/2 - 210, sprite.getPosition().y + sprite.getGlobalBounds().height - 10);  
        fire_sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width/2 -45, sprite.getPosition().y + sprite.getGlobalBounds().height - 25);  

   delay = 0;
    

    updateScore = true;
}
else if(x>332 && x<=500 && y>= 300 && delay>1)
{
    // fire_tex.loadFromFile("img/PNG/Lasers/2new.png"); //PNG/Lasers/laserRed02.png");
    // fire_sprite.setTexture(fire_tex);
    // fire_sprite.setScale(0.85,1.75);

    fire_sprite.setRotation(-35);
    fire_sprite.setScale(1,1.40);
    fire_sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width/2 -40, sprite.getPosition().y + sprite.getGlobalBounds().height + 20);  

    //fire_sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width/2 - 30, sprite.getPosition().y + sprite.getGlobalBounds().height-35);  
    delay = 0;

    updateScore = true;
}

if(updateScore && !p->hit )//&& delay>=0.5)
{  //std::cout<<"A"<<endl;
    score += 50;
   updateScore = false;
}

delay += time;
}



 void Dragon::SetPosition(float x, float y) 
{

}

 Sprite& Dragon::GetSprite()  
{
return sprite;
}

 bool Dragon::hit() 
{
return fire;

}

 void Dragon::setHit(bool h) 
{

}

 void Dragon::bomb(Bomb *b, float &timer, float &time, int level) 
{

}

 Bomb* Dragon::getbomb() 
{

}

 Sprite& Dragon::GetDamageSprite()
{
return fire_sprite;
}
 


 bool Dragon::MD_Spawned()
 {
    return Spawned;
 }

void Dragon::DisplayMD(float time)
{
    if(SpawnTime <= 5.0)
{
    Spawned = true;
}
else
{
    SpawnTime = 0;
    Spawned = false;
}


SpawnTime += time;    
}

 void Dragon::setMD_Spawned(bool Spawn) 
 {
    Spawned = Spawn;
 }

 void Dragon::AddOndestroy(float x, float y, Bullet *b,int &score, int &level){}
