#include "Score.h"

Score::Score() : foodEaten(1), timePlayed(0.0f) {}

void Score::increaseFoodEaten() {
    foodEaten++;
}

void Score::updateTimePlayed(float deltaTime) {
    timePlayed += deltaTime;
}

int Score::calculateScore() const {
    // Adjust the calculation to provide a non-zero score early on
    return static_cast<int>((foodEaten + timePlayed));
}

int Score::getFoodEaten() const {
    return foodEaten;
}

float Score::getTimePlayed() const {
    return timePlayed;
}
