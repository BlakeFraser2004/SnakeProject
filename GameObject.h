#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

// GameObject class represents a generic object in the game world.
class GameObject {
public:
    // Virtual destructor to allow polymorphic destruction.
    virtual ~GameObject() = default;

    // Update function to be called each game loop iteration.
    virtual void update() = 0;

    // Draw function to render the object on the window.
    virtual void draw(sf::RenderWindow& window) const = 0;

    // Get the position of the object.
    virtual sf::Vector2f getPosition() const = 0;
};

#endif // GAMEOBJECT_H
