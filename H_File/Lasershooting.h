#ifndef LASER_SHOOTING_H
#define LASER_SHOOTING_H

#include "Weapon.h"
#include "TextureManager.h"
#include "Enemy.h"

namespace Towerdefense
{

    class Lasershooting : public Weapon {
    private:
        sf::Vector2f laserstraalPosition;
        TextureManager textureManager;
        sf::Vector2f direction;
        const unsigned char LaserSpeed = 20;
        static bool outOfRange;

    public:

        sf::Sprite spriteLaserKogeltwee;

        Lasershooting();
        Lasershooting(const sf::Vector2f& initialPosition);

        void fire(sf::Vector2f& shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four) override;
        void update(float directionX, float directionY) override;
        void updateprobeer();

        bool getOutofRange() const { return outOfRange; }


    };
}
#endif 
