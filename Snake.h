
#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameBoard.h"
#include "GameObject.h"

class Snake : public GameObject {
private:
    std::vector<sf::Vector2i> segments;
    sf::Vector2i direction;
    sf::Color color;
    int gridSize; // Move this before speed
    float speed;

public:
    Snake(int gridSize);
    void update() override;
    void draw(sf::RenderWindow& window) const override;
    void handleInput(sf::RenderWindow& window);
    void grow();
    sf::Vector2i getHeadPosition() const;
    bool checkCollisionWithBorder(const GameBoard& gameBoard) const;
    bool checkSelfCollision(const sf::Vector2i& headPosition) const;
    void reset();
    int getSize() const;
    sf::Vector2f getPosition() const override; // Added override for pure virtual method
};

#endif // SNAKE_H





