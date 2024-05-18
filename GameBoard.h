#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>

class GameBoard {
private:
    int boardSize; //Size of the game board grid
    std::vector<std::vector<int> > grid; //2D vector representation of the game board grid

public:
    //Constructor to intialise the gameboard with a specified grid size.
    GameBoard(int gridSize);
    //Draw the gameboard on the provided window.
    void drawBoard(sf::RenderWindow& window);
    int getBoardSize() const;
};

#endif // GAMEBOARD_H 