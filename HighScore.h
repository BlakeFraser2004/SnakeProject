
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "Score.h"
#include <fstream>
#include <iostream>
#include <string>

class HighScore : public Score {
private:
    std::string filename; // Reorder this
    int highestScore;     // Reorder this

public:
    HighScore(const std::string& file); // Constructor to accept file name
    void loadHighScore(); // Function to load high score from file
    void saveHighScore(); // Function to save high score to file
    void wipeHighScore(); // Function to wipe high score

    void setHighScore(int highscore);
    int getHighScore(); // Returns high score
};

#endif
