#ifndef TRIPLEPOINTFOOD_H
#define TRIPLEPOINTFOOD_H

#include "GameObject.h"

class TriplePointFood : public GameObject {
private:
    sf::RectangleShape shapeShadow;

public:
    TriplePointFood(int gridSize);
    void respawn(int gridSize);
    void draw(sf::RenderWindow& window) const override;
};

#endif // TRIPLEPOINTFOOD_H
