#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "Snake.h"
#include "Food.h" // Include the Food header
#include <iostream>

int main() {
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(500,500), "Snake Game");

    // Initialize the game board
    GameBoard gameBoard(50);

    // Initialize the snake
    Snake snake(10); // Assuming each grid cell is 20x20 pixels

    // Initialize the food
    Food food(10); // Pass the same grid size as the game board

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

        // Check for collision with food
        // Main function
// Check for collision with food
// Main function
// Check for collision between the snake's head and the food
sf::Vector2i snakeHeadPositionInt = snake.getHeadPosition();
sf::Vector2f snakeHeadPosition(static_cast<float>(snakeHeadPositionInt.x), static_cast<float>(snakeHeadPositionInt.y));
sf::Vector2f foodPosition = food.getPosition();
float distanceX = std::abs(snakeHeadPosition.x - foodPosition.x);
float distanceY = std::abs(snakeHeadPosition.y - foodPosition.y);

//std::cout << "Snake Head Position: " << snakeHeadPosition.x << ", " << snakeHeadPosition.y << std::endl;
//std::cout << "Food Position: " << foodPosition.x << ", " << foodPosition.y << std::endl;

// Determine the tolerance distance based on the size of the grid cell
int cellSize = 1;
float tolerance = cellSize;

if (distanceX <= tolerance && distanceY <= tolerance) {
    // Collision detected, snake eats the food
    snake.grow(); // Increase snake's length
    // Respawn a new food item
    food.respawn(window.getSize().x, window.getSize().y); // Respawn the food
 // Respawn the food
 
   // Check the position of the food


        

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
