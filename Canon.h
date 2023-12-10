#ifndef CANON_POSITION_H
#define CANON_POSITION_H

#include "Weapon.h"
#include "TextureManager.h"
#include "Canonshooting.h"
#include "EnemyOne.h"

namespace Towerdefense
{
    class Canon : public Canonshooting {
    private:
        sf::Vector2f Canonposition;
        TextureManager textureManager;

    public:

        sf::Sprite spritecanonleveleen;

        Canon(sf::Vector2f initialPosition);
    };
}
#endif 