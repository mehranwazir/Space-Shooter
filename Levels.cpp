#include "Levels.h"


Levels::Levels()
{
l[0].loadFromFile("img/level1.png");
level[0].setTexture(l[0]);
level[0].setScale(1,1);
level[0].setPosition(60,260);

l[1].loadFromFile("img/level2.png");
level[1].setTexture(l[1]);
level[1].setScale(1,1);
level[1].setPosition(60,260);

l[2].loadFromFile("img/level3.png");
level[2].setTexture(l[2]);
level[2].setScale(1,1);
level[2].setPosition(60,260);


phase1_tex.loadFromFile("img/123.png");
phase1_back.setTexture(phase1_tex);
phase1_back.setScale(1, 1.25);

phase2_tex.loadFromFile("img/phase1_background.png"); 
phase2_back.setTexture(phase2_tex);
phase2_back.setScale(1.25, 1.25);

phase3_tex.loadFromFile("img/phase2_background.png"); 
phase3_back.setTexture(phase3_tex);
phase3_back.setScale(1.25, 1.25);

phase = 1;
gameLevel = 1;
phaseChange = false;
once = true;

phase_texture[0].loadFromFile("img/phase1.png");
 phase_img[0].setTexture(phase_texture[0]);
 phase_img[0].setScale(1,1);
 phase_img[0].setPosition(60,320);



 phase_texture[1].loadFromFile("img/phase2.png");
 phase_img[1].setTexture(phase_texture[1]);
 phase_img[1].setScale(1,1);
 phase_img[1].setPosition(60,320);


 phase_texture[2].loadFromFile("img/phase3.png");
 phase_img[2].setTexture(phase_texture[2]);
 phase_img[2].setScale(1,1);
 phase_img[2].setPosition(60,320);


 //Textures for level 3

level3_Texture[0].loadFromFile("img/phases/1.png");
level3_sprites[0].setTexture(level3_Texture[0]);
level3_sprites[0].setScale(1, 1);

level3_Texture[1].loadFromFile("img/phases/2.jpeg");
level3_sprites[1].setTexture(level3_Texture[1]);
level3_sprites[1].setScale(1, 1);

level3_Texture[2].loadFromFile("img/phases/3.jpeg");
level3_sprites[2].setTexture(level3_Texture[2]);
level3_sprites[2].setScale(1.5, 1);

level3_Texture[3].loadFromFile("img/phases/4.jpeg");
level3_sprites[3].setTexture(level3_Texture[3]);
level3_sprites[3].setScale(1, 1);


level3_Texture[4].loadFromFile("img/phases/5.jpeg");
level3_sprites[4].setTexture(level3_Texture[4]);
level3_sprites[4].setScale(1, 0.5);

level3_Texture[5].loadFromFile("img/phases/6.jpeg");
level3_sprites[5].setTexture(level3_Texture[5]);
level3_sprites[5].setScale(1, 1);
}


void Levels::DisplayLevels(Enemy **enemy, float &timer, float &t, float &bombDelay, float &time)
{

        
  // =========JIGGLING EFFECT===========
          float amplitude = 1.5f; // The maximum amount of movement in pixels
          float period = 1.25f; // The number of seconds it takes for a complete oscillation
          float x_offset = amplitude * cos(2 * M_PI * timer / period);
          float y_offset = amplitude * sin(2 * M_PI * timer / period);
 //=======================================================
  
 
   
  //LEVEL
  if(phase == 1 && gameLevel == 1  )
  {
  //RECTANGLE
  
 

  enemy[0]->SetPosition(85+x_offset,100+y_offset);  //alpha
  enemy[8]->SetPosition(145+x_offset,80+y_offset);  //beta
  enemy[1]->SetPosition(205+x_offset,100+y_offset); //alpha
  enemy[2]->SetPosition(265+x_offset,100+y_offset); //alpha
  enemy[9]->SetPosition(325+x_offset,80+y_offset);  //beta
  enemy[3]->SetPosition(385+x_offset,100+y_offset); //alpha
  
  enemy[12]->SetPosition(90+x_offset,160+y_offset); //gamma
  
  enemy[4]->SetPosition(85+x_offset,220+y_offset);  //alpha
  enemy[10]->SetPosition(145+x_offset,210+y_offset); //beta
  enemy[5]->SetPosition(200+x_offset,220+y_offset); //alpha
  enemy[6]->SetPosition(260+x_offset,220+y_offset); //alpha
  enemy[11]->SetPosition(325+x_offset,210+y_offset); //beta
  enemy[7]->SetPosition(380+x_offset,220+y_offset); //alpha
  
  enemy[13]->SetPosition(385+x_offset,160+y_offset); //gamma
   
  //SetLevel("img/level1.png");
  //setPhase("img/phase1.png");
  }
  
  else if(phase == 2 && gameLevel == 1 )
  {
        if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }
    

  enemy[0]->SetPosition(150+x_offset,100+y_offset);  //alpha
  enemy[8]->SetPosition(190+x_offset,40+y_offset);  //beta
  enemy[1]->SetPosition(220+x_offset,10+y_offset); //alpha
  enemy[2]->SetPosition(265+x_offset,40+y_offset); //alpha
  enemy[9]->SetPosition(305+x_offset,70+y_offset);  //beta
  enemy[3]->SetPosition(335+x_offset,125+y_offset); //alpha
  
  enemy[12]->SetPosition(120+x_offset,160+y_offset); //gamma
  
  enemy[4]->SetPosition(85+x_offset,220+y_offset);  //alpha
  enemy[10]->SetPosition(145+x_offset,210+y_offset); //beta
  enemy[5]->SetPosition(200+x_offset,220+y_offset); //alpha
  enemy[6]->SetPosition(260+x_offset,220+y_offset); //alpha
  enemy[11]->SetPosition(325+x_offset,210+y_offset); //beta
  enemy[7]->SetPosition(380+x_offset,220+y_offset); //alpha
  
  enemy[13]->SetPosition(375+x_offset,175+y_offset); //gamma
   

  
 // displayLevel("img/level2.png");
  //setPhase("img/phase2.png");  
  
  }
  
  else if(phase == 3 && gameLevel==1) 
  {
            if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }
    
   
  enemy[0]->SetPosition(105+x_offset,335+y_offset);  //alpha
  enemy[8]->SetPosition(155+x_offset,285+y_offset);  //beta
  
  enemy[1]->SetPosition(220+x_offset,210+y_offset); //alpha_center
  
  enemy[2]->SetPosition(65+x_offset,65+y_offset); //alpha
  
  
  enemy[9]->SetPosition(330+x_offset,70+y_offset);  //beta
  enemy[3]->SetPosition(295+x_offset,125+y_offset); //alpha
  
  enemy[12]->SetPosition(185+x_offset,255+y_offset); //gamma //no
  
  enemy[4]->SetPosition(100+x_offset,100+y_offset);  //alpha //no
  enemy[10]->SetPosition(145+x_offset,130+y_offset); //beta //no
  enemy[5]->SetPosition(190+x_offset,180+y_offset); //alpha
  enemy[6]->SetPosition(260+x_offset,240+y_offset); //alpha
  enemy[11]->SetPosition(310+x_offset,260+y_offset); //beta
  enemy[7]->SetPosition(350+x_offset,305+y_offset); //alpha
  
  enemy[13]->SetPosition(260+x_offset,165+y_offset); //gamma //no
 
   
  //displayLevel("img/level3.png");
   // setPhase("img/phase3.png");
  }

  //HEART
 else if(phase==1 && gameLevel==2 )
 {
   if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }
    
  enemy[12]->SetPosition(240+x_offset,60+y_offset); //gamma
  enemy[8]->SetPosition(310+x_offset,20+y_offset);  //beta
  enemy[1]->SetPosition(375+x_offset,30+y_offset); //alpha
  enemy[2]->SetPosition(415+x_offset,80+y_offset); //alpha
  enemy[9]->SetPosition(420+x_offset,145+y_offset);  //beta
  enemy[0]->SetPosition(375+x_offset,205+y_offset);  //alpha
  enemy[4]->SetPosition(330+x_offset,255+y_offset);  //alpha
  enemy[13]->SetPosition(250+x_offset,310+y_offset); //gamma
  

  enemy[5]->SetPosition(180+x_offset,255+y_offset);  //alpha
  enemy[10]->SetPosition(135+x_offset,200+y_offset); //beta
  enemy[6]->SetPosition(90+x_offset,160+y_offset); //alpha
  enemy[7]->SetPosition(85+x_offset,85+y_offset); //alpha
  enemy[11]->SetPosition(180+x_offset,20+y_offset); //beta
  enemy[3]->SetPosition(120+x_offset,30+y_offset); //alpha
  
  //SetLevel("img/level2.png");
  //setPhase("img/phase1.png");
 }

 else if(phase==2 && gameLevel == 2)
 {

     if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }

  //DIAMOND
  enemy[13]->SetPosition(185+x_offset,290+y_offset); //gamma
  enemy[5]->SetPosition(130+x_offset,240+y_offset);  //alpha
  enemy[4]->SetPosition(90+x_offset,180+y_offset);  //alpha
  enemy[10]->SetPosition(50+x_offset,110+y_offset); //beta
  enemy[0]->SetPosition(80+x_offset,60+y_offset);  //alpha
  enemy[8]->SetPosition(135+x_offset,50+y_offset);  //beta
  enemy[1]->SetPosition(190+x_offset,60+y_offset); //alpha
  
  enemy[12]->SetPosition(250+x_offset,60+y_offset); //gamma
  
  enemy[2]->SetPosition(310+x_offset,60+y_offset); //alpha
  enemy[9]->SetPosition(365+x_offset,50+y_offset);  //beta
  enemy[11]->SetPosition(395+x_offset,110+y_offset); //beta
   
  enemy[6]->SetPosition(345+x_offset,180+y_offset); //alpha
  enemy[7]->SetPosition(310+x_offset,240+y_offset); //alpha
  
  enemy[3]->SetPosition(260+x_offset,290+y_offset); //alpha
  
 // displayPhase("img/phase2.png");
 }
  
  //CIRCLE
  
  else if(phase == 3 && gameLevel == 2)
  {

    if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }

  enemy[13]->SetPosition(240+x_offset,20+y_offset); //gamma
  enemy[5]->SetPosition(310+x_offset,40+y_offset);  //alpha
  enemy[4]->SetPosition(360+x_offset,90+y_offset);  //alpha
  enemy[10]->SetPosition(380+x_offset,150+y_offset); //beta 
  enemy[6]->SetPosition(370+x_offset,230+y_offset);  //alpha
  enemy[8]->SetPosition(340+x_offset,280+y_offset);  //beta
  enemy[0]->SetPosition(270+x_offset,315+y_offset);  //alpha
  enemy[12]->SetPosition(210+x_offset,330+y_offset); //gamma
  enemy[1]->SetPosition(140+x_offset,310+y_offset); //alpha
  enemy[9]->SetPosition(100+x_offset,245+y_offset);  //beta
  enemy[2]->SetPosition(80+x_offset,185+y_offset); //alpha
  enemy[7]->SetPosition(80+x_offset,120+y_offset); //alpha
  enemy[11]->SetPosition(110+x_offset,45+y_offset); //beta
  enemy[3]->SetPosition(160+x_offset,30+y_offset); //alpha

 //displayPhase("img/phase3.png");
  }


  
  //FILLED RECTANGLE
 
 else if(phase == 1 && gameLevel == 3)
  {

    if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }

  enemy[0]->SetPosition(85+x_offset,100+y_offset);  //alpha
  enemy[8]->SetPosition(165+x_offset,145+y_offset);  //beta
  enemy[1]->SetPosition(170+x_offset,100+y_offset); //alpha
  enemy[2]->SetPosition(265+x_offset,100+y_offset); //alpha
  enemy[9]->SetPosition(230+x_offset,145+y_offset);  //beta
  enemy[3]->SetPosition(385+x_offset,100+y_offset); //alpha
  
  enemy[12]->SetPosition(90+x_offset,160+y_offset); //gamma
  
  enemy[4]->SetPosition(85+x_offset,220+y_offset);  //alpha
  enemy[10]->SetPosition(145+x_offset,210+y_offset); //beta
  enemy[5]->SetPosition(215+x_offset,220+y_offset); //alpha
  enemy[6]->SetPosition(290+x_offset,220+y_offset); //alpha
  enemy[11]->SetPosition(310+x_offset,145+y_offset); //beta
  enemy[7]->SetPosition(380+x_offset,220+y_offset); //alpha
  
  enemy[13]->SetPosition(385+x_offset,160+y_offset); //gamma
}

//FILLED TRIANGLE 

 else if(phase == 2 && gameLevel == 3)
  {

    if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }
 enemy[0]->SetPosition(150+x_offset,100+y_offset);  //alpha
  enemy[8]->SetPosition(190+x_offset,40+y_offset);  //beta
  enemy[1]->SetPosition(220+x_offset,10+y_offset); //alpha
  enemy[2]->SetPosition(230+x_offset,90+y_offset); //alpha
  enemy[9]->SetPosition(280+x_offset,40+y_offset);  //beta
  enemy[3]->SetPosition(320+x_offset,110+y_offset); //alpha
  
  enemy[12]->SetPosition(120+x_offset,160+y_offset); //gamma
  
  enemy[4]->SetPosition(85+x_offset,220+y_offset);  //alpha
  enemy[10]->SetPosition(180+x_offset,210+y_offset); //beta
  enemy[5]->SetPosition(190+x_offset,160+y_offset); //alpha
  enemy[6]->SetPosition(270+x_offset,160+y_offset); //alpha
  enemy[11]->SetPosition(290+x_offset,210+y_offset); //beta
  enemy[7]->SetPosition(380+x_offset,220+y_offset); //alpha
  
  enemy[13]->SetPosition(360+x_offset,160+y_offset); //gamma
}

//CROSS SIGN

 else if(phase == 3 && gameLevel == 3)
  {

    if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }

enemy[0]->SetPosition(120+x_offset,315+y_offset);  //alpha
  enemy[8]->SetPosition(175+x_offset,265+y_offset);  //beta
  
  enemy[1]->SetPosition(230+x_offset,295+y_offset); //alpha_center
  
  enemy[2]->SetPosition(210+x_offset,125+y_offset); //alpha
  
  
  enemy[9]->SetPosition(330+x_offset,70+y_offset);  //beta
  enemy[3]->SetPosition(295+x_offset,125+y_offset); //alpha
  
  enemy[12]->SetPosition(195+x_offset,235+y_offset); //gamma //no
  
  enemy[4]->SetPosition(100+x_offset,100+y_offset);  //alpha //no
  enemy[10]->SetPosition(145+x_offset,130+y_offset); //beta //no
  enemy[5]->SetPosition(190+x_offset,180+y_offset); //alpha
  enemy[6]->SetPosition(260+x_offset,240+y_offset); //alpha
  enemy[11]->SetPosition(310+x_offset,260+y_offset); //beta
  enemy[7]->SetPosition(350+x_offset,305+y_offset); //alpha
  
  enemy[13]->SetPosition(260+x_offset,165+y_offset); //gamma //no

}


//FILLED HEART

 else if(phase == 4 && gameLevel == 3)
  {

    if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }
  enemy[12]->SetPosition(240+x_offset,85+y_offset); //gamma
  enemy[8]->SetPosition(310+x_offset,20+y_offset);  //beta
  enemy[1]->SetPosition(375+x_offset,30+y_offset); //alpha
  enemy[2]->SetPosition(415+x_offset,95+y_offset); //alpha
  enemy[9]->SetPosition(350+x_offset,115+y_offset);  //beta
  enemy[0]->SetPosition(390+x_offset,180+y_offset);  //alpha
  enemy[4]->SetPosition(330+x_offset,255+y_offset);  //alpha
  enemy[13]->SetPosition(250+x_offset,310+y_offset); //gamma
  

  enemy[5]->SetPosition(170+x_offset,240+y_offset);  //alpha
  enemy[10]->SetPosition(240+x_offset,200+y_offset); //beta
  enemy[6]->SetPosition(90+x_offset,160+y_offset); //alpha
  enemy[7]->SetPosition(85+x_offset,85+y_offset); //alpha
  enemy[11]->SetPosition(165+x_offset,20+y_offset); //beta
  enemy[3]->SetPosition(160+x_offset,115+y_offset); //alpha
}

//FILLED DIAMOND

 else if(phase == 5 && gameLevel == 3)
  {

    if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }
  enemy[13]->SetPosition(220+x_offset,290+y_offset); //gamma
  enemy[5]->SetPosition(130+x_offset,240+y_offset);  //alpha
  enemy[4]->SetPosition(90+x_offset,180+y_offset);  //alpha
  enemy[10]->SetPosition(50+x_offset,125+y_offset); //beta
  enemy[0]->SetPosition(80+x_offset,60+y_offset);  //alpha
  enemy[8]->SetPosition(150+x_offset,110+y_offset);  //beta
  enemy[1]->SetPosition(175+x_offset,60+y_offset); //alpha
  
  enemy[12]->SetPosition(265+x_offset,60+y_offset); //gamma
  
  enemy[2]->SetPosition(290+x_offset,115+y_offset); //alpha
  enemy[9]->SetPosition(365+x_offset,50+y_offset);  //beta
  enemy[11]->SetPosition(395+x_offset,110+y_offset); //beta
   
  enemy[6]->SetPosition(345+x_offset,180+y_offset); //alpha
  enemy[7]->SetPosition(310+x_offset,240+y_offset); //alpha
  
  enemy[3]->SetPosition(225+x_offset,200+y_offset); //alpha

  }

  //FILLED CIRCLE

  else if(phase == 6 && gameLevel == 3)
  {
      if(timer>t && phaseChange)
      {  
        phaseChange = false;
      }
      
       enemy[14]-> DisplayMD(time);

  }

   else if(phase == 7 && gameLevel == 3)
  {

    if(timer>t && phaseChange)
        {

         for(int i=0; i<14; i++) 
        enemy[i]->setHit(1);
       
        phaseChange = false;
        //t = timer+4;
        // bombDelay = timer+6;
        }
  enemy[13]->SetPosition(240+x_offset,20+y_offset); //gamma
  enemy[5]->SetPosition(310+x_offset,40+y_offset);  //alpha
  enemy[4]->SetPosition(360+x_offset,90+y_offset);  //alpha
  enemy[10]->SetPosition(380+x_offset,150+y_offset); //beta 
  enemy[6]->SetPosition(370+x_offset,230+y_offset);  //alpha
  enemy[8]->SetPosition(320+x_offset,295+y_offset);  //beta

  enemy[0]->SetPosition(290+x_offset,240+y_offset);  //alpha

  enemy[12]->SetPosition(210+x_offset,330+y_offset); //gamma
  enemy[1]->SetPosition(290+x_offset,100+y_offset); //alpha
  enemy[9]->SetPosition(120+x_offset,265+y_offset);  //beta
  enemy[2]->SetPosition(80+x_offset,185+y_offset); //alpha
  enemy[7]->SetPosition(80+x_offset,120+y_offset); //alpha
  enemy[11]->SetPosition(170+x_offset,150+y_offset); //beta
  enemy[3]->SetPosition(140+x_offset,40+y_offset); //alpha
}

else if(phase == 8 && gameLevel == 3)
{ 
  if(timer>t && phaseChange)
  phaseChange = false;

  
  enemy[15] -> DisplayMD(time);
}


 

}