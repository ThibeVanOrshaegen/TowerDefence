#include "HandleIntersectionAndDamage.h"

void HandleIntersectionAndDamage::handleIntersectionsAndDamage(sf::Sprite& weaponSprite, sf::Sprite& robotSprite, HealthBar& healthBar) {
    if (weaponSprite.getGlobalBounds().intersects(robotSprite.getGlobalBounds())) {
        healthBar.applyDamage();
    }
}
