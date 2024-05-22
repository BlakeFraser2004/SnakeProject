#ifndef TRIPLEFOOD_H
#define TRIPLEFOOD_H

#include "Food.h"

// Class declaration for TripleFood, a subclass of Food.
class TripleFood : public Food {
public:
    // Constructor for TripleFood, taking the grid size as a parameter.
    TripleFood(int gridSize);
    
    // Override the draw function to draw the shadow shape.
    void draw(sf::RenderWindow& window) const override;
    
    // Override the respawn function to respawn the TripleFood at a random position.
    void respawn(int gridSize) override;
};

#endif // TRIPLEFOOD_H 
