#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "Score.h"

class HighScore : public Score {
    private:
        int highestScore;

    public:
        HighScore(); // 
      //  void calculateHighScore(); // Function to calculate high score MOVED TO MAIN
        void setHighScore(int highscore);
        int getHighScore(); // Returns high score
};


#endif