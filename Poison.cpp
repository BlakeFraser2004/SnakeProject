#include "Poison.h"

Poison::Poison(int gridSize) : Food(gridSize) {}

void Poison::respawn(int gridSize) {
    // Call the base class respawn method
    Food::respawn(gridSize);

    // Additional behavior for Poison, for example, changing color and setting poisonous flag
    shapeShadow.setFillColor(sf::Color::Green);
    isPoisonous = true;
}
