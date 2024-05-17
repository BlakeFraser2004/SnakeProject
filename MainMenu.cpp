#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
        std::cerr << "Error loading font" << std::endl;
    }

    // Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play (press)");
    mainMenu[0].setCharacterSize(30);
    mainMenu[0].setPosition(Vector2f(width / 2.5, height / (Max_main_menu + 2)));

    // Exit
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Exit");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(Vector2f(width / 2.5, height / (Max_main_menu + 1) * 2));

    MainMenuSelected = 0;
}

MainMenu::~MainMenu() {
}

void MainMenu::draw(RenderWindow& window) {
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(mainMenu[i]);
    }
}

void MainMenu::MoveUp() {
    if (MainMenuSelected - 1 >= 0) {
        MainMenuSelected--;
    }
}

void MainMenu::MoveDown() {
    if (MainMenuSelected + 1 < Max_main_menu) {
        MainMenuSelected++;
    }
}
