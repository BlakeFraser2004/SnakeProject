#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
    // Default constructor
}

GameObject::GameObject(sf::Vector2f position) : positionOfObject(position) {
    // Constructor with position parameter
}

sf::Vector2f GameObject::getPosition() const {
    return positionOfObject;
}

void GameObject::setPosition(sf::Vector2f position) {
    positionOfObject = position;
}