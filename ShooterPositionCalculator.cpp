#include "ShooterPositionCalculator.h"
#include <cmath>

sf::Vector2f ShooterPositionCalculator::calculateShooterPosition(sf::Vector2f robotPosition, sf::Vector2f shooterPosition) {
    return sf::Vector2f(robotPosition.x - shooterPosition.x, robotPosition.y - shooterPosition.y);
}

float ShooterPositionCalculator::calculateDistance(sf::Vector2f position1, sf::Vector2f position2) {
    float dx = position1.x - position2.x;
    float dy = position1.y - position2.y;
    return std::sqrt(dx * dx + dy * dy);
}
