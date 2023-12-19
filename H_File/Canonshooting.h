#ifndef CANON_POSITION_H
#define CANON_POSITION_H

#include "Weapon.h"
#include "TextureManager.h"
#include "Enemy.h"

namespace Towerdefense
{
    class Canonshooting : public Weapon {
    private:
        sf::Vector2f arrowPosition;
        TextureManager textureManager;
        sf::Vector2f direction;
        const unsigned char arrowSpeed = 20;

    public:
        sf::Sprite spriteCanonKogeltwee;

        Canonshooting();
        Canonshooting(const sf::Vector2f& initialPosition);
        void fire(sf::Vector2f& shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four) override;
        void update(float directionX, float directionY) override;
        void updateprobeer();
    };
}
#endif