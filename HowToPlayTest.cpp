#include <SFML/Graphics.hpp>
#include "HowToPlay.h"
#include <iostream>

int main() {
    //constants for the test
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "How To Play Test");

    // Create an instance of the HowToPlay class
    HowToPlay howToPlay(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
                std::cout << "Returning to main menu...\n";
            }
        }

        // Clear the window
        window.clear();

        // Draw the "How to Play" screen
        howToPlay.draw(window);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
