#include "Score.h"

Score::Score() : foodEaten(1) {} // Initalise foodEaten to 1

void Score::increaseFoodEaten() {
    foodEaten++;
}

int Score::calculateScore() const {
    // Adjust the calculation to provide a non-zero score early on
    return static_cast<int>((foodEaten));
}

int Score::getFoodEaten() const {
    return foodEaten;
}

void Score::reset() {
    foodEaten = 0;
}