#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) const = 0; // Marked as const
    virtual sf::Vector2f getPosition() const = 0;          // Marked as const
};

#endif // GAMEOBJECT_H
