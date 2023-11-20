#include "Beweging.h"

Beweging::Beweging(float xVel, float yVel) : xVelocity(xVel), yVelocity(yVel), originalYVelocity(yVel) {}

void Beweging::move(sf::Vector2f& position) {
    if (position.x < 170 && (position.y > 100 && position.y < 420))
    {
        position.x += xVelocity;
    }
    if ((position.x >= 170 && position.x < 200) && position.y > 172)
    {
        position.y -= yVelocity;
    }
    if (position.x < 412 && position.y < 172)
    {
        position.x += xVelocity;
    }
    if ((position.x >= 412 && position.x <= 700) && position.y < 172)
    {
        yVelocity *= -1;
    }
    if (position.y < 490 && position.x >= 412)
    {
        position.y -= yVelocity;
    }
    if (position.x < 734 && position.y >= 490)
    {
        position.x += xVelocity;
    }
    if (position.x >= 734 && position.y >= 340)
    {
        yVelocity = originalYVelocity;
        position.y -= yVelocity;
    }

    if (position.x >= 734 && position.y <= 340)
    {
        yVelocity = 0;

        if (position.x <= 1000)
        {
            position.x += xVelocity;
        }
    }
};
