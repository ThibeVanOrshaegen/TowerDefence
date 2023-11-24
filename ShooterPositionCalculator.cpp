#include "ShooterPositionCalculator.h"
#include <cmath>
namespace Towerdefense
{
    sf::Vector2f ShooterPositionCalculator::calculateShooterPosition(const sf::Vector2f robotPosition, const sf::Vector2f shooterPosition) {
        return sf::Vector2f(robotPosition.x - shooterPosition.x, robotPosition.y - shooterPosition.y);
    }

    float ShooterPositionCalculator::calculateDistance(const sf::Vector2f position1, const sf::Vector2f position2) {
        float dx = position1.x - position2.x;
        float dy = position1.y - position2.y;
        return std::sqrt(dx * dx + dy * dy);
    }
}