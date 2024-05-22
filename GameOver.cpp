#include "GameOver.h"
#include <iostream>

// Constructor for the GameOver screen.
// Initializes text objects with provided width and height.
GameOver::GameOver(float width, float height) {
    // Load font file
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
    }
    
    // Set up game over text
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("GAME OVER!!!");
    gameOverText.setPosition(width / 2 - gameOverText.getGlobalBounds().width / 2, height / 3);

    // Set up return to menu text
    returnToMenuText.setFont(font);
    returnToMenuText.setCharacterSize(24);
    returnToMenuText.setFillColor(sf::Color::White);
    returnToMenuText.setString("Press M to return to Main Menu");
    returnToMenuText.setPosition(width / 2 - returnToMenuText.getGlobalBounds().width / 2, height / 2);
}

// Draw the game over screen on the provided window.
void GameOver::draw(sf::RenderWindow &window) {
    window.draw(gameOverText);
    window.draw(returnToMenuText);
}

// Handle input events for the game over screen.
// Returns true if 'M' key is pressed to return to main menu, false otherwise.
bool GameOver::handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
            return true; // Return to main menu
        }
    }
    return false; // Continue showing game over screen
}
