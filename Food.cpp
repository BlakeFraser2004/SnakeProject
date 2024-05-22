#include "Food.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Implementation of the Food class methods
// This class manages the food object in the game, including its position, appearance, and behavior.

// Constructor to initialize the Food object with a specified grid size
Food::Food(int gridSize) : gridSize(gridSize) {
    // Set the size and initial position of the food
    shape.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
    shape.setPosition(25, 25);

    // Set up the shadow of the food with a red color
    shapeShadow.setFillColor(sf::Color::Red);
    shapeShadow.setPosition(250, 250);
    shapeShadow.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
}

// Respawn the food at a random position within the grid
void Food::respawn(int gridSize) {
    // Generate random coordinates within the grid
    int x = rand() % gridSize;
    int y = rand() % gridSize;

    // Set the position of the food and its shadow
    shapeShadow.setPosition(sf::Vector2f(10 * x, 10 * y)); // Multiply by 10 for visual offset
    shape.setPosition(sf::Vector2f(x, y));
}

// Draw the shadow of the food on the window
void Food::draw(sf::RenderWindow& window) const {
    window.draw(shapeShadow);
}

// Get the current position of the food
sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}
