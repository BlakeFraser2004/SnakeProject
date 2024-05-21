#include "Score.h"

// Constructor initializes foodEaten to 0
Score::Score() : foodEaten(0) {}

// Increase the count of food eaten by 1
void Score::increaseFoodEaten() {
    foodEaten++;
}

// Calculate the score based on the number of food eaten
int Score::calculateScore() const {
    // Adjust the calculation to provide a non-zero score early on
    return static_cast<int>(foodEaten);
}

// Get the number of food eaten
int Score::getFoodEaten() const {
    return foodEaten;
}

// Reset the count of food eaten to 0
void Score::reset() {
    foodEaten = 0;
}