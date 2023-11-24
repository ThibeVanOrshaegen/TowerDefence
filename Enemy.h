#ifndef ENEMY_H
#define ENEMY_H

#include "HealthBar.h"
#include "TextureManager.h"
#include "Beweging.h"
namespace Towerdefense
{
    class Enemy : public HealthBar {
    private:
        TextureManager textureManager;
        Beweging beweging;


    public:
        virtual ~Enemy() = default;

        sf::Sprite spriterobottwee;

        Enemy(sf::Vector2f initialPosition, sf::Vector2f size, int RandommaxHealth, float xVelocity, float yVelocity);

        void update();

        void updateHealthBar();
    };
}
#endif

