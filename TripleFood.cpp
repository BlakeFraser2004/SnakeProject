#include "TripleFood.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor for TripleFood, initializes the shadow shape with a yellow color.
TripleFood::TripleFood(int gridSize) : Food(gridSize) {
    shapeShadow.setFillColor(sf::Color::Yellow);
}

// Draws the shadow shape on the window.
void TripleFood::draw(sf::RenderWindow& window) const {
    window.draw(shapeShadow);
}

// Respawn the TripleFood at a random position within the grid.
void TripleFood::respawn(int gridSize) {
    // Generate random coordinates within the grid
    int x = rand() % gridSize;
    int y = rand() % gridSize;

    // Set the position of the shape and shadow shape
    shape.setPosition(sf::Vector2f(x, y));
    shapeShadow.setPosition(sf::Vector2f(10 * x, 10 * y));
}
