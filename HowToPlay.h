#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <SFML/Graphics.hpp>

class HowToPlay {
public:
    HowToPlay(float width, float height);
    void draw(sf::RenderWindow& window);
    bool handleInput(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text howToPlayText;
    sf::Text closeText;
};

#endif // HOWTOPLAY_H
