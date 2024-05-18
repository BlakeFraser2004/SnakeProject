#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>

class GameOver {
public:
    GameOver(float width, float height);
    void draw(sf::RenderWindow &window);
    bool handleInput(sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Text gameOverText;
    sf::Text returnToMenuText;
};

#endif // GAMEOVER_H