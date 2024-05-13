// Food.cpp
#include "Food.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()
#include <iostream>

Food::Food(int gridSize) {
    shape.setSize(sf::Vector2f(static_cast<float>(gridSize), static_cast<float>(gridSize)));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(0,0);
}

void Food::respawn(int maxWidth, int maxHeight) {
    int gridSizeX = static_cast<int>(((shape.getSize().x)*5)-1);
    int gridSizeY = static_cast<int>(((shape.getSize().y)*5)-1);
    
    int x = rand() % (gridSizeX);
    int y = rand() % (gridSizeY);
    


     std::cout<<"position of gridSizeX is: " <<x<<std::endl;
      std::cout<<"position of gridSizeX is: " <<y<<std::endl;
    
    shape.setPosition(sf::Vector2f(x, y));
}


void Food::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}
