#include "gameObject.h"

GameObject::GameObject(int gridSize) {
    shape.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
}

void GameObject::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f GameObject::getPosition() const {
    return shape.getPosition();
}

void GameObject::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void GameObject::setPosition(const sf::Vector2f& position) {
    shape.setPosition(position);
}

sf::FloatRect GameObject::getBounds() const {
    return shape.getGlobalBounds();
}
