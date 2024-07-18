#include "Monster.h"
#include "Bullet.h"
#include "player.h"

Monster::Monster()
{
    texture.loadFromFile("img/monster.png");
    sprite.setTexture(texture);
    light.loadFromFile("img/PNG/Lasers/blue2.png"); //PNG/Lasers/laserRed02.png");
    lightning.setTexture(light);
    lightning.setScale(1,1.20);
    lightning.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width/2 - 110, sprite.getPosition().y + sprite.getGlobalBounds().height-30);
    
    delay = 0;
    SpawnTime = 0;
    fire = true;
    sprite.setPosition(200,50);
    right = true;
    left = false;
    sprite.setScale(0.15,0.15);
    Spawned = false;

  buffer1.loadFromFile("1.wav");
  sound1.setBuffer(buffer1);
  sound1.setVolume(60);

  buffer2.loadFromFile("2.wav");
  sound2.setBuffer(buffer2);
  sound2.setVolume(60);
    
    Play1 = true;
    Play2 = false;
}

void Monster::update()
{

if(right )
{
    sprite.move(0.1,0);
    if(sprite.getPosition().x >= 500 - sprite.getGlobalBounds().width)
    {
    right = false;
    left = true;
    }
}

else if(left)
{
    
    sprite.move(-0.1,0);
    if(sprite.getPosition().x <= 0)
     {
        right = true;
        left = false;
     }
}


}

 void Monster::destroy(float x, float y, Bullet *b, int &score, int &level) 
{

FloatRect monsterBox = sprite.getGlobalBounds();
FloatRect bulletBox = b->bullet.getGlobalBounds();

if(bulletBox.intersects(monsterBox))
b->fired = false;

}

 void Monster::SetPosition(float x, float y) 
{

}

 Sprite& Monster::GetSprite()  
{
return sprite;
}

 bool Monster::hit() 
{
return fire;
}

 void Monster::setHit(bool h) 
{

}

 void Monster::bomb(Bomb *b, float &timer, float &time, int level) 
{

// if(delay >= 2.0)      //Two seconds delay meaning after every two seconds the monster will fire the lightning beam
// {
   
//     //cout<<"beam fired"<<endl;
//      lightning.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width/2 - 110, sprite.getPosition().y + sprite.getGlobalBounds().height-30);
//      fire = true;
    
//      if(Play1)
//      {
//      //sound1.stop();
//      sound2.play();
//      Play1 = false;
//      }
//     if(delay >= 4.0)   //The monster will fire the lightning beam for 2 seconds and then will stop
//     { 
//         //cout<<"beam stopped"<<endl;
//         fire = false;
//         delay = 0;
//         Play2 = true;
//     }
// }
// else if(Play2)
// {
//   //sound2.stop();
//   sound1.play();
//   Play2 = false;
// }


// delay += time;

// if(delay >= 2.0  && delay <= 2.05)
// Play1 = true;
// //cout<<delay<<endl;
}

void Monster::MonsterOrDragon_Attack(Player *p, float &time, int &score)
{


if(delay >= 2.0)      //Two seconds delay meaning after every two seconds the monster will fire the lightning beam
{
   
    //cout<<"beam fired"<<endl;
     lightning.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width/2 - 110, sprite.getPosition().y + sprite.getGlobalBounds().height-30);
     fire = true;
    
     bool updateScore = true;

     if(p->hit)
     updateScore = false;

     if(Play1)
     {  
     sound2.play();
     Play1 = false;
     }
    if(delay >= 4.0)   //The monster will fire the lightning beam for 2 seconds and then will stop
    { 

        if(updateScore && fire)
        score += 40;

        fire = false;
        delay = 0;
        Play2 = true;
    }
}
else if(Play2)
{
  //sound2.stop();
  sound1.play();
  Play2 = false;
}


delay += time;

if(delay >= 2.0  && delay <= 2.05)
Play1 = true;
//cout<<delay<<endl;


}

 Bomb* Monster::getbomb() 
{

}

 Sprite& Monster::GetDamageSprite() 
{
return lightning;
}

bool Monster::MD_Spawned()
{
 return Spawned;
}

void Monster::setMD_Spawned(bool Spawn) 
{
    Spawned = Spawn;
}
void Monster::DisplayMD(float time)
{

if(SpawnTime <= 15.0)
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

void Monster::DragonFire(float x, float y, float time, int &score, Player *p)  {}
void Monster::AddOndestroy(float x, float y, Bullet *b,int &score, int &level){}
