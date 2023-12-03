#ifndef ENEMY_ONE_H
#define ENEMY_ONE_H

#include "HealthBar.h"
#include "TextureManager.h"
#include "Beweging.h"

namespace Towerdefense
{
    class Canon;

    class EnemyOne : public HealthBar {
    private:

        TextureManager textureManager;
        Beweging beweging;
        friend class Canon;

    public:

        sf::Sprite spriteEnemyOne;

        virtual ~EnemyOne() = default;

        EnemyOne(sf::Vector2f initialPosition, sf::Vector2f size, int RandommaxHealth, float xVelocity, float yVelocity); //constructor
        EnemyOne(const EnemyOne& other);

        void update();

        void updateHealthBar();


    };
}
#endif

