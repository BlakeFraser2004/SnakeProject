#include "GameObject.h"
#include <cstdlib> // For rand()

GameObject::GameObject(int gridSize) : gridSize(gridSize) {}

void GameObject::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f GameObject::getPosition() const {
    return position;
}
