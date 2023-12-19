#ifndef LASER_H
#define LASER_H

#include "Weapon.h"
#include "TextureManager.h"
#include "Lasershooting.h"
#include "Enemy.h"
namespace Towerdefense
{
    // Declaration of the Laser class, derived from Lasershooting
    class Laser : public Lasershooting {
    private:
        sf::Vector2f laserstraalPosition;
        TextureManager textureManager;

    public:
        sf::Sprite spritelaserleveleen;

        Laser(sf::Vector2f initialPosition);
        Laser();
        

    };
}
#endif

