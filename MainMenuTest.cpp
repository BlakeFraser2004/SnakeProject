#include <SFML/Graphics.hpp>
#include "MainMenu.h" // Include your MainMenu class header

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
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) {
                    // Handle Play option selected
                    std::cout << "Play option selected!" << std::endl;
                }
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
