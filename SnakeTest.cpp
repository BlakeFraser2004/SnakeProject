#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constants for the test
const int window_width= 800;
const int window_height = 600;
const int grid_size = 20;

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Snake Test");

    // Create an instance of the Snake class
    Snake snake(grid_size);

    // Print initial position
    sf::Vector2i initialPosition = snake.getHeadPosition();
    std::cout << "Initial Position: (" << initialPosition.x << ", " << initialPosition.y << ")\n";

    // Main loop to move the snake a small distance
    int moves = 5; // Number of moves to make
    for (int i = 0; i < moves; ++i) {
        // Update the snake's position
        snake.update();

        // Handle window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the snake
        snake.draw(window);

        // Display the contents of the window
        window.display();

        // Pause to see the movement
        sf::sleep(sf::seconds(0.2f)); // Adjust the pause duration as needed
    }

    // Print updated position
    sf::Vector2i updatedPosition = snake.getHeadPosition();
    std::cout << "Updated Position: (" << updatedPosition.x << ", " << updatedPosition.y << ")\n";
    std::cout << "Amount Moved: (" << updatedPosition.x - initialPosition.x << ", " << updatedPosition.y - initialPosition.y << ")\n";

    return 0;
}
