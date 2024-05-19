#include "DifferentFood.h"

DifferentFood::DifferentFood(int gridSize, FoodType type) : Food(gridSize) {
    // Initialize food based on the type
    switch (type) {
        case FoodType::Regular:
            shape.setFillColor(sf::Color::Green); // Regular food color
            break;
        case FoodType::Special:
            shape.setFillColor(sf::Color::Blue); // Special food color
            break;
        case FoodType::Poison:
            shape.setFillColor(sf::Color::Red); // Poison food color
            break;
    }
}

void DifferentFood::respawn(int /*gridSize*/) {
    // Implement respawn functionality specific to DifferentFood if needed
}

void DifferentFood::draw(sf::RenderWindow& window) const {
    window.draw(shape); // Draw the food shape
}