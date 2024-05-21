#include "HowToPlay.h"
#include <iostream>

HowToPlay::HowToPlay(float width, float height) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

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
        "Press H to close this window."
    );
    howToPlayText.setPosition(45, 50);

    closeText.setFont(font);
    closeText.setCharacterSize(30);
    closeText.setFillColor(sf::Color::Red);
    closeText.setString("Press M to return to main menu");
    closeText.setPosition(width / 2 - closeText.getGlobalBounds().width / 2, height - 50);
}

void HowToPlay::draw(sf::RenderWindow& window) {
    window.draw(howToPlayText);
    window.draw(closeText);
}

bool HowToPlay::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
            return true;
        }
    }
    return false;
}
