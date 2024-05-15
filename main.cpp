#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "Snake.h"
#include "Food.h"
#include <iostream>

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");

    // Initialize the game board
    GameBoard gameBoard(50);

    // Initialize the snake
    Snake snake(10); // Assuming each grid cell is 10x10 pixels

    // Initialize the food
    Food food(9); // Pass the same grid size as the game board

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Handle input
        snake.handleInput(window);

        // Update
        snake.update();

        // Check for collisions
        // Check for collisions
       // Check for collisions
if (snake.checkCollisionWithBorder(gameBoard)) {
        std::cout << "Snake collided with the border. Game Over!" << std::endl;
        window.close(); // Close the window
        break; // Exit the game loop
    }



        // Check for collision with food
        sf::Vector2i snakeHeadPositionInt = snake.getHeadPosition();
        sf::Vector2f snakeHeadPosition(static_cast<float>(snakeHeadPositionInt.x), static_cast<float>(snakeHeadPositionInt.y));
        sf::Vector2f foodPosition = food.getPosition();
        float distanceX = std::abs(snakeHeadPosition.x - foodPosition.x);
        float distanceY = std::abs(snakeHeadPosition.y - foodPosition.y);

        // Determine the tolerance distance based on the size of the grid cell
        int cellSize = 0; // Assuming each grid cell is 10x10 pixels
        float tolerance = cellSize;

        if (distanceX <= tolerance && distanceY <= tolerance) {
    // Get the current size of the snake
    int prevSize = snake.getSize();
    
    // Collision detected, snake eats the food
    snake.grow(); // Increase snake's length
    
    // Get the new size of the snake after growing
    int newSize = snake.getSize();
    
    std::cout << "Previous size: " << prevSize << ", New size: " << newSize << std::endl;
    
    // Check if the snake grew
    if (newSize > prevSize) {
        std::cout << "Snake grew!" << std::endl;
        // If the snake grew, update the food position
        food.respawn(50); // Pass the grid size
    }
}





        std::cout << "Snake's Head Position: (" << snakeHeadPosition.x << ", " << snakeHeadPosition.y << ")" << std::endl;
        std::cout << "Food's Position: (" << foodPosition.x << ", " << foodPosition.y << ")" << std::endl;


        // Clear the window
        window.clear(sf::Color::White);

        // Draw the game board
        gameBoard.drawBoard(window);

        // Draw the food
        food.draw(window);

        // Draw the snake
        snake.render(window);

        // Display the window
        window.display();
    }

    return 0;
}
