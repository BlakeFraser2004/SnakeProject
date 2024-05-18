#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "Snake.h"
#include "Food.h"
#include "Score.h"
#include "MainMenu.h"
#include "HighScore.h"
#include "GameOver.h"
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    GameBoard gameBoard(50);
    Snake snake(10);
    Food food(9);
    Score score;
    HighScore highscore("highscores.txt");
    GameOver gameOver(window.getSize().x, window.getSize().y);

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
    bool isGameOver = false;

    while (window.isOpen()) {
        if (inMainMenu) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::R) {
                        inMainMenu = false;
                        clock.restart();
                        isGameOver = false;
                        snake = Snake(10);
                        food = Food(9);
                        score.reset();
                    } else if (event.key.code == sf::Keyboard::W) {
                        highscore.wipeHighScore();
                        highScoreText.setString("High Score: " + std::to_string(highscore.getHighScore()));
                    } else if (event.key.code == sf::Keyboard::E) {
                        window.close();
                        return 0;
                    }
                }
            }
            window.clear(sf::Color::Black);
            mainMenu.draw(window);
            window.display();
        } else if (isGameOver) {
            if (gameOver.handleInput(window)) {
                inMainMenu = true;
            }
            window.clear(sf::Color::Black);
            gameOver.draw(window);
            window.display();
        } else {
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
                std::cout << "Snake collided with the border or itself. Game Over!" << std::endl;
                isGameOver = true;
                continue;
            }

            sf::Vector2i snakeHeadPositionInt = snake.getHeadPosition();
            sf::Vector2f snakeHeadPosition(static_cast<float>(snakeHeadPositionInt.x), static_cast<float>(snakeHeadPositionInt.y));
            sf::Vector2f foodPosition = food.getPosition();
            float distanceX = std::abs(snakeHeadPosition.x - foodPosition.x);
            float distanceY = std::abs(snakeHeadPosition.y - foodPosition.y);

            int cellSize = 0;  // Assuming cell size is 10, adjust accordingly
            float tolerance = static_cast<float>(cellSize);

            if (distanceX <= tolerance && distanceY <= tolerance) {
                snake.grow();
                score.increaseFoodEaten();
                highScoreText.setString("High Score: " + std::to_string(highscore.getHighScore()));
                highScoreText.setFillColor(sf::Color::Yellow);

                if (score.calculateScore() > highscore.getHighScore()) {
                    highscore.setHighScore(score.calculateScore());
                }

                food.respawn(50);
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