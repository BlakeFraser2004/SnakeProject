#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameBoard.h"

class Snake {
private:
    std::vector<sf::Vector2i> segments;
    sf:: Vector2i direction;
    sf:: Color color;
    float speed;
    int gridSize;
    
public:
    Snake(int gridSize);
    void update();
    void render(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window);
    void grow();
    sf::Vector2i getHeadPosition();
};

#endif
