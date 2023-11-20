#pragma once

#include "HealthBar.h"
#include "TextureManager.h"
#include "Beweging.h"

class Enemy : public HealthBar {
private:
    TextureManager textureManager;
    Beweging beweging;

public:
    sf::Sprite spriterobottwee;

    Enemy(sf::Vector2f initialPosition, sf::Vector2f size, int RandommaxHealth, float xVelocity, float yVelocity);

    void update();

    void updateHealthBar();
};

