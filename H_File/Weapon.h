#ifndef WEAPONS_H
#define WEAPONS_H

#include <SFML/Graphics.hpp>
namespace Towerdefense
{
    class Weapon {
    public:

        // Virtual destructor to enable proper polymorphism
        virtual ~Weapon() = default;

        // Pure virtual function for firing the weapon, promoting polymorphism
        virtual void fire(sf::Vector2f& shooterPosition,float limit_one, float limit_two, float limit_three, float limit_four) = 0; //polymorfisme
        
        // Pure virtual function for updating the weapon, promoting polymorphism
        virtual void update(float directionX, float directionY) = 0;
    };
}
#endif
