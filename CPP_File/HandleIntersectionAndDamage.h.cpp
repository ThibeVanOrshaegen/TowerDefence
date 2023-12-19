#include "HandleIntersectionAndDamage.h"
#include <iostream>

namespace Towerdefense
{
    // Method definition to handle intersections between a weapon and an enemy and apply damage
    void HandleIntersectionAndDamage::handleIntersectionsAndDamage(sf::Sprite& weaponSprite, sf::Sprite& robotSprite, HealthBar& healthBar) {
        if (weaponSprite.getGlobalBounds().intersects(robotSprite.getGlobalBounds())) {
            healthBar.applyDamage();
            // Subtract a specific amount of health from the health bar
            healthBar.subtractHealth(4);

            std::vector<std::string> linesToWrite = { "Enemy has been hit" };
        }
    }
}
