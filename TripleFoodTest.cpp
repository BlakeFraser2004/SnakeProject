#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()
#include "TripleFood.h"

// Constants for the test
const int window_width = 800;
const int window_height = 600;
const int grid_size = 20;

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "TripleFood Test");

    // Create an instance of the TripleFood class
    TripleFood tripleFood(grid_size);

    // Initial respawn
    tripleFood.respawn(grid_size);

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                // Respawn the TripleFood when space is pressed
                tripleFood.respawn(grid_size);
            }
        }

        // Clear the window
        window.clear();

        // Draw the TripleFood
        tripleFood.draw(window);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
