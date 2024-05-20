//Implementation of the GameBoard class methods
//This class manages the game baord, which includes initialising the grid and drawing the board.
#include "GameBoard.h"

//Initialises the gameboard with the given grid size
GameBoard::GameBoard(int gridSize) : boardSize(gridSize) {
    // Initialize the grid with zeros
    grid.resize(gridSize);
    for (int i = 0; i < gridSize; ++i) {
        grid[i].resize(gridSize, 0);
    }
}

void GameBoard::drawBoard(sf::RenderWindow& window) {
    // Calculate the size of each square based on the size of the window
    float squareSize = static_cast<float>(window.getSize().x) / boardSize;

    // Draw the game board using SFML graphics
    sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            // Calculates the position for each square.
            float posX = i * squareSize;
            float posY = j * squareSize;

            // Sets the position for the square shape on the gameboard.
            square.setPosition(posX, posY);

            // Sets the colour of the gameboard
            square.setFillColor(sf::Color::Black);

            // Draws the square (gameboard)
            window.draw(square);
        }
    }
}

int GameBoard::getBoardSize() const { // Added function definition
    return boardSize;
}