#ifndef LASER_H
#define LASER_H

#include "Weapon.h"
#include "TextureManager.h"
namespace Towerdefense
{
    class Laser : public Weapon {
    private:
        sf::Vector2f laserPosition;
        TextureManager textureManager;

    public:
        sf::Sprite spritelaser;

        Laser(sf::Vector2f initialPosition);

        void fire(sf::Vector2f shootereenPosition) override; //polymorfisme
        void update() override;

    };
}
#endif

