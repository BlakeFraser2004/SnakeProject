#ifndef POISON_H
#define POISON_H

#include "Food.h"

class Poison : public Food {
public:
    Poison(int gridSize);
    void respawn(int gridSize) override; // Override the respawn method
private:
    void setShapeShadowColor(const sf::Color& color); // Helper method to set shapeShadow color
    void setPoisonous(bool value); // Set isPoisonous flag
    bool isPoisonous; // Flag to indicate if the food is poisonous
};

#endif // POISON_H
