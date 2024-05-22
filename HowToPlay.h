// HowToPlay.h

#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <SFML/Graphics.hpp>

class HowToPlay {
public:
    // Constructor
    HowToPlay(float width, float height);
    
    // Draw the HowToPlay screen on the provided window
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text howToPlayText;
    sf::Text closeText;
};

#endif // HOWTOPLAY_H

