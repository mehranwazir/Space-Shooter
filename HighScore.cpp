#include "HighScore.h"




HighScore::HighScore()
{    
    bg.loadFromFile("img/ranks/background.png");
    background.setTexture(bg);

    rank_texture[0].loadFromFile("img/ranks/gold.png");
    rank_sprite[0].setTexture(rank_texture[0]);
    rank_sprite[0].setPosition(50,100);
    
    rank_texture[1].loadFromFile("img/ranks/silver.png");
    rank_sprite[1].setTexture(rank_texture[1]);
    rank_sprite[1].setPosition(50,275);

    rank_texture[2].loadFromFile("img/ranks/bronze.png");
    rank_sprite[2].setTexture(rank_texture[2]);
    rank_sprite[2].setPosition(50,450);

        
        font.loadFromFile("CrimaDisplay.otf");
        playerText[0].setFont(font);
        playerText[0].setCharacterSize(20);
        playerText[0].setFillColor(Color::Yellow);
        playerText[0].setPosition(200, 145);


  
        playerText[1].setFont(font);
        playerText[1].setCharacterSize(20);
        playerText[1].setFillColor(Color::Yellow);
        playerText[1].setPosition(200, 320);

        playerText[2].setFont(font);
        playerText[2].setCharacterSize(20);
        playerText[2].setFillColor(Color::Yellow);
        playerText[2].setPosition(200, 495);

}



void HighScore::LoadPlayerData()
{
 ifstream inFile("data.txt");
    
    if (inFile.is_open())
    {
        
        string line;
        string displayText[3];
        
        string topPlayer1 = "";
        unsigned short topScore1 = 0;
        string topPlayer2 = "";
        unsigned short topScore2 = 0;
        string topPlayer3 = "";
        unsigned short topScore3 = 0;

        while (getline(inFile, line))
        {
            string name;
            unsigned short score;
            stringstream ss(line);
            getline(ss, name, ',');
            ss >> score;

            // Update top players
            if (score > topScore1)
            {
                topScore3 = topScore2;
                topPlayer3 = topPlayer2;
                topScore2 = topScore1;
                topPlayer2 = topPlayer1;
                topScore1 = score;
                topPlayer1 = name;
            }
            else if (score > topScore2)
            {
                topScore3 = topScore2;
                topPlayer3 = topPlayer2;
                topScore2 = score;
                topPlayer2 = name;
            }
            else if (score > topScore3)
            {
                topScore3 = score;
                topPlayer3 = name;
            }
        }
        inFile.close();

        displayText[0] += "1. NAME: " + topPlayer1 + "\n    SCORE: " + std::to_string(topScore1) + "\n";
        displayText[1] += "2. NAME: " + topPlayer2 + "\n    SCORE: " + std::to_string(topScore2) + "\n";
        displayText[2] += "3. NAME: " + topPlayer3 + "\n    SCORE: " + std::to_string(topScore3) + "\n";

        playerText[0].setString(displayText[0]);
        playerText[1].setString(displayText[1]);
        playerText[2].setString(displayText[2]);
    }
    else
    {
        cerr << "Failed to open the file for reading." << std::endl;
    }


} // End

void HighScore::highscore(RenderWindow &window)
{

    bool DataLoaded = false;

while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {               
                 if(event.key.code == sf::Keyboard::BackSpace)
                return;
            }
        }

        if(!DataLoaded)
         {
            LoadPlayerData();
            DataLoaded = true;
         }
        window.clear();
        window.draw(background);

        for(int i=0; i<3; i++)
        window.draw(rank_sprite[i]);
       
        if(DataLoaded)
        {   
            for(int i=0; i<3; i++)
            window.draw(playerText[i]);
        }
        window.display();

    }

}

