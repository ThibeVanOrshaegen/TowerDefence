#pragma once

#include <SFML/Graphics.hpp>
#include "Weapon.h"

class ShooterUpdaterdrie : public Weapon{
public:
    static void updateRotation(sf::Sprite& shooter, sf::Sprite& weapon, float distance, float dy, float dx);
};