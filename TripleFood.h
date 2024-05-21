#ifndef TRIPLEFOOD_H
#define TRIPLEFOOD_H

#include "Food.h"

class TripleFood : public Food {
public:
    TripleFood(int gridSize);
    void draw(sf::RenderWindow& window) const override;
    void respawn(int gridSize) override;
};

#endif // TRIPLEFOOD_H