#include "player.h"
#include "Bullet.h"
#include "Lives.h"
#include "enemy.h"
#include "Add_Ons.h"
#include "bomb.h"


Player::Player(std::string png_path)
{

tex.loadFromFile(png_path);
sprite.setTexture(tex);

//=====DESTROY ANIMATION=============
destroy.loadFromFile("img/explosion.png");
animation.setTexture(destroy);
animation.setScale(0.45,0.45);
//=====DESTROY ANIMATION==========

x=210;y=575;
sprite.setPosition(x,y);
sprite.setScale(0.45,0.45);
hit = false;


numberOfLives = 5;
lives = new Lives[numberOfLives];

life_delay = 0;
danger_delay = 0;

FireActive = false;
powerUp_delay = 0;
PowerUpActive = false;
}


void Player::fire(Bullet *b, float time, int &count)
{
  
 
  this->b = b;

for(int i=0; i<100; i++)
  if(this->b[i].fired && !b[i].leftUp && !b[i].rightUp  && !b[i].leftDown && !b[i].rightDown && !b[i].slightLeft && !b[i].slightRight && !b[i].moreLeft && !b[i].moreRight)
  this->b[i].update(0, -0.4);
  else if(b[i].fired && b[i].leftUp)
  this->b[i].update(-0.4,-0.4);
  else if(b[i].fired && b[i].rightUp)
  this->b[i].update(0.4,-0.4);
  else if(b[i].fired && b[i].slightLeft)
  this->b[i].update(-0.1,-0.4);
  else if(b[i].fired && b[i].moreLeft)
  this->b[i].update(-0.2,-0.4);
  else if(b[i].fired && b[i].slightRight)
  this->b[i].update(0.1,-0.4);
  else if(b[i].fired && b[i].moreRight)
  this->b[i].update(0.2,-0.4);
  else if(b[i].fired && b[i].rightDown)
  this->b[i].update(0.4,0.4); 
  else if(b[i].fired && b[i].leftDown)
  this->b[i].update(-0.4,0.4); 

for(int i=0; i<100; i++)
  if(b[i].bullet.getPosition().y < - 20 || b[i].bullet.getPosition().x < -20  && b[i].leftUp )
  {
    b[i].leftUp = false;
   // b[i].b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
   // b[i].bullet.setTexture(b[i].b);
  }
  // else if(b[i].bullet.getPosition().y < - 20 || b[i].bullet.getPosition().x < -20  &&  b[i].slightLeft )
  // {
   
  //   b[i].slightLeft = false; //For powerUp Add on
   
  //  // b[i].b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
  //  // b[i].bullet.setTexture(b[i].b);
  // }

  // else if(b[i].bullet.getPosition().y < - 20 || b[i].bullet.getPosition().x < -20  &&   b[i].moreLeft)
  // {
   
  //   b[i].moreLeft = false; //For powerUp Add on
   
  //  // b[i].b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
  //  // b[i].bullet.setTexture(b[i].b);
  // }

 else if(b[i].bullet.getPosition().y < - 20 || b[i].bullet.getPosition().x > 520  && b[i].rightUp )
 {
   b[i].rightUp = false;
   // b[i].b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
   // b[i].bullet.setTexture(b[i].b);
 }
//   else if(b[i].bullet.getPosition().y < - 20 || b[i].bullet.getPosition().x > 520  &&  b[i].slightRight )
//  {
  
//    b[i].slightRight = false;
//     // b[i].b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
//    // b[i].bullet.setTexture(b[i].b);
//  }
//   else if(b[i].bullet.getPosition().y < - 20 || b[i].bullet.getPosition().x > 520  &&  b[i].moreRight)
//  {
//    b[i].moreRight = false;
//    // b[i].b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
//    // b[i].bullet.setTexture(b[i].b);
//  }
   else if(b[i].bullet.getPosition().y <  20 || b[i].bullet.getPosition().x > 520  && b[i].rightDown)
 {
   b[i].rightDown = false;
   // b[i].b.loadFromFile("img/PNG/Lasers/laserBlue03.png");
   // b[i].bullet.setTexture(b[i].b);
 }
 
  if(count >= 90)
   {
   count = 0;
  

   }



}


void Player::destroyShip(Bomb *bomb, Enemy **enemy,float &timer)
{ 
    static int t = 0;
 
  
     FloatRect spaceshipBox = sprite.getGlobalBounds();
    
    if(enemy[14]->MD_Spawned())
    {
          FloatRect spaceshipBox = sprite.getGlobalBounds();

    FloatRect lightningBox = enemy[14]->GetDamageSprite().getGlobalBounds();
    lightningBox.width -= 20.0f; 
    FloatRect monsterBox = enemy[14]->GetSprite().getGlobalBounds();
    
    //cout<<lightningBox.width<<"     "<<lightningBox.height<<endl;
    
    if(spaceshipBox.intersects(monsterBox) && !hit && timer>t)
    {    
  buffer.loadFromFile("Digital_SFX_Set/playerdeath.wav");
  sound.setBuffer(buffer);
  sound.setVolume(60);
        sound.play();
        hit = true;
        t = timer + 3;
        
        if(numberOfLives>0)
        {
        numberOfLives--;
        }
            animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);

    }

    else if(spaceshipBox.intersects(lightningBox) && !hit && enemy[14]->hit() && timer>t)
    {
  buffer.loadFromFile("Digital_SFX_Set/playerdeath.wav");
  sound.setBuffer(buffer);
  sound.setVolume(60);
        sound.play();
        hit = true;
        t = timer + 3;
        
        if(numberOfLives>0)
        {
        numberOfLives--;
        }

      animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);

    }

     
    
    
    }

     else if(enemy[15]->MD_Spawned())
    {
    FloatRect spaceshipBox = sprite.getGlobalBounds();
    FloatRect DragonBox = enemy[15]->GetSprite().getGlobalBounds();
    FloatRect FireBox = enemy[15]->GetDamageSprite().getGlobalBounds();
     //FireBox.width -= 20.0f;
  

   DragonBox.height -= 60.0f;
   DragonBox.width -= 50.0f;

       

    if(spaceshipBox.intersects(DragonBox) && !hit && timer>t)
    {    
  buffer.loadFromFile("Digital_SFX_Set/playerdeath.wav");
  sound.setBuffer(buffer);
  sound.setVolume(60);
        sound.play();
        hit = true;
        t = timer + 3;
        
        if(numberOfLives>0)
        {
        numberOfLives--;
        }
            animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);

    }

    
else if(spaceshipBox.intersects(FireBox) && !hit  && timer>t)
    {
  buffer.loadFromFile("Digital_SFX_Set/playerdeath.wav");
  sound.setBuffer(buffer);
  sound.setVolume(60);
        sound.play();
        hit = true;
        t = timer + 3;
        
        if(numberOfLives>0)
        {
        numberOfLives--;
        }

      animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);
    }

    

    }

    else
    {

    for(int i=0; i<14; i++)
    {
    FloatRect bombBox = bomb[i].sprite.getGlobalBounds();
    FloatRect enemyBox = enemy[i]->GetSprite().getGlobalBounds();
    
     if(spaceshipBox.intersects(enemyBox) && enemy[i]->hit()  && !hit && timer>t)
    {    
  buffer.loadFromFile("Digital_SFX_Set/playerdeath.wav");
  sound.setBuffer(buffer);
  sound.setVolume(60);
        sound.play();
        enemy[i]->setHit(0);
        bomb[i].fired = false;
        hit = true;
        t = timer + 3;
        
        if(numberOfLives>0)
        {
        numberOfLives--;
        }

    }
    
    else if(bombBox.intersects(spaceshipBox) && enemy[i]->hit()  && !hit && timer>t)
    {
    
    buffer.loadFromFile("Digital_SFX_Set/playerdeath.wav");
  sound.setBuffer(buffer);
  sound.setVolume(60);
  
     
       sound.play();
        bomb[i].fired = false;
        hit = true;
        t = timer + 3;

        if(numberOfLives>0)
        {
        numberOfLives--;
        }

        animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);
    }
    else if(bombBox.intersects(spaceshipBox) && !enemy[i]->hit() && bomb[i].fired && !hit && timer>t)
    {
    
  buffer.loadFromFile("Digital_SFX_Set/playerdeath.wav");
  sound.setBuffer(buffer);
  sound.setVolume(60);
  
     
       sound.play();
        bomb[i].fired = false;
        hit = true;
        t = timer + 3;
        if(numberOfLives>0)
        {
        numberOfLives--;
       
        }

        animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);
    }
    
   
       
    if(hit && timer>t)
    {
  buffer.loadFromFile("Digital_SFX_Set/reset.wav");
  sound.setBuffer(buffer);
  sound.setVolume(100);
  sound.play();
     hit = false;
     bomb[i].fired = false;
     sprite.setPosition(210,575);
     t = timer+2;
    }
    
    }

    }

    if(hit && timer>t)
    {
     buffer.loadFromFile("Digital_SFX_Set/reset.wav");
     sound.setBuffer(buffer);
     sound.setVolume(100);
     sound.play();
     hit = false;
     sprite.setPosition(210,575);
     t = timer+2;
    }
}


//======life Add on==================



void Player::life_Add_on(Add_On *Recievelife, float time,RenderWindow &window)
{
  this->life = Recievelife;
  static bool newLife = true;
 
  if(!life->getTimeBool())  //If time is not generated then generate random time
  {
    life->RandomTimeGenerate();
    life->setTimeBool(1);
    life->getSprite().setPosition(rand() % 480 + 10 , -20); 
    newLife = true;
     }
  
  if(life_delay >= life->getDelay())
  {
    
   life->update();

   FloatRect playerShip = sprite.getGlobalBounds();
   FloatRect lifeArea = life->getSprite().getGlobalBounds();
   
     if(life->getSprite().getPosition().y >= 690)
   {
     life->getSprite().setPosition(rand() % 480 + 10 , -20);
     life_delay = 0;
     life->setTimeBool(0);
   }

   if(lifeArea.intersects(playerShip) && newLife && !hit)
   {   
       delete [] lives;
       numberOfLives++;
       lives = new Lives[numberOfLives];
       newLife = false;
   }

   
   if(newLife)
  window.draw(life->getSprite());
 
  }

  

  life_delay += time;
}

//====================

//=====Danger add on ===========

void Player::Danger_Add_on(Add_On *NewDanger,float time,int &score,RenderWindow &window)
{
   this->danger = NewDanger;
  static bool newDanger = true;
 
  if(!danger->getTimeBool())  //If time is not generated then generate random time
  {
    danger->RandomTimeGenerate();
    danger->setTimeBool(1);
    danger->getSprite().setPosition(rand() % 480 + 10 , -20); 
    newDanger = true;
     }
  
  if(danger_delay >= danger->getDelay())
  {
    
   danger->update();

   FloatRect playerShip = sprite.getGlobalBounds();
   FloatRect dangerArea = danger->getSprite().getGlobalBounds();
   
     if(danger->getSprite().getPosition().y >= 690)
   {
     danger->getSprite().setPosition(rand() % 480 + 10 , -20);
     danger_delay = 0;
     danger->setTimeBool(0);
     score+=5;
   }

   if(dangerArea.intersects(playerShip) && newDanger && !hit )
   {
        buffer.loadFromFile("Digital_SFX_Set/playerdeath.wav");
        sound.setBuffer(buffer);
        sound.setVolume(60);
        sound.play();
       
       delete [] lives;
       numberOfLives--;
       lives = new Lives[numberOfLives];
       newDanger = false;
       hit = true;
       animation.setPosition(sprite.getPosition().x, sprite.getPosition().y);
   }

   
   if(newDanger)
  window.draw(danger->getSprite());
 
  }

  

  danger_delay += time;




}


//==========================


//=====FIRE ADD ON ==============

void Player::Fire_Add_on(Add_On *NewFire,float time,RenderWindow &window)
{
   this->fireAddon = NewFire;
  static bool newFire = true;
 
  if(!fireAddon->getTimeBool())  //If time is not generated then generate random time
  {
    fireAddon->RandomTimeGenerate();
    fireAddon->setTimeBool(1);
    fireAddon->getSprite().setPosition(rand() % 480 + 10 , -20); 
    newFire = true;
     }
  
  if(fire_delay >= fireAddon->getDelay())
  {
    
   fireAddon->update();

   FloatRect playerShip = sprite.getGlobalBounds();
   FloatRect fireArea = fireAddon->getSprite().getGlobalBounds();
   
     if(fireAddon->getSprite().getPosition().y >= 690)
   {
     fireAddon->getSprite().setPosition(rand() % 480 + 10 , -20);
     fire_delay = 0;
     fireAddon->setTimeBool(0);
     
   }

   if(fireArea.intersects(playerShip) && newFire  && !hit )
   {
      buffer.loadFromFile("Digital_SFX_Set/Upgrade.wav");
      sound.setBuffer(buffer);
      sound.setVolume(60);
        sound.play();
       newFire = false;
       FireActive = true;
   }

   
   if(newFire)
  window.draw(fireAddon->getSprite());
 
  }

  

  

  fire_delay += time;

}


//Power Up add on
void Player::PowerUp_Add_on(Add_On *NewPowerUp, float time, RenderWindow &window)
{
   this->powerUp = NewPowerUp;
  static bool newPower = true;
 
  if(!powerUp->getTimeBool())  //If time is not generated then generate random time
  {
    powerUp->RandomTimeGenerate();
    powerUp->setTimeBool(1);
    powerUp->getSprite().setPosition(rand() % 480 + 10 , -20); 
    newPower = true;
     }
  
  if(powerUp_delay >= powerUp->getDelay())
  {
    
   powerUp->update();

   FloatRect playerShip = sprite.getGlobalBounds();
   FloatRect powerArea = powerUp->getSprite().getGlobalBounds();
   
     if(powerUp->getSprite().getPosition().y >= 690)
   {
     powerUp->getSprite().setPosition(rand() % 480 + 10 , -20);
     powerUp_delay = 0;
     powerUp->setTimeBool(0);
     
   }

   if(powerArea.intersects(playerShip) && newPower  && !hit )
   {
      buffer.loadFromFile("Digital_SFX_Set/Upgrade.wav");
      sound.setBuffer(buffer);
      sound.setVolume(60);
      sound.play();
       newPower = false;
       PowerUpActive = true;
   }

   
   if(newPower)
  window.draw(powerUp->getSprite());
 
  }  

  powerUp_delay += time;

}


//=================
void Player::move(std::string s){
float delta_x=0,delta_y=0;
if(s=="l")
{	delta_x=-1;
       x = sprite.getPosition().x;
       y = sprite.getPosition().y;      
if(x<-50)
{
x = 503;
sprite.setPosition(x, y);
 }
 
 }

else if(s=="r")
{
	delta_x = 1;
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;
	 if(x > 500) 
         {
         x = -50;
	 sprite.setPosition(x, y);
	 }
	
}
if(s=="u")
{	
        delta_y=-1;
        x = sprite.getPosition().x;
        y = sprite.getPosition().y;
        
 if( y < -50)
 {
y = 690; 
sprite.setPosition(x,y);
}
	
	}
else if(s=="d")
{
	delta_y=1;
	x = sprite.getPosition().x;
        y = sprite.getPosition().y;
        
	 if(y > 690)
     {
        y = -50;
      sprite.setPosition(x, y);
      }
}


if(s=="lu")
{ 

  tex.loadFromFile("img/image.png");
  sprite.setTexture(tex);  
  

//sprite.setOrigin(sprite.getLocalBounds().width / 2, //sprite.getLocalBounds().height / 2);
// sprite.setRotation(-45);
}

else if(s=="ru")
{

   tex.loadFromFile("img/image1.png");
   sprite.setTexture(tex);  
   
  
//sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
// sprite.setRotation(45);
}

else if(s=="ld")
{

 tex.loadFromFile("img/image3.png");
   sprite.setTexture(tex);  
  
 //sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2); 
 //sprite.setRotation(-135);
}

else if(s=="rd")
{

 tex.loadFromFile("img/image2.png");
   sprite.setTexture(tex);  
   
//sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
 //sprite.setRotation(135);
}

delta_x*=speed;
delta_y*=speed;


sprite.move(delta_x, delta_y);

}

void Player::reset()
{


 tex.loadFromFile("img/player_ship.png");
   sprite.setTexture(tex);  

// sprite.setRotation(0);
}
