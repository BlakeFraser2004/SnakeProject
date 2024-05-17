#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>

class GameObject {
    private:
    sf::Vector2f positionOfObject;

    public:
    GameObject();
    GameObject(sf::Vector2f position);
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f position);
};


#endif