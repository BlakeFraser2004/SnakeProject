#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
//The GameBoard class initialises the grid and draws the game board.
class GameBoard {
private:
    //Size of the game board grid.
    int boardSize; 
    //2D vector representation of the game board grid
    std::vector<std::vector<int> > grid;

public:
    //Constructor to intialise the gameboard with a specified grid size.
    GameBoard(int gridSize);
    //Draw the gameboard on the provided window.
    void drawBoard(sf::RenderWindow& window);
    int getBoardSize() const;
};

#endif // GAMEBOARD_H 