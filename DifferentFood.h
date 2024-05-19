// DifferentFood.h
#ifndef DIFFERENTFOOD_H
#define DIFFERENTFOOD_H

#include "Food.h"

class DifferentFood : public Food {
public:
    enum class FoodType {
        Regular,
        Special,
        Poison
    };

    DifferentFood(int gridSize, FoodType type);

    // Override the base class methods
    void respawn(int gridSize) override;
    void draw(sf::RenderWindow& window) const override;
};

#endif // DIFFERENTFOOD_H
