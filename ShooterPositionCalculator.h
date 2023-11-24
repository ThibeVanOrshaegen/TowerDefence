#ifndef SHOOTER_POSITION_CALCULATOR_H
#define SHOOTER_POSITION_CALCULATOR_H

#include <SFML/Graphics.hpp>
#include "Weapon.h"
namespace Towerdefense
{
    class ShooterPositionCalculator : public Weapon {
    public:
        static sf::Vector2f calculateShooterPosition(const sf::Vector2f robotPosition, const sf::Vector2f shooterPosition);
        static float calculateDistance(const sf::Vector2f position1, const sf::Vector2f position2); //references for functions
    };
}
#endif

