#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int main() {
    // Define window dimensions
    float screenWidth = 800.0f;
    float screenHeight = 600.0f;

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Main Menu Test");

    // Create MainMenu instance
    MainMenu mainMenu(screenWidth, screenHeight);

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window if the close button is clicked
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Handle key presses
            else if (event.type == sf::Event::KeyPressed) {
                // Check if the 'R' key is pressed
                if (event.key.code == sf::Keyboard::R) {
                    // Handle Play option selected
                    std::cout << "Play option selected!" << std::endl;
                }
                // Check if the 'E' key is pressed
                else if (event.key.code == sf::Keyboard::E) {
                    // Handle Exit option selected
                    std::cout << "Exit option selected!" << std::endl;
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the main menu
        mainMenu.draw(window);

        // Display the window contents
        window.display();
    }

    return 0;
}
