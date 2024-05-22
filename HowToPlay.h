#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <SFML/Graphics.hpp>

// Class definition for the HowToPlay window.
class HowToPlay {
public:
    // Constructor to initialize the HowToPlay window.
    HowToPlay(float width, float height);

    // Function to draw the HowToPlay window on the provided window.
    void draw(sf::RenderWindow& window);

private:
    // Font for the HowToPlay text.
    sf::Font font;
    // Text displaying the instructions on how to play.
    sf::Text howToPlayText;
    // Text indicating how to return to the main menu.
    sf::Text closeText;
};

#endif // HOWTOPLAY_H