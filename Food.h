#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

// The Food class manages the food object in the game, including its position, appearance, and behavior.
class Food : public GameObject {
protected:
    sf::RectangleShape shape;
    sf::RectangleShape shapeShadow;
    sf::Vector2i gridPosition; // Grid position of the food
    int gridSize; // Size of each grid cell in pixels

public:
    // Constructor to initialize the Food object with a specified grid size
    Food(int gridSize);

    // Respawn the food at a random position within the grid
    virtual void respawn(int gridSize);

    // Override the update function (no implementation required for Food)
    void update() override {}

    // Draw the food on the window
    void draw(sf::RenderWindow& window) const override;

    // Get the current position of the food
    sf::Vector2f getPosition() const override;
};

#endif // FOOD_H
