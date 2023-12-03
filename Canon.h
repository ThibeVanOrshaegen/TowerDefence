#ifndef CANON_H
#define CANON_H

#include "Weapon.h"
#include "TextureManager.h"
#include "EnemyOne.h"

namespace Towerdefense
{

    class Canon : public Weapon {
    private:
        sf::Vector2f arrowPosition;
        TextureManager textureManager;

    public:

        sf::Sprite spriteCanonKogeltwee;

        Canon(sf::Vector2f initialPosition);

        void fire(sf::Vector2f shooterPosition) override;
        void update() override;


    };
}
#endif 