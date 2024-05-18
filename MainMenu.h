#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define Max_main_menu 3 // Updated for 3 menu items

class MainMenu {
public:
    MainMenu(float width, float height);
    ~MainMenu();

    void draw(RenderWindow& window);
    int MainMenuPressed() const;

private:
    int MainMenuSelected;
    Font font;
    Text mainMenu[Max_main_menu];
    Texture backgroundTexture;
    Sprite backgroundSprite;
};