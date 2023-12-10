#ifndef LASER_SHOOTING_H
#define LASER_SHOOTING_H

#include "Weapon.h"
#include "TextureManager.h"
#include "EnemyOne.h"

namespace Towerdefense
{

    class Lasershooting : public Weapon {
    private:
        sf::Vector2f laserstraalPosition;
        TextureManager textureManager;

    public:

        sf::Sprite spriteLaserKogeltwee;

        Lasershooting();

        Lasershooting(sf::Vector2f initialPosition);

        void fire(sf::Vector2f shooterPosition) override;
        void update() override;

    };
}
#endif 

