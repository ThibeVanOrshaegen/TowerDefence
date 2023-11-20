#pragma once

#include <SFML/Graphics.hpp>

class Beweging {
private:
    float xVelocity;
    float yVelocity;
    float originalYVelocity;

public:
    Beweging(float xVel, float yVel);

    void move(sf::Vector2f& position);
};

