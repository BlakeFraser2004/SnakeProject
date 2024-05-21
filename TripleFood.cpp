#include "TripleFood.h"
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()


TripleFood::TripleFood(int gridSize) : Food(gridSize) {
    shapeShadow.setFillColor(sf::Color::Yellow);
}

void TripleFood::draw(sf::RenderWindow& window) const {
    window.draw(shapeShadow);
}

void TripleFood::respawn(int gridSize) {
    // Generate random coordinates within the grid
    int x = rand() % gridSize;
    int y = rand() % gridSize;
    std::cout << "TripleFood Respawned at: " << x << "  " << y << std::endl;

    // Set the position of the shape
    shape.setPosition(sf::Vector2f(x * gridSize, y * gridSize));
    shapeShadow.setPosition(sf::Vector2f(10 * x, 10 * y));
}