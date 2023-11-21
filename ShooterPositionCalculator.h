#ifndef SHOOTER_POSITION_CALCULATOR_H
#define SHOOTER_POSITION_CALCULATOR_H

#include <SFML/Graphics.hpp>
#include "Weapon.h"

class ShooterPositionCalculator : public Weapon{
public:
    static sf::Vector2f calculateShooterPosition(sf::Vector2f robotPosition, sf::Vector2f shooterPosition);
    static float calculateDistance(sf::Vector2f position1, sf::Vector2f position2);
};

#endif

