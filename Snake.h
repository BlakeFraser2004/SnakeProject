#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameBoard.h"
#include "GameObject.h"

class Snake : public GameObject {
private:
    std::vector<sf::Vector2i> segments; // Stores the positions of each segment of the snake
    sf::Vector2i direction; // Direction in which the snake is moving
    sf::Color color; // Color of the snake
    int gridSize; // Size of each grid cell
    float speed; // Speed of the snake's movement

public:
    // Constructor to initialize the Snake
    Snake(int gridSize);

    // Update function to move the snake
    void update() override;

    // Draw function to render the snake on the window
    void draw(sf::RenderWindow& window) const override;

    // Function to handle user input for controlling the snake's movement
    void handleInput(sf::RenderWindow& window);

    // Function to make the snake grow longer
    void grow();

    // Function to get the position of the snake's head
    sf::Vector2i getHeadPosition() const;

    // Function to check collision of the snake with the game board border
    bool checkCollisionWithBorder(const GameBoard& gameBoard) const;

    // Function to check collision of the snake with itself
    bool checkSelfCollision(const sf::Vector2i& headPosition) const;

    // Function to reset the snake to its initial state
    void reset();

    // Function to get the size of the snake (number of segments)
    int getSize() const;

    // Function to get the position of the snake (used for collision detection)
    sf::Vector2f getPosition() const override;
};

#endif // SNAKE_H
