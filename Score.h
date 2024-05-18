#ifndef SCORE_H
#define SCORE_H

// Responsible for setting and calculating the score of the user dependent on
// food eaten

class Score {
public:
    Score();

    // Increase the food eaten count by 1
    void increaseFoodEaten();

    // Calculate the overall score
    int calculateScore() const;

    // Get the number of foods eaten
    int getFoodEaten() const;


    void reset();

    virtual int getHighScore(){return calculateScore();}; // virtual function to return high score.

private:
    int foodEaten;
};

#endif // SCORE_H