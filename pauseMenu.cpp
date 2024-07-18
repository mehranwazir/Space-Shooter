
#include "pauseMenu.h"
#include "PlayerData.h"

pauseMenu::pauseMenu()
{
//IndexSelected = 0;
b.loadFromFile("img/phases/menu.png");
background.setTexture(b);
background.setScale(1, 1.2);

logo.loadFromFile("img/Logo.png");
logoSprite.setTexture(logo);
logoSprite.setScale(0.35,0.35);
logoSprite.setPosition(80,-80);
}
pauseMenu::pauseMenu(float width, float height)
{

 b.loadFromFile("img/phases/menu.png");
background.setTexture(b);
background.setScale(1, 1.2);

logo.loadFromFile("img/Logo.png");
logoSprite.setTexture(logo);
logoSprite.setScale(0.35,0.35);
logoSprite.setPosition(80,-80);
 
  font.loadFromFile("Cartoon.ttf"); 
  menu[0].setFont(font);
  menu[0].setColor(Color::Yellow);
  menu[0].setString("CONTINUE");
  menu[0].setCharacterSize(42);
  menu[0].setPosition(width/2-90, height/(MAX_ITEMS+1)*1+40);
  
   
  menu[1].setFont(font);
  menu[1].setColor(Color::White);
  menu[1].setString("NEW GAME");
  menu[1].setCharacterSize(42);
  menu[1].setPosition(width/2-90, (height/(MAX_ITEMS+1)*2));


  menu[2].setFont(font);
  menu[2].setColor(Color::White);
  menu[2].setString("INSTRUCTIONS");
  menu[2].setCharacterSize(42);
  menu[2].setPosition(width/2-90, (height/(MAX_ITEMS+1)*3)-50);
  
  menu[3].setFont(font);
  menu[3].setColor(Color::White);
  menu[3].setString("HIGH SCORE");
  menu[3].setCharacterSize(42);
  menu[3].setPosition(width/2-90, (height/(MAX_ITEMS+1)*4)-100);  

  menu[4].setFont(font);
  menu[4].setColor(Color::White);
  menu[4].setString("EXIT");
  menu[4].setCharacterSize(42);
  menu[4].setPosition(width/2-90, (height/(MAX_ITEMS+1)*5)-150);  

//IndexSelected = 0;

}

void pauseMenu::MoveUp()
{
  if(IndexSelected - 1 >= 0)
  {
     menu[IndexSelected].setColor(Color::White);
     IndexSelected--;
     menu[IndexSelected].setColor(Color::Yellow);
  
  }
}

void pauseMenu::MoveDown()
{
  if(IndexSelected + 1 < MAX_ITEMS)
  {
     menu[IndexSelected].setColor(Color::White);
     IndexSelected++;
     menu[IndexSelected].setColor(Color::Yellow);
  }
}



void pauseMenu::draw(RenderWindow &window)
{
for(int i=0; i<MAX_ITEMS; i++)
 window.draw(menu[i]);

}



 bool pauseMenu::Display_PauseMenu(RenderWindow &window, PlayerData &playerData, int &SCORE)
 {
  

 bool flag = false;
 bool flagContinue = true;
 bool instru = false;
  while (window.isOpen())
    {
 	Event e;
        while (window.pollEvent(e))
        {  
          
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                
                
                
                if(e.type == Event::KeyReleased)
                {
                
                 if(e.key.code == Keyboard::Up)
                 {
                   MoveUp();
                 }
                 
                 else if(e.key.code == Keyboard::Down)
                 {
                  MoveDown();
                  
                 }
                 
                 else if(e.key.code == Keyboard::Return)
                 {  
                 
                     
                    if(IndexSelected == 0)
                    {
                    flagContinue = false;                   
                    }
                    
                    else if(IndexSelected == 1)
                    {
                     flag = true;
                     
                    }
                    
                    else if(IndexSelected == 2)
                    {
                     instru = true;
                    }
                    
                    else if(IndexSelected == 3)
                    {
                     score.highscore(window);                       
                    } 

                    else if(IndexSelected == 4)
                    {
                     
                      playerData.setHighScore(SCORE);  
                      playerData.SaveData("data.txt");
                      window.close();
                    }
                 }
                
                
                }
                        	
        }    
  
 if(!flag && !instru && flagContinue )
 {
 window.clear();
 window.draw(background);
 window.draw(logoSprite);
 draw(window);
 window.display();
 }
 else
 {
  if(instru)
  {
    b.loadFromFile("img/instructions.png");
     background.setTexture(b); 
     background.setScale(1,1);
      
      window.clear();
      window.draw(background);

      if(e.key.code == Keyboard::BackSpace)
      {
        b.loadFromFile("img/phases/menu.png");
        background.setTexture(b);
        background.setScale(1, 1.2);
        instru = false;
      }
      window.display();     
  }

 else 
 break;
 
 }
 }


 if(flag)
 {
    return true; 
 }
 else if(!flagContinue)
 return false;

 else
 return false;
 
 
}



int pauseMenu::IndexSelected = 0;



