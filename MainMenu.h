//The MainMenu class initialises the main menu items and draws the main menu interface.
#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

//Namespace declarations
using namespace std;
using namespace sf;
//Constant which deifnes the max number of main menu items.
#define Max_main_menu 2

//Class definition for the MainMenu.
class MainMenu {
public:
    //Constructor to initialise the MainMenu.
    MainMenu(float width, float height);
   //Destructor
    ~MainMenu();

    //Function the draw the MainMenu on the window.
    void draw(RenderWindow& window);
    
    //Function to get the index of the selected MainMenu item
    int MainMenuPressed() const {
        return MainMenuSelected;
    }

private:
    
    //Index of the selected MainMenu
    int MainMenuSelected;
    //Font for MainMenu text
    Font font;
    //Array to store MainMenu Text
    Text mainMenu[Max_main_menu];
    //Texture for MainMenu background.
    Texture backgroundTexture;
    //Sprite for MainMenu background.
    Sprite backgroundSprite;
};

#endif