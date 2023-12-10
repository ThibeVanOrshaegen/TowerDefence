#ifndef CANON_H
#define CANON_H

#include "Weapon.h"
#include "TextureManager.h"
#include "EnemyOne.h"

namespace Towerdefense
{

    class Canonshooting : public Weapon{
    private:
        sf::Vector2f arrowPosition;
        TextureManager textureManager;
        sf::Vector2f direction;

    public:
        
        sf::Sprite spriteCanonKogeltwee;

        Canonshooting();

        Canonshooting(sf::Vector2f initialPosition);

        void fire(sf::Vector2f shooterPosition) override;
        void update() override;

        void setDirection(sf::Vector2f targetPosition);
        void update(sf::Vector2f targetPosition, sf::Vector2f shooterPosition);
    };
}
#endif 

