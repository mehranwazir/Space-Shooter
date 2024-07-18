#include "PlayerData.h"


void PlayerData::setPlayerName(string name)
{
    PlayerName = name;
}

string PlayerData::getPlayerName()const
{
    return PlayerName;
}

void PlayerData::setHighScore(int score)
{
    HighScore = score;
}

int PlayerData::getHighScore()const 
{
    return HighScore;
}

  void PlayerData::SaveData(const string& fileName)
  {

  ofstream outFile(fileName, ios::app);
    if (outFile.is_open())
    {
        outFile << PlayerName << "," << HighScore << endl;
        outFile.close();
        cout << "Player data saved to " << fileName << endl;
    }
    else
    {
        cout << "Failed to open the file for writing." << endl;
    }

  }

