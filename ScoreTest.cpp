#include <iostream>
#include "Score.h"

int main() {
    // Create Score instance.
    Score score;

    // Simulate some gameplay
    // Increase food eaten count
    score.increaseFoodEaten();
    // Increase food eaten count again
    score.increaseFoodEaten();

    // Get and display score.
    int finalScore = score.calculateScore();
    std::cout << "Final Score: " << finalScore << std::endl;

    // Get and display food eaten.
    int foodsEaten = score.getFoodEaten();
    std::cout << "Foods Eaten: " << foodsEaten << std::endl;

    // Reset score and display values again.
    score.reset();
    finalScore = score.calculateScore();
    foodsEaten = score.getFoodEaten();
    std::cout << "\nAfter Reset:\n";
    std::cout << "Final Score: " << finalScore << std::endl;
    std::cout << "Foods Eaten: " << foodsEaten << std::endl;

    return 0;
}
