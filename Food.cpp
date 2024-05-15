#include "Food.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()
#include<iostream>

Food::Food(int gridSize) {
    shape.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(15, 15);
}

void Food::respawn(int gridSize) {
    
    int x = rand() % gridSize;
    int y = rand() % gridSize;

    // Ensure x and y are within the range (0, gridSize - 1)
    x = std::min(std::max(x, 0), gridSize - 1);
    y = std::min(std::max(y, 0), gridSize - 1);

    shape.setPosition(sf::Vector2f(x,y));
}
void Food::draw(sf::RenderWindow& window) const {
    //std::cout << "Drawing food at position: (" << shape.getPosition().x << ", " << shape.getPosition().y << ")" << std::endl;
    window.draw(shape);
}


sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}
