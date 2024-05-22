#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include<iostream>

int main() {
    // Define the window dimensions
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Over Test");

    // Create an instance of the GameOver class
    GameOver gameOver(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Main game loop
    while (window.isOpen()) {
        // Event handling loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window for the next frame
        window.clear();

        // Draw the game over screen
        gameOver.draw(window);

        // Display the contents of the window
        window.display();

        // Handle input events
        if (gameOver.handleInput(window)) {
            std::cout << "Returning to main menu...\n";
        }
    }

    return 0;
}