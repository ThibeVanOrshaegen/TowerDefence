#ifndef WEAPONS_H
#define WEAPONS_H

#include <SFML/Graphics.hpp>
namespace Towerdefense
{
    class Weapon {
    public:
        virtual ~Weapon() = default;
        virtual void fire(sf::Vector2f& shooterPosition,float limit_one, float limit_two, float limit_three, float limit_four) = 0; //polymorfisme
        virtual void update(float directionX, float directionY) = 0;
    };
}
#endif