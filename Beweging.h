#ifndef BEWEGING_H
#define BEWEGING_H

#include <SFML/Graphics.hpp>
namespace Towerdefense
{
    class Beweging {
    private:
        float xVelocity;
        float yVelocity;
        float originalYVelocity;

    public:
        Beweging(float xVel, float yVel);

        void move(sf::Vector2f& position);
    };
}
#endif 
