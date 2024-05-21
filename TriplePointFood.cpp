#include "TriplePointFood.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()

TriplePointFood::TriplePointFood(int gridSize) : GameObject(gridSize) {
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
    shape.setPosition(25, 25);

    shapeShadow.setFillColor(sf::Color::Cyan);
    shapeShadow.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
    shapeShadow.setPosition(250, 250);
    
    respawn(gridSize); // Initial spawn
}

void TriplePointFood::respawn(int gridSize) {
    // Generate random coordinates within the grid
    int x = rand() % gridSize;
    int y = rand() % gridSize;

    // Set the position of the shape
    shapeShadow.setPosition(sf::Vector2f(10 * x, 10 * y));
    shape.setPosition(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

void TriplePointFood::draw(sf::RenderWindow& window) const {
    window.draw(shapeShadow);
    window.draw(shape);
}
