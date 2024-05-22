#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject { // This class is used as an abstract class
public:
    virtual ~GameObject() = default;    // Virtual destructor
    virtual void update() = 0;  // The following are pure virtual function
    virtual void draw(sf::RenderWindow& window) const = 0; 
    virtual sf::Vector2f getPosition() const = 0;          
};

#endif 