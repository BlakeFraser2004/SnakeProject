#ifndef SCORE_H
#define SCORE_H

// Responsible for setting and calculating the score of the user dependent on
// time lasted and food eaten

class Score {
public:
    Score();

    // Increase the food eaten count by 1
    void increaseFoodEaten();

    // Update the time played
    void updateTimePlayed(float deltaTime);

    // Calculate the overall score
    int calculateScore() const;

    // Get the number of foods eaten
    int getFoodEaten() const;

    // Get the time played
    float getTimePlayed() const;
private:
    int foodEaten;
    float timePlayed;
};

#endif // SCORE_H
