#include <iostream>
#include "HighScore.h" // Include your HighScore class header

int main() {
    // Create HighScore instance with filename "highscore.txt"
    HighScore highScore("highscore.txt");

    // Load and display the initial high score
    std::cout << "Initial High Score: " << highScore.getHighScore() << std::endl;

    std::cout <<"Player scored 100"<<std::endl;
    // Set a new high score and save it
    highScore.setHighScore(100);
    std::cout << "New High Score: " << highScore.getHighScore() << std::endl;

    // Wipe the high score and display
    highScore.wipeHighScore();
    std::cout << "High Score After Wipe: " << highScore.getHighScore() << std::endl;

    return 0;
}
