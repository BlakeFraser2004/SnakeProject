#include "HighScore.h"

// Default Constructor for highScore. Initialises the High Score to 0.
HighScore::HighScore() : highestScore(0){};

int HighScore::getHighScore()
{
    return highestScore;
}

void HighScore::setHighScore(int highscore)
{
    this->highestScore = highscore;
}