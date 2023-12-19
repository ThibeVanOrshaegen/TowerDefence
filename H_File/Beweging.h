#ifndef BEWEGING_H
#define BEWEGING_H

#include <SFML/Graphics.hpp>
namespace Towerdefense
{
    class Beweging {
    private:


    public:
        Beweging();
        Beweging(float xVel, float yVel);

        void move(sf::Vector2f& position);
        float xVelocity; //usefull member variabel
        float yVelocity; //usefull member variabel
        float originalYVelocity; //usefull member variabel
    };
}
#endif 