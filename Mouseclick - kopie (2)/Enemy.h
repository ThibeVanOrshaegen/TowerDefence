#ifndef ENEMY_ONE_H
#define ENEMY_ONE_H

#include "HealthBar.h"
#include "TextureManager.h"
#include "Beweging.h"

namespace Towerdefense
{

    class Enemy : public HealthBar {
    public:

        TextureManager textureManager;
        Beweging beweging;
        sf::Sprite spriteEnemy;

        virtual ~Enemy() = default;
        Enemy(sf::Vector2f initialPosition, sf::Vector2f size, unsigned char RandommaxHealth, float xVelocity, float yVelocity);

        // Copy constructor
        Enemy(const Enemy& other);

        void updateMoveHealth();
        void updatePosition();
        void updateHealthBar();


    };
}
#endif