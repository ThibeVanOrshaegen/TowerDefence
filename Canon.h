#ifndef CANON_H
#define CANON_H

#include "Weapon.h"
#include "TextureManager.h"

class Canon : public Weapon {
private:
    sf::Vector2f arrowPosition;
    TextureManager textureManager;

public:

    sf::Sprite spritecanonred;

    Canon(sf::Vector2f initialPosition);

    void fire(sf::Vector2f shooterPosition) override;
    void update() override;

};
#endif 

