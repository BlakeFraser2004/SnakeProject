
#ifndef SCORE_H
#define SCORE_H

// The Score Class is responsible for managing the score of the user based on food eaten
class Score {
public:
    // Constructor to initialize the Score object
    Score();

    // Increase the count of food eaten by 1
    void increaseFoodEaten();

    // Calculate the overall score based on food eaten
    int calculateScore() const;

    // Get the number of foods eaten
    int getFoodEaten() const;

    // Reset the food eaten count to zero
    void reset();

    // Virtual function to return the high score
    virtual int getHighScore() { return calculateScore(); };

private:
    int foodEaten; // Count of foods eaten
};

#endif // SCORE_H
