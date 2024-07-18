#include "game.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
#include "player.h"
#include "enemy.h"
#include "PowerUp.h"
#include "Monster.h"
#include "Dragon.h"
#include "pauseMenu.h"
#include "Add_Ons.h"
#include "Danger.h"
#include "Fire.h"
#include "Lives.h"
#include "menu.h"
#include <cmath>




Game::Game()
{

//======= Creating Player ================    
p=new Player("img/player_ship.png");
bg_texture.loadFromFile("img/background2.jpg");
background.setTexture(bg_texture);
background.setScale(1, 3);

bulletCount = 0;

pressed = false; //To make sure the space is pressed only once
//========================================

SCORE = 0;

//=========  Creating Enemies  =============
for(int i=0; i<14; i++)
{
if(i<8)
enemy[i] = new Alpha();

else if(i<12)
{
enemy[i] = new Beta();
bomb[i].SetTexture("img/PNG/Lasers/laserGreen14.png");
}
else
{
enemy[i] = new Gamma();
bomb[i].SetTexture("img/PNG/Lasers/laserRed08.png");
}

}

//======= Creating Monster and Dragon ========================

 enemy[14] = new Monster();
 enemy[15] = new Dragon();
//========================================

//======= Creating Add ons =================
life = new Lives ();
danger = new Danger();
fire = new Fire();
powerUp = new PowerUp();
//========================================

           //============SOUND==============================
            buffer.loadFromFile("Digital_SFX_Set/laser3.wav");
            sound.setBuffer(buffer);
            sound.setVolume(100);
           //===============================================


           //===============MUSIC===========================
           music.openFromFile("Digital_SFX_Set/music.wav");
           music.setVolume(35);
           music.setLoop(true);
           //===============================================

//============LOAD SPRITE SHEET==========

texture.loadFromFile("img/explosion.png");
animation.setTexture(texture);
animation.setScale(0.45,0.45);



//============= SCORE  ===================

  font.loadFromFile("Cartoon.ttf"); 
  text.setFont(font);
  text.setColor(Color::Yellow);
  text.setString("SCORE: ");
  text.setCharacterSize(36);
  text.setPosition(180, 0);
  

  Score_font.loadFromFile("Cartoon.ttf"); 
  Score_text.setFont(font);
  Score_text.setColor(Color::Yellow);
  Score_text.setCharacterSize(36);
  Score_text.setPosition(300, 0);


  lives_font.loadFromFile("CrimaDisplay.otf"); 
  lives_text.setFont(font);
  lives_text.setColor(Color::Yellow);
  lives_text.setString("Lives: ");
  lives_text.setCharacterSize(28);
  lives_text.setPosition(0, 0);
  


  GameOver_font.loadFromFile("CrimaDisplay.otf"); 
  GameOver_text.setFont(font);
  GameOver_text.setColor(Color::Red);
  GameOver_text.setString("GAME OVER");
  GameOver_text.setCharacterSize(62);
  GameOver_text.setPosition(110, 350);

  YourScore_font.loadFromFile("CrimaDisplay.otf"); 
  YourScore_text.setFont(font);
  YourScore_text.setColor(Color::Red);
  YourScore_text.setString("YOUR SCORE IS:  ");
  YourScore_text.setCharacterSize(44);
  YourScore_text.setPosition(110, 450);
//===============================


       
    playerName.setFont(font);
    playerName.setCharacterSize(42);
    playerName.setFillColor(sf::Color::White);
    playerName.setPosition(80, 250);

    YourName.setFont(font);
    YourName.setCharacterSize(50);
    YourName.setFillColor(sf::Color::White);
    YourName.setString("Enter Your Name: \n");
    YourName.setPosition(80, 150);
 
 NameEntered = false;
 DataSaved = false;
}


bool checkifEnemyDestroyed(Enemy **enemy)
            {
            for(int i=0; i<14; i++)
            if(enemy[i]->hit())
            return false;

            return true;
            }
            
void Game::start_game(RenderWindow &window)
{
    srand(time(0));
    //RenderWindow window(VideoMode(500, 680), title);
    Clock clock;
    float timer=0;
    Clock c;
    Clock c2;
    music.play();
    
     float t = 0;
     float bombDelay = 4;
     bool pause_menu = false;
     bool gameOver = false;
   
   IntRect rectSourceSprite(0, 0, 138, 138);
   IntRect rectSourceSprite2[14];
    
    for(int i=0; i<14; i++)
     rectSourceSprite2[i]= IntRect(0,0,138,138);

 //==============
float time = 0;
float seconds = 0;
float seconds2 = 0;

//=================
    while (window.isOpen())
    {
        if(NameEntered) //Clock should start after the name is entered
        {
         time = clock.getElapsedTime().asSeconds(); 

         seconds = c.getElapsedTime().asSeconds();
         seconds2 = c2.getElapsedTime().asSeconds();
         clock.restart();
        
        timer += time;  
       // cout<<timer<<endl; 
        }
 	Event e;
        while (window.pollEvent(e) )
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
               {
                 if(!DataSaved)
                    {
                      playerData.setHighScore(SCORE);  
                      playerData.SaveData("data.txt");
                      DataSaved = true;
                      }
                window.close(); //close the game                        	     
               }
         if(!NameEntered)
         {
           
           if (e.type == Event::TextEntered)
            {
                if (e.text.unicode < 128 && e.text.unicode != 8)  // Ignore control characters except Backspace
                {
                    inputName += static_cast<char>(e.text.unicode);
                    playerName.setString(inputName);
                }
                else if (e.text.unicode == 8 && !inputName.empty())  // Backspace key
                {
                    inputName.pop_back();
                    playerName.setString(inputName);
                }
            }

             else if (e.type == Event::KeyPressed)
            {
                if (e.key.code == Keyboard::Enter)
                {
                    playerData.setPlayerName(inputName);
                    NameEntered = true;
                }
            }

         }
         
        }

  if(NameEntered)
  {  
      if(!gameOver)
      {
      
        if(Keyboard::isKeyPressed(Keyboard::H))
        {
          pauseMenu *pause = new pauseMenu(500.0,680.0);

          if(pause->Display_PauseMenu(window, playerData, SCORE))
           {
             if(!DataSaved)
             {
               playerData.setHighScore(SCORE);  
               playerData.SaveData("data.txt");
               DataSaved = true;
             }
            Game game;
            game.start_game(window);
           }
           else
          delete pause;
        }
          
          
        if(timer>3 )//&& !pause_menu)  // No movement for 3 seconds
        {
          
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
            
	////////////////////////////////////////////////
	/////  Call your functions here            ////
	//////////////////////////////////////////////

       if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)) // If down key is pressed
           {
            p->move("lu");  //player will move left up
            
            }
                
           else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) // If down key is pressed
            p->move("ru");  //player will right up
            
           else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left)) // If down key is pressed
            p->move("ld");  //player will left down
            
           else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right)) // If down key is pressed
            p->move("rd");  //player will right down
                                         
           else
             {
              p->reset();
              }
          
          if(Keyboard::isKeyPressed(Keyboard::Space) && !pressed && !p->hit) // space to fire 
                {        
                  sound.play();
                 
                   if(!p->PowerUpActive)
                   {
                   if(Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
                    {
                      bullet[bulletCount].leftUp = true;
                     // bullet[bulletCount].b.loadFromFile("img/PNG/Lasers/45Bullets.png");
                     // bullet[bulletCount].bullet.setTexture(bullet[bulletCount].b);
                      
                      bullet[bulletCount].bullet.setRotation(-45);
                      bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x -25 , p->sprite.getPosition().y-25);
                      
                      //Only used to set the origin as the picture is not fully displayed otherwise
                      //Vector2f spriteSize(bullet[bulletCount].bullet.getGlobalBounds().width, bullet[bulletCount].bullet.getGlobalBounds().height);
                      //bullet[bulletCount].bullet.setOrigin(spriteSize/2.0f);

                      //bullet[bulletCount].bullet.setScale(0.65,0.65);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
                    {
                      bullet[bulletCount].rightUp = true;
                      bullet[bulletCount].bullet.setRotation(45);
                      // bullet[bulletCount].b.loadFromFile("img/PNG/Lasers/-45Bullets.png");
                      // bullet[bulletCount].bullet.setTexture(bullet[bulletCount].b);
                       bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x + 60, p->sprite.getPosition().y-15);

                      //bullet[bulletCount].bullet.setScale(0.65,0.65);
                    }
                      else if(Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
                    {
                      bullet[bulletCount].rightDown = true;
                      bullet[bulletCount].bullet.setRotation(135);
                      bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x + 70, p->sprite.getPosition().y+65);

                      //bullet[bulletCount].b.loadFromFile("img/PNG/Lasers/45Bullets.png");
                      //bullet[bulletCount].bullet.setTexture(bullet[bulletCount].b);
                      //bullet[bulletCount].bullet.setScale(0.65,0.65);
                    }
                      else if(Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
                    {
                      // bullet[bulletCount].leftDown = true;
                      // bullet[bulletCount].b.loadFromFile("img/PNG/Lasers/-45Bullets.png");
                      // bullet[bulletCount].bullet.setTexture(bullet[bulletCount].b);
                      //bullet[bulletCount].bullet.setScale(0.65,0.65);
                    }
                  if(!bullet[bulletCount].leftUp && !bullet[bulletCount].rightUp && !bullet[bulletCount].leftDown && !bullet[bulletCount].rightDown)
                   {
                    bullet[bulletCount].bullet.setRotation(0);
                    bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x+25,p->sprite.getPosition().y-20); 
                     
                   }
                  bullet[bulletCount].fired = true;
                  pressed = true;
                  bulletCount++;   
                   }

                   else
                   {
                    
                    bullet[bulletCount].bullet.setRotation(0);
                    bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x+25,p->sprite.getPosition().y-20); 
                    bullet[bulletCount].fired = true;
                    bulletCount++; 

                    bullet[bulletCount].slightLeft = true;
                    bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x+10,p->sprite.getPosition().y-20);
                    bullet[bulletCount].bullet.setRotation(-25);
                    bullet[bulletCount].fired = true;
                    bulletCount++; 

                    bullet[bulletCount].moreLeft = true;
                    bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x,p->sprite.getPosition().y-20);
                    bullet[bulletCount].bullet.setRotation(-35);
                    bullet[bulletCount].fired = true;
                    bulletCount++;                     
                    

                    bullet[bulletCount].leftUp = true;
                    bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x-5,p->sprite.getPosition().y-20);
                    bullet[bulletCount].bullet.setRotation(-45);
                    bullet[bulletCount].fired = true;
                    bulletCount++;                     

                    bullet[bulletCount].slightRight = true;
                    bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x+40,p->sprite.getPosition().y-20);
                    bullet[bulletCount].fired = true;
                    bullet[bulletCount].bullet.setRotation(25);
                    bulletCount++; 

                    bullet[bulletCount].moreRight = true;
                    bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x+50,p->sprite.getPosition().y-20);
                    bullet[bulletCount].fired = true;
                    bullet[bulletCount].bullet.setRotation(35);
                    bulletCount++; 


                    bullet[bulletCount].rightUp = true;
                    bullet[bulletCount].bullet.setPosition(p->sprite.getPosition().x+55,p->sprite.getPosition().y-20);
                    bullet[bulletCount].bullet.setRotation(25);
                    bullet[bulletCount].fired = true;
                    bulletCount++;                     

                   pressed = true;
                    
                   }

            
                 
                }
                else if(e.type == Event::KeyReleased && e.key.code == Keyboard::Space)
                pressed = false;
 
    }
 
     if(p->PowerUpActive )
     {
         static float d = 0;
         d+=time;

         if(d>=5)
         {

          for(int i=0; i<100; i++)
          {
            bullet[i].bullet.setRotation(0);
            bullet[i].bullet.setPosition(p->sprite.getPosition().x+25,p->sprite.getPosition().y-20);                
            bullet[i].slightLeft = false;
            bullet[i].slightRight = false;
            bullet[i].moreLeft = false;
            bullet[i].moreRight = false;
          }

         p->PowerUpActive = false;
         d=0;
         }
     }


       //======= Bullet Fire ===========
      
      
        p->fire(bullet,time,bulletCount);
         
         // =========== To Change Level ==============
        
      
        
         if(checkifEnemyDestroyed(enemy) && !levels.phaseChange && !enemy[14]->MD_Spawned() && !enemy[15]->MD_Spawned() && timer>t)
        {
          
        if(levels.gameLevel<3)
        {
        levels.phase++;
        levels.phaseChange = true;
        }
        if(levels.phase == 4 && levels.gameLevel <3)
        {  levels.phase = 1;
          levels.gameLevel++;
        }

        else if(levels.gameLevel == 3)
        {
         levels.phaseChange = true;
         levels.phase = rand() % 8 + 1;
        }

         for(int i=0; i<14; i++)  
         if (rectSourceSprite2[i].left >= 552)
        rectSourceSprite2[i].left = 0;
        
        for(int i=0; i<14; i++)
        bomb[i].fired = false;
   
        t = timer+3;
        bombDelay = timer+7;
         } 
        

        if(timer>t)
        levels.DisplayLevels(enemy,timer,t,bombDelay, time);
         
      
      //========== Setting Lives sprite on the screen ==========================
    
        for(int i=0,j=70; i<p->numberOfLives; i++,j=j+10)
        p->lives[i].getSprite().setPosition(j,5);

        
     // ========= Check Collisions of bullets with enemy ==============
        if(!levels.phaseChange)
        for(int i=0; i<14; i++)
           for(int j=0; j<100; j++)
                if(bullet[j].fired  && enemy[i]->hit() && !p->FireActive)
                   enemy[i]->destroy(bullet[j].bullet.getPosition().x, bullet[j].bullet.getPosition().y, &bullet[j],SCORE,levels.gameLevel); 

      //========= Check Collisions but in this case with the fire add on to Destroy all enemies in it's way ======          
         if(!levels.phaseChange && p->FireActive)
         for(int i=0; i<100; i++)
            for(int j=0; j<14; j++)
             if(bullet[i].fired  && enemy[j]->hit())     
              enemy[j]->AddOndestroy(bullet[i].bullet.getPosition().x, bullet[i].bullet.getPosition().y, &bullet[i], SCORE, levels.gameLevel);  
 
   
    // ========= Enemies Bomb =========   
       if(timer>bombDelay && !levels.phaseChange)
       for(int i=0; i<14; i++)
       if(enemy[i]->hit())      //Did the opposite :) enemey->hit is true means that if enemy is not hit 
       enemy[i]->bomb(&bomb[i], timer,time, levels.gameLevel);                                          
       else if(!enemy[i]->hit() && bomb[i].fired)
       {
        enemy[i]->bomb(&bomb[i], timer,time, levels.gameLevel);  
       }  

 // ======= Animation of player if destroyed ========
      if ( p->hit && seconds>0.3 && !p->PowerUpActive){
      
     rectSourceSprite.left += 138;
  
     p->animation.setTextureRect(rectSourceSprite);
     c.restart();
     
    }
  
  //======= Animation of Enemies if Destoryed ===========
   if(seconds2>0.3)
   for(int i=0; i<14; i++)
   {
    if(!enemy[i]->hit() && rectSourceSprite2[i].left <= 552 && !levels.phaseChange && !enemy[14]->MD_Spawned() && !enemy[15]->MD_Spawned()) //&& seconds2>0.3)
    {

     rectSourceSprite2[i].left += 138;
     animation.setTextureRect(rectSourceSprite2[i]);
     c2.restart();
    }
   } 
    

   //==========MONSTER AND DRAGON======================
  if(enemy[14]->MD_Spawned())
  {
  enemy[14]->update();
  
  for(int j=0; j<100; j++)
  enemy[14]->destroy(bullet[j].bullet.getPosition().x, bullet[j].bullet.getPosition().y, &bullet[j],SCORE,levels.gameLevel);                
            
  //enemy[14]->bomb(bomb,timer,time);
  enemy[14]->MonsterOrDragon_Attack(p,time,SCORE);

  }
  
  else if(enemy[15]->MD_Spawned())
  {
    enemy[15]->DragonFire(p->sprite.getPosition().x, p->sprite.getPosition().y, time, SCORE, p);
  
  
    for(int j=0; j<100; j++)
    enemy[15]->destroy(bullet[j].bullet.getPosition().x, bullet[j].bullet.getPosition().y, &bullet[j],SCORE,levels.gameLevel);                
  
  }
   //====================

     
      //=======PLAYER COLLISION======================
        
        if(!levels.phaseChange && timer>bombDelay && !p->PowerUpActive)
        p->destroyShip(bomb,enemy,timer);
      


 //Score Update===================
 string NewScore = to_string(SCORE);
 Score_text.setString(NewScore);
 //===================

      }

window.clear(Color::Black); //clears the screen



//====== Setting up Backgrounds and the phases ============
 if(levels.phase == 1 && levels.gameLevel<3)
	window.draw(levels.phase1_back);  // setting background
	else if(levels.phase == 2 && levels.gameLevel<3)
  window.draw(levels.phase2_back);
  else if(levels.phase == 3 && levels.gameLevel<3)
  window.draw(levels.phase3_back);

    else if(levels.phase == 1 && levels.gameLevel == 3)
    window.draw(levels.level3_sprites[0]);
    else if(levels.phase == 2 && levels.gameLevel == 3)
  window.draw(levels.level3_sprites[1]);
    else if(levels.phase == 3 && levels.gameLevel == 3)
  window.draw(levels.level3_sprites[2]);
    else if(levels.phase == 4 && levels.gameLevel == 3)
  window.draw(levels.level3_sprites[3]);
    else if(levels.phase == 5 && levels.gameLevel == 3)
  window.draw(levels.level3_sprites[4]);
    else if(levels.phase == 6 && levels.gameLevel == 3)
  window.draw(levels.level3_sprites[5]);
   else if(levels.phase == 7 && levels.gameLevel == 3)
  window.draw(levels.level3_sprites[5]);
      else if(levels.phase == 8 && levels.gameLevel == 3)
  window.draw(levels.level3_sprites[4]);

   if(timer<3 && levels.phase == 1)
	 {
    window.draw(levels.level[0]);
    window.draw(levels.phase_img[0]);
   }
   else if(timer<t && levels.phase == 1)
   {
     if(levels.gameLevel == 2 )
     {
      window.draw(levels.level[1]);
      window.draw(levels.phase_img[0]);
     }
    else if(levels.gameLevel == 3 && levels.once)
    { window.draw(levels.level[2]);
      levels.once = false;
    }
   }
    
  else if(timer<t && levels.phase == 2 && levels.phaseChange && levels.gameLevel<3)
  window.draw(levels.phase_img[1]);
  
  else if(timer<t && levels.phase == 3 && levels.phaseChange && levels.gameLevel<3)
  window.draw(levels.phase_img[2]);
  
//==============================================

	

//============LIFE ADDON=================
 
 for(int i=0;i<p->numberOfLives; i++)
   if(p->lives[i].Available())
       window.draw(p->lives[i].getSprite());
 
 p->life_Add_on(life,time,window);

//==============================


//=========Danger Add on===============

p->Danger_Add_on(danger,time,SCORE,window);
//=====================

//====Fire Add on==========
p->Fire_Add_on(fire,time,window);
//====================


//===== If Fire add on is picked ===============
  if(p->FireActive)
      { 
        static bool once = true;
       
       if(once)
       {
       for(int i=0; i<100; i++)
       {
        bullet[i].set_Texture("img/PNG/Lasers/FireBullet.png", 1.5, 0.5);
       }
        once = false;
       }
       static float activeTime = 0;
       activeTime+=time;
       
       if(activeTime>=5.0)
       {
        
        for(int i=0; i<100; i++)
       bullet[i].set_Texture("img/PNG/Lasers/laserBlue03.png",0.65,0.65);
       
        p->FireActive = false;
        activeTime = 0;
        once = true;
       }
              }
        
 //=======Power Up Add on ===========

 p->PowerUp_Add_on(powerUp,time,window);

   


//======== Score Display ===================
window.draw(text);
window.draw(Score_text);
//================
window.draw(lives_text);
//===============

	//========Drawing Monster and Dragon =================
  if(enemy[14]->MD_Spawned())
  {
  window.draw(enemy[14]->GetSprite());
  if(enemy[14]->hit())
  window.draw(enemy[14]->GetDamageSprite());
  }
  else if(enemy[15]->MD_Spawned())
  {
  window.draw(enemy[15]->GetSprite());
  window.draw(enemy[15]->GetDamageSprite());

  }
  //================================      


 //====== Player Ship ========
	if(!p->hit ) //if the ship is not hit then draw
	{window.draw(p->sprite);   // setting player on screen

   if (rectSourceSprite.left >= 552)
        rectSourceSprite.left = 0;
     
  }
  else
  { 
    window.draw(p->animation);

  }

 // ============ Drawing Enemies =============
         for(int i=0; i<14; i++) 
        if(enemy[i]->hit() && timer>t && !levels.phaseChange)  //if enemy is not destroyed then draw
                {  window.draw(enemy[i]->GetSprite());
           
                }
        else if(!levels.phaseChange && !enemy[14]->MD_Spawned() && !enemy[15]->MD_Spawned())
        {
          if(rectSourceSprite2[i].left <=552)
          {
         animation.setPosition(enemy[i]->GetSprite().getPosition().x, enemy[i]->GetSprite().getPosition().y); 
         window.draw(animation);
          }
        } 


//====== Drawinf bullets ==========
   for(int i=0; i<100; i++)
           {
           if(bullet[i].fired )
           window.draw(bullet[i].bullet);
            
           }
 //======================          
           
           
       //=========== Drawing Bombs =========    
            if(timer>bombDelay && !levels.phaseChange)
           {
           for(int i=0; i<14; i++)
           {
            if(enemy[i]->hit() && bomb[i].fired)
            window.draw(enemy[i]->getbomb()->sprite);
           
             else if(!enemy[i]->hit() && bomb[i].fired)
             {
               window.draw(bomb[i].sprite);
             }
           
           }
           
           }

              
   //======= GAME OVER===========

 if(p->numberOfLives == 0 )
 {
   if(!DataSaved)
   {
   playerData.setHighScore(SCORE);  
   playerData.SaveData("data.txt");
   DataSaved = true;
   }
   gameOver = true;


//====GAME OVER=======
    window.draw(GameOver_text);
  //  window.draw(YourScore_text);
  //  window.draw(Score_text);  

  static float OverDelay = 0;
  OverDelay += time;

 if(OverDelay>=4)
 {
     Menu m(500,680);
     m.display_menu(window);
    
 }
 }

 	window.display();  //Displying all the sprites
    }

     else
    {

       window.clear(Color::Black);
       window.draw(YourName);
       window.draw(playerName);
       window.display();
    }

    
    
    }//While window is open
   
    

}


