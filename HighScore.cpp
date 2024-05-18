#include "HighScore.h"

// Constructor to accept filename
HighScore::HighScore(const std::string& file) : filename(file), highestScore(0) {
    loadHighScore();
}

void HighScore::loadHighScore() {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> highestScore;
        file.close();
    } else {
        std::cerr << "Error loading high score file\n";
    }
}

void HighScore::saveHighScore() {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << highestScore;
        file.close();
    } else {
        std::cerr << "Error saving high score file\n";
    }
}

void HighScore::wipeHighScore() {
    highestScore = 0;
    saveHighScore();
}

int HighScore::getHighScore() {
    return highestScore;
}

void HighScore::setHighScore(int highscore) {
    this->highestScore = highscore;
    saveHighScore();
}