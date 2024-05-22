#include "HowToPlay.h"
#include <iostream>

// Constructor to initialize the HowToPlay window
HowToPlay::HowToPlay(float width, float height) {
    // Load the font
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

    // Set up the How To Play text
    howToPlayText.setFont(font);
    howToPlayText.setCharacterSize(24);
    howToPlayText.setFillColor(sf::Color::White);
    howToPlayText.setString(
        "Aim: Get the Highest Score Possible\n\n"
        "HOW TO PLAY:\n\n"
        "Use arrow keys to move the snake.\n"
        "Eat red food items to gain 1 point.\n"
        "Eat yellow food items to gain 3 point.\n"
        "Avoid colliding with the walls or yourself.\n"
    );
    howToPlayText.setPosition(45, 50);

    // Set up the Close text
    closeText.setFont(font);
    closeText.setCharacterSize(30);
    closeText.setFillColor(sf::Color::Red);
    closeText.setString("Press M to return to main menu");
    closeText.setPosition(width / 2 - closeText.getGlobalBounds().width / 2, height - 50);
}

// Draw the HowToPlay window on the provided window
void HowToPlay::draw(sf::RenderWindow& window) {
    window.draw(howToPlayText);
    window.draw(closeText);
}
