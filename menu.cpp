#include "menu.h"

int Menu::IndexSelected = 0;

Menu::Menu()
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
Menu::Menu(float width, float height)
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
  menu[0].setString("PLAY");
  menu[0].setCharacterSize(42);
  menu[0].setPosition(width/2-90, height/(MAX_ITEMS+1)*1+20);

  menu[1].setFont(font);
  menu[1].setColor(Color::White);
  menu[1].setString("INSTRUCTIONS");
  menu[1].setCharacterSize(42);
  menu[1].setPosition(width/2-90, (height/(MAX_ITEMS+1)*2)-35);
  
  menu[2].setFont(font);
  menu[2].setColor(Color::White);
  menu[2].setString("HIGH SCORE");
  menu[2].setCharacterSize(42);
  menu[2].setPosition(width/2-90, (height/(MAX_ITEMS+1)*3)-80);  

  menu[3].setFont(font);
  menu[3].setColor(Color::White);
  menu[3].setString("EXIT");
  menu[3].setCharacterSize(42);
  menu[3].setPosition(width/2-90, (height/(MAX_ITEMS+1)*4)-150+20);  



 Instruction_tex.loadFromFile("img/instructions.png");
 Instructions.setTexture(Instruction_tex);
  
  
}

void Menu::MoveUp()
{
  if(IndexSelected - 1 >= 0)
  {
     menu[IndexSelected].setColor(Color::White);
     IndexSelected--;
     menu[IndexSelected].setColor(Color::Yellow);
  
  }
}

void Menu::MoveDown()
{
  if(IndexSelected + 1 < MAX_ITEMS)
  {
     menu[IndexSelected].setColor(Color::White);
     IndexSelected++;
     menu[IndexSelected].setColor(Color::Yellow);
  }
}



void Menu::draw(RenderWindow &window)
{
for(int i=0; i<MAX_ITEMS; i++)
 window.draw(menu[i]);
}




void Menu::display_menu()

{

RenderWindow window(VideoMode(500,680),"MENU");
 
 bool flag = false;
 bool instru = false;
 Menu m(500, 680);
 
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
                   m.MoveUp();

                 }
                 
                 else if(e.key.code == Keyboard::Down)
                 {
                  m.MoveDown();
                  
                 }
                 
                 else if(e.key.code == Keyboard::Return)
                 {  
                 
                     
                    if(IndexSelected == 0)
                    {
                    flag = true;
                    //window.close();
             
                    }
                    
                    else if(IndexSelected == 1)
                    { 
                      // window.draw(Instructions);
                       instru = true;
                      //instructions(window);
                      
                    }
                    
                    
                    else if(IndexSelected == 2)
                    {
                      score.highscore(window);                       
                    }

                    else if(IndexSelected == 3)
                    {
                      flag = false;
                     window.close();
                    }
                 
                 }
                
                
                }
                        	
        }    
  
 if(!flag && !instru)
 { 
 window.clear();
 window.draw(background);
 window.draw(logoSprite);
 m.draw(window);
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
      window.display();                      //instructions(window);
   }

    else if(flag)
    {
    Game g;     
    g.start_game(window);
    }
 }

}

}


void Menu::display_menu(RenderWindow &window)
 {
  

 bool flag = false;
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
                    flag = true;
                    //window.close();
             
                    }
                    
                    else if(IndexSelected == 1)
                    { 
                      //window.draw(Instructions);
                       instru = true;
                      //instructions(window);
                      
                    }
                    
                    else if(IndexSelected == 2)
                    {
                      score.highscore(window);
                    }
                    
                    else if(IndexSelected == 3)
                    {
                     flag = false;
                     window.close();
                    } 
                 }
                
                
                }
                        	
        }    
  
if(!flag && !instru)
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

  else if(flag)
  {
    Game g;     
    g.start_game(window);
    }
 
    }
 
}

 }