// GameOver.cpp

#include "GameOver.h"
#include <iostream>

// Constructor to initialize the GameOver screen
GameOver::GameOver(float width, float height) {
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

// Draw the GameOver screen on the provided window
void GameOver::draw(sf::RenderWindow &window) {
    window.draw(gameOverText);
    window.draw(returnToMenuText);
}

// Handle input events for the GameOver screen
bool GameOver::handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
            return true;
        }
    }
    return false;
}

