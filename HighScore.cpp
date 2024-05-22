#include "HighScore.h"

// Constructor to accept filename
HighScore::HighScore(const std::string& file) : filename(file), highestScore(new int(0)) {
    //Load the previous high score from the file.
    loadHighScore();
}

// Destructor to clean up dynamic memory
HighScore::~HighScore() {
    saveHighScore();
    delete highestScore;
}

// This function loads the high score from the file.
void HighScore::loadHighScore() {
    //Opens the file containing 
    std::ifstream file(filename);
    if (file.is_open()) {
        //Reads the high score from within the file.
        file >> *highestScore;
        file.close();
    } else {
        //Displays an error message if the file cannot open. 
        std::cerr << "Error loading high score file\n";
    }
}

// This function saves the high score to the file.
void HighScore::saveHighScore() {
    // Opens the file for writing
    std::ofstream file(filename);
    if (file.is_open()) {
        // Writes the high score into the file.
        file << *highestScore;
        file.close();
    } else {
        // Displays an error message if the high score cannot be saved into the file.
        std::cerr << "Error saving high score file\n";
    }
}

// This function resets the high score to zero.
void HighScore::wipeHighScore() {
    // Sets highscore to zero.
    *highestScore = 0;
    // Saves the current high score to file.
    saveHighScore();
}

// This function retrieves the current high score.
int HighScore::getHighScore() {
    return *highestScore;
}

// This function sets the new high score.
void HighScore::setHighScore(int highscore) {
    // Sets the high score to the specified value.
    *highestScore = highscore;
    // Save the update high score to the file.
    saveHighScore();
}
