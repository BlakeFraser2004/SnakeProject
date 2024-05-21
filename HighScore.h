#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "Score.h"
#include <fstream>
#include <iostream>
#include <string>


//The HighScore class inherits from the Score class and manages high scores, including loading, saving, resetting, highscores.
class HighScore : public Score {
private:
    //The name of the file where the high score is saved.
    std::string filename;
    // Records the highest score achieved.
    int highestScore;     

public:
    //Constructor that initializes the high score file.
    HighScore(const std::string& file);
    // Function to load high score from file
    void loadHighScore(); 
    // Function to save high score to the file
    void saveHighScore();
    // Function to reset the high score to zero and save it to the file.
    void wipeHighScore();
    //Sets a new high score and saves it to the file.
    void setHighScore(int highscore);
    // Returns high score.
    int getHighScore();
};

#endif