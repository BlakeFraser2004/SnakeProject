#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>

class GameBoard {
private:
    int boardSize;
    std::vector<std::vector<int> > grid;

public:
    GameBoard(int boardSize);
    void initializeBoard();
    void drawBoard(sf::RenderWindow &window);
    void updateBoard();
};

#endif // GAMEBOARD_H
