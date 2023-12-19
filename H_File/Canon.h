#ifndef CANON_H
#define CANON_H

#include "Weapon.h"
#include "TextureManager.h"
#include "Canonshooting.h"
#include "Enemy.h"

namespace Towerdefense
{
    class Canon : public Canonshooting {
    private:
        sf::Vector2f Canonposition;
        TextureManager textureManager;

    public:

        sf::Sprite spritecanonleveleen;

        Canon(sf::Vector2f initialPosition);

        // Default constructor
        Canon();
    };
}
#endif 
