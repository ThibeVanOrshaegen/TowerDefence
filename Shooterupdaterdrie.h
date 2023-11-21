#pragma once

#include <SFML/Graphics.hpp>

class ShooterUpdaterdrie {
public:
    static void updateRotation(sf::Sprite& shooter, sf::Sprite& weapon, float distance, float dy, float dx);
};