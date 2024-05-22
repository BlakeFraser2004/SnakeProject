#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>

// GameOver class represents the game over screen.
class GameOver {
public:
    // Constructor to initialize the game over screen with the provided width and height.
    GameOver(float width, float height);

    // Draw the game over screen on the provided window.
    void draw(sf::RenderWindow &window);

    // Handle input events for the game over screen.
    // Returns true if 'M' key is pressed to return to the main menu, false otherwise.
    bool handleInput(sf::RenderWindow &window);

private:
    sf::Font font;              // Font for text rendering
    sf::Text gameOverText;      // Text displaying "GAME OVER!!!"
    sf::Text returnToMenuText;  // Text prompting to return to the main menu
};

#endif // GAMEOVER_H
