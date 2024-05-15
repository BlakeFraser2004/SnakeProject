#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>

class GameBoard {
private:
    int boardSize;
    std::vector<std::vector<int> > grid;

public:
    GameBoard(int gridSize);
    void initializeBoard();
    void drawBoard(sf::RenderWindow& window);
    void updateBoard();
    int getBoardSize() const;
};

#endif // GAMEBOARD_H
