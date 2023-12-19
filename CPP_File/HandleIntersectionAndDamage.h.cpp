#include "HandleIntersectionAndDamage.h"
#include <iostream>

namespace Towerdefense
{

    void HandleIntersectionAndDamage::handleIntersectionsAndDamage(sf::Sprite& weaponSprite, sf::Sprite& robotSprite, HealthBar& healthBar) {
        if (weaponSprite.getGlobalBounds().intersects(robotSprite.getGlobalBounds())) {
            healthBar.applyDamage();
            healthBar.subtractHealth(4);

            std::vector<std::string> linesToWrite = { "Enemy has been hit" };
        }
    }
}