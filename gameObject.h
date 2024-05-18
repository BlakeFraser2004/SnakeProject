#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::RectangleShape shape;

public:
    GameObject(int gridSize);
    virtual ~GameObject() = default;

    virtual void draw(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
    sf::FloatRect getBounds() const;
};

#endif // GAMEOBJECT_H
