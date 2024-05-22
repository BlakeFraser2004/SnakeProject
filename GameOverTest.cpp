#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include<iostream>

int main() {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Over Test");

    // Create an instance of the GameOver class
    GameOver gameOver(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the game over screen
        gameOver.draw(window);

        // Display the window
        window.display();

        // Handle input
        if (gameOver.handleInput(window)) {
            // If M is pressed, return to the main menu (not implemented in this test)
            // For testing purposes, you can add a message or action here
            std::cout << "Returning to main menu...\n";
        }
    }

    return 0;
}
