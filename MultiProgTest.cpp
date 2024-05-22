#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Food.h"
#include "Snake.h"
#include "GameBoard.h"

// Define the dimensions of the main window
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
// Define the size of each grid cell on the game board
const int GRID_SIZE = 50;

int main() {
    // Seed the random number generator for food spawning
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake and Food Test");

    // Create instances of the GameBoard, Food, and Snake classes
    GameBoard gameBoard(GRID_SIZE);
    Food food(GRID_SIZE / 5); // The size of the food is set to one-fifth of the grid size
    Snake snake(GRID_SIZE / 5); // The size of the snake is set to one-fifth of the grid size

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Handle snake input
        snake.handleInput(window);

        // Update the snake's position
        snake.update();

        // Check if the snake's head position matches the food position
        if (snake.getHeadPosition() == sf::Vector2i(food.getPosition().x, food.getPosition().y)) {
            // If the snake eats the food, it grows and the food respawns
            snake.grow();
            food.respawn(GRID_SIZE);
        }

        // Clear the window
        window.clear();

        // Draw the game board, food, and snake
        gameBoard.drawBoard(window);
        food.draw(window);
        snake.draw(window);

        // Display the contents of the window
        window.display();

        // Output the positions of the snake's head, food, and the size of the snake
        std::cout << "Snake Head Position: (" << snake.getHeadPosition().x << ", " << snake.getHeadPosition().y << ")\n";
        std::cout << "Food Position: (" << food.getPosition().x << ", " << food.getPosition().y << ")\n";
        std::cout << "Snake Size: " << snake.getSize() << "\n";

        // Delay to control the speed of the game
        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
