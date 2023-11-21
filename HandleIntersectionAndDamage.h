#pragma once

#include <SFML/Graphics.hpp>
#include "HealthBar.h"  // Include the necessary header for HealthBar or replace it with the correct one

class HandleIntersectionAndDamage {
public:
    static void handleIntersectionsAndDamage(sf::Sprite& weaponSprite, sf::Sprite& robotSprite, HealthBar& healthBar);
};

