#include "gameBoard.h"

GameBoard::GameBoard(int gridSize) : boardSize(gridSize) {
    // Initialize the grid with zeros
    grid.resize(gridSize);
    for (int i = 0; i < gridSize; ++i) {
        grid[i].resize(gridSize, 0);
    }

    // Initialize the snake and other necessary components here
}

void GameBoard::drawBoard(sf::RenderWindow& window) {
    // Calculate the size of each square based on the size of the window
    float squareSize = static_cast<float>(window.getSize().x) / boardSize;

    // Draw the game board using SFML graphics
    sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            // Calculate position for each square
            float posX = i * squareSize;
            float posY = j * squareSize;

            // Set position for the square
            square.setPosition(posX, posY);

            // Set fill color for the square
            square.setFillColor(sf::Color::Black); // Inside color

            // Draw the square
            window.draw(square);
        }
    }
}


int GameBoard::getBoardSize() const { // Added function definition
    return boardSize;
}