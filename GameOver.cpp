#include "GameOver.h"
#include <iostream>

GameOver::GameOver(float width, float height) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
    }
    
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("GAME OVER!!!");
    gameOverText.setPosition(width / 2 - gameOverText.getGlobalBounds().width / 2, height / 3);

    returnToMenuText.setFont(font);
    returnToMenuText.setCharacterSize(24);
    returnToMenuText.setFillColor(sf::Color::White);
    returnToMenuText.setString("Press M to return to Main Menu");
    returnToMenuText.setPosition(width / 2 - returnToMenuText.getGlobalBounds().width / 2, height / 2);
}

void GameOver::draw(sf::RenderWindow &window) {
    window.draw(gameOverText);
    window.draw(returnToMenuText);
}

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