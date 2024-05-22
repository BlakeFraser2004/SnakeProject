#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Food : public GameObject {
protected:
    sf::RectangleShape shape;
    sf::RectangleShape shapeShadow;
    sf::Vector2i gridPosition; // Grid position of the food
    int gridSize; // Size of each grid cell in pixels

public:
    Food(int gridSize); // Constructor
    void respawn(int gridSize); // Respawn the food at a new position within the grid
    void update() override {} // Food doesn't need to update, but must override
    void draw(sf::RenderWindow& window) const override; // Draw the food on the provided window
    sf::Vector2f getPosition() const override; // Get the position of the food
};

#endif // FOOD_H