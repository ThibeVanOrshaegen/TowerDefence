#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

class ShooterUpdaterdrie : public Game{
public:
    static void updateRotation(sf::Sprite& shooter, sf::Sprite& weapon, float distance, float dy, float dx);
};