#include "Food.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()
#include <iostream>

Food::Food(int gridSize) : gridSize(gridSize) {
    shape.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
    shape.setPosition(25, 25);
    shapeShadow.setFillColor(sf::Color::Red);
    shapeShadow.setPosition(250, 250);
    shapeShadow.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
}

void Food::respawn(int gridSize) {
    // Generate random coordinates within the grid
    int x = rand() % gridSize;
    int y = rand() % gridSize;
    std::cout << x << "  " << y << std::endl;

    // Set the position of the shape
    shapeShadow.setPosition(sf::Vector2f(10 * x, 10 * y));
    shape.setPosition(sf::Vector2f(x, y));
}

void Food::draw(sf::RenderWindow& window) const {
    window.draw(shapeShadow);
}

sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}