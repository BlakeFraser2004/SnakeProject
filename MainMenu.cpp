#include "MainMenu.h"

// Constructor to initialize the MainMenu
MainMenu::MainMenu(float width, float height) {
    // Load font
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Load background texture
    if (!backgroundTexture.loadFromFile("grass.png")) {
        std::cerr << "Error loading background image" << std::endl;
    }

    // Set background sprite
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        width / backgroundSprite.getLocalBounds().width,
        height / backgroundSprite.getLocalBounds().height
    );

    // Set up menu items.
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play (Press R to play)");
    mainMenu[0].setCharacterSize(30);
    mainMenu[0].setPosition(Vector2f(width / 4, height / (Max_main_menu + 2)));

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Exit (Press E to Exit)");
    mainMenu[1].setCharacterSize(30);
    mainMenu[1].setPosition(Vector2f(width / 4, height / (Max_main_menu + 1) * 2));

    // Initialize selected menu item
    MainMenuSelected = 0;
}
// Destructor
MainMenu::~MainMenu() {
}

// Draw the main menu on the provided window
void MainMenu::draw(RenderWindow& window) {
   // Draw the background first
   window.draw(backgroundSprite);
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(mainMenu[i]);
    }
}