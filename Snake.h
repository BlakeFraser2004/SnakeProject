#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameBoard.h"

class Snake {
private:
    std::vector<sf::Vector2i> segments;
    sf::Vector2i direction;
    sf::Color color;
    int gridSize; // Move this before speed
    float speed;

public:
    Snake(int gridSize);
    void update();
    void draw(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window);
    void grow();
    sf::Vector2i getHeadPosition();
    bool checkCollisionWithBorder(const GameBoard& gameBoard);
    bool checkSelfCollision(const sf::Vector2i& headPosition);
    void reset();
    int getSize() const;
};

#endif // SNAKE_H
