#pragma once

#include "Weapon.h"

class Canon : public Weapon {
private:
    sf::Vector2f initialPosition;
    sf::Vector2f arrowPosition;

public:
    sf::CircleShape arrow;

    Canon(sf::Vector2f initialPosition);

    void fire(sf::Vector2f shooterPosition) override;
    void update() override;
};

