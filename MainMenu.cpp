#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
        std::cerr << "Error loading font" << std::endl;
    }

    // Load the background texture
    if (!backgroundTexture.loadFromFile("grass.png")) {
        // Handle error
        std::cerr << "Error loading background image" << std::endl;
    }

    // Set the background sprite
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        width / backgroundSprite.getLocalBounds().width,
        height / backgroundSprite.getLocalBounds().height
    );

    // Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play (Press R to play)");
    mainMenu[0].setCharacterSize(30);
    mainMenu[0].setPosition(Vector2f(width / 4, height / (Max_main_menu + 2)));

    // Exit
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Exit (Press E to Exit)");
    mainMenu[1].setCharacterSize(30);
    mainMenu[1].setPosition(Vector2f(width / 4, height / (Max_main_menu + 1) * 2));

    MainMenuSelected = 0;
}

MainMenu::~MainMenu() {
}

void MainMenu::draw(RenderWindow& window) {
    window.draw(backgroundSprite); // Draw the background first
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(mainMenu[i]);
    }
}
