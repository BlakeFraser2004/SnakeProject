#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "Snake.h"
#include "Food.h"
#include "Score.h"
#include "MainMenu.h" // Include the MainMenu header file
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");

    // Initialize the main menu
    MainMenu mainMenu(window.getSize().x, window.getSize().y);

    // Initialize the game board
    GameBoard gameBoard(50);

    // Initialize the snake
    Snake snake(10); // Assuming each grid cell is 10x10 pixels

    // Initialize the food
    Food food(9); // Pass the same grid size as the game board

    // Initialize the score
    Score score;

    // Font for displaying the score
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);

    sf::Clock clock; // Clock to measure the elapsed time

    // Game loop
    bool inMainMenu = true;
    while (window.isOpen()) {
        if (inMainMenu) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        mainMenu.MoveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        mainMenu.MoveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Enter) {
                        int selection = mainMenu.MainMenuPressed();
                        if (selection == 0) { // Play
                            inMainMenu = false;
                        }
                        else if (selection == 1) { // Exit
                            window.close();
                            return 0;
                        }
                    }
                }
            }
            window.clear(sf::Color::Black);
            mainMenu.draw(window);
            window.display();
        }
        else {
            float deltaTime = clock.restart().asSeconds();
            score.updateTimePlayed(deltaTime); // Update the playtime

            // Handle events
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // Handle input
            snake.handleInput(window);

            // Update
            snake.update();

            // Check for collisions
            if (snake.checkCollisionWithBorder(gameBoard)) {
                std::cout << "Snake collided with the border. Game Over!" << std::endl;
                window.close(); // Close the window
                break; // Exit the game loop
            }

            // Check for collision with food
            sf::Vector2i snakeHeadPositionInt = snake.getHeadPosition();
            sf::Vector2f snakeHeadPosition(static_cast<float>(snakeHeadPositionInt.x), static_cast<float>(snakeHeadPositionInt.y));
            sf::Vector2f foodPosition = food.getPosition();
            float distanceX = std::abs(snakeHeadPosition.x - foodPosition.x);
            float distanceY = std::abs(snakeHeadPosition.y - foodPosition.y);

            // Determine the tolerance distance based on the size of the grid cell
            int cellSize = 10; // Assuming each grid cell is 10x10 pixels
            float tolerance = cellSize;

            if (distanceX <= tolerance && distanceY <= tolerance) {
                // Collision detected, snake eats the food
                snake.grow(); // Increase snake's length
                score.increaseFoodEaten(); // Update the score

                std::cout << "Snake grew!" << std::endl;
                // If the snake grew, update the food position
                food.respawn(50); // Pass the grid size
            }

            std::cout << "Snake's Head Position: (" << snakeHeadPosition.x << ", " << snakeHeadPosition.y << ")" << std::endl;
            std::cout << "Food's Position: (" << foodPosition.x << ", " << foodPosition.y << ")" << std::endl;

            // Update the score text
            scoreText.setString("Score: " + std::to_string(score.calculateScore()));

            // Clear the window
            window.clear(sf::Color::White);

            // Draw the game board
            gameBoard.drawBoard(window);

            // Draw the food
            food.draw(window);

            // Draw the snake
            snake.render(window);

            // Draw the score
            window.draw(scoreText);

            // Display the window
            window.display();
        }
    }

    return 0;
}
