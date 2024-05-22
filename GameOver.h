// GameOver.h

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>

class GameOver {
public:
    // Constructor
    GameOver(float width, float height);
    
    // Draw the GameOver screen on the provided window
    void draw(sf::RenderWindow &window);
    
    // Handle input events for the GameOver screen
    bool handleInput(sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Text gameOverText;
    sf::Text returnToMenuText;
};

#endif // GAMEOVER_H

