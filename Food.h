#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

class Food {
private:
    sf::RectangleShape shape;

public:
    Food(int gridSize);
    void respawn(int gridSize);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;
};

#endif // FOOD_H
