#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

// Namespace declarations
using namespace std;
using namespace sf;

// Constant which defines the max number of main menu items.
constexpr int Max_main_menu = 4;

// Class definition for the MainMenu.
class MainMenu {
public:
    // Constructor to initialize the MainMenu.
    MainMenu(float width, float height);
    // Destructor
    ~MainMenu() = default;

    // Function to draw the MainMenu on the window.
    void draw(RenderWindow& window);
    
    // Function to get the index of the selected MainMenu item
    int MainMenuPressed() const {
        return MainMenuSelected;
    }

private:
    // Index of the selected MainMenu
    int MainMenuSelected;
    // Font for MainMenu text
    Font font;
    // Array to store MainMenu Text
    Text mainMenu[Max_main_menu];
    // Texture for MainMenu background.
    Texture backgroundTexture;
    // Sprite for MainMenu background.
    Sprite backgroundSprite;
};

#endif // MAINMENU_H
