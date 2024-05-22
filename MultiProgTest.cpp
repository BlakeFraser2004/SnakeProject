#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Food.h"
#include "Snake.h"
#include "GameBoard.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const int GRID_SIZE = 50;

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake and Food Test");

    // Create instances of the GameBoard, Food, and Snake classes
    GameBoard gameBoard(50);
    Food food(10);
    Snake snake(10);

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

        // Output the positions
        std::cout << "Snake Head Position: (" << snake.getHeadPosition().x << ", " << snake.getHeadPosition().y << ")\n";
        std::cout << "Food Position: (" << food.getPosition().x << ", " << food.getPosition().y << ")\n";
        std::cout << "Snake Size: " << snake.getSize() << "\n";

        // Delay to control the speed of the game
        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
