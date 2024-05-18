#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "gameObject.h"
#include "GameBoard.h"

class Snake {
private:
    std::vector<sf::Vector2i> segments;
    sf::Vector2i direction;
    sf::Color color;
    float speed;
    int gridSize;

public:
    Snake(int gridSize);
    void update();
    void render(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window);
    void grow();
    sf::Vector2i getHeadPosition();
    bool checkCollisionWithBorder(const GameBoard& gameBoard);
    bool checkSelfCollision(const sf::Vector2i& headPosition, const sf::Vector2i& foodPosition);
    void reset();   
    int getSize() const;
};


class Snake : public GameObject {
private:
    std::vector<sf::RectangleShape> body;
    sf::Vector2f direction;
    int gridSize;

public:
    Snake(int gridSize);
    void move();
    void grow();
    bool checkCollision() const;
    void draw(sf::RenderWindow& window) const override;
};

#endif // SNAKE_H