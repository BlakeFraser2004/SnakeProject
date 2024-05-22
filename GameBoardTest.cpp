#include <iostream>
#include "GameBoard.h"

int main()
{
    // Create a test window for the game board.
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Board Test");

    // Create a GameBoard object for testing.
    // Set the grid size.
    int gridSize = 10;
    GameBoard gameBoard(gridSize);

    // Test if the game window is open.
    if (!window.isOpen())
    {
        //outputs an error message if the game window is not open.
        std::cerr << "Error: Game window is not open." << std::endl;
        return 1;
    }

    // Outputs the gridSize.
    std::cout << "Grid Size: " << gameBoard.getBoardSize() << std::endl;

    // The game board should be open, so clear and display it.
    window.clear();
    gameBoard.drawBoard(window);
    window.display();

    // Keep the window open until it's manually closed.
    while (window.isOpen())
    {
        // Check for window events.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    //outputs a message if the gameboard passed the test.
    std::cout << "Game Board Test Passed" << std::endl;
    return 0;
}
