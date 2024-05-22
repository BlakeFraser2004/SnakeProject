#include "MainMenu.h"

// Constructor to initialize the MainMenu
MainMenu::MainMenu(float width, float height) {
    // Load font
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Set up menu items.
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play (Press R to play)");
    mainMenu[0].setCharacterSize(30);
    mainMenu[0].setPosition(Vector2f(width / 4, height / (3.5)));

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("How to Play (Press H)");
    mainMenu[1].setCharacterSize(30);
    mainMenu[1].setPosition(Vector2f(width / 4, height / (2.5)));

    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("Reset HighScore (Press W)");
    mainMenu[2].setCharacterSize(30);
    mainMenu[2].setPosition(Vector2f(width / 4, height / (2.0)));

    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Exit (Press E to Exit)");
    mainMenu[3].setCharacterSize(30);
    mainMenu[3].setPosition(Vector2f(width / 4, height / (1.5)));

    // Initialize selected menu item
    MainMenuSelected = 0;
}

// Draw the main menu on the provided window
void MainMenu::draw(RenderWindow& window) {
    // Set a black background
    window.clear(sf::Color::Black);
    
    // Draw "Snake" at the top of the screen
    sf::Text title;
    title.setFont(font);
    title.setString("Snake");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Red);
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 30);
    window.draw(title);

    // Draw main menu items
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(mainMenu[i]);
    }
}
