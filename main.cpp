#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "Snake.h"
#include "Food.h"
#include "Score.h"
#include "MainMenu.h"
#include "HighScore.h"
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    GameBoard gameBoard(50);
    Snake snake(10);
    Food food(9);
    Score score;
    HighScore highscore;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    sf::Text highScoreText;
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(24);
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setPosition(10, 40);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

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
                    else if (event.key.code == sf::Keyboard::E) {
                        int selection = mainMenu.MainMenuPressed();
                        if (selection == 0) {
                            inMainMenu = false;
                            clock.restart();
                        }
                        else if (selection == 1) {
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
            sf::Time elapsedTime = clock.restart();
            timeSinceLastUpdate += elapsedTime;

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            snake.handleInput(window);
            snake.update();

            if (snake.checkCollisionWithBorder(gameBoard)) {
                std::cout << "Snake collided with the border. Game Over!" << std::endl;
                window.close();
                break;
            }

            sf::Vector2i snakeHeadPositionInt = snake.getHeadPosition();
            sf::Vector2f snakeHeadPosition(static_cast<float>(snakeHeadPositionInt.x), static_cast<float>(snakeHeadPositionInt.y));
            sf::Vector2f foodPosition = food.getPosition();
            float distanceX = std::abs(snakeHeadPosition.x - foodPosition.x);
            float distanceY = std::abs(snakeHeadPosition.y - foodPosition.y);

            int cellSize = 0;
            float tolerance = cellSize;

            if (distanceX <= tolerance && distanceY <= tolerance) {
                snake.grow();
                score.increaseFoodEaten();

                if (score.calculateScore() > highscore.getHighScore()) {
                    highscore.setHighScore(score.calculateScore());
                    highScoreText.setString("High Score: " + std::to_string(highscore.getHighScore()));
                    highScoreText.setFillColor(sf::Color::Yellow);
                }

                food.respawn(50);
            }

            // Update score based on time elapsed since last update
            while (timeSinceLastUpdate > sf::seconds(1.0f)) {
                score.updateTimePlayed(1.0f);
                timeSinceLastUpdate -= sf::seconds(1.0f);
            }

            scoreText.setString("Score: " + std::to_string(score.calculateScore()));

            window.clear(sf::Color::White);
            gameBoard.drawBoard(window);
            food.draw(window);
            snake.render(window);
            window.draw(scoreText);
            window.draw(highScoreText);
            window.display();
        }
    }

    return 0;
}
