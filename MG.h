#pragma once

#include "Weapon.h"
#include "TextureManager.h"

class MG : public Weapon {
private:
    sf::Vector2f MGPosition;
    TextureManager textureManager;

public:
    sf::Sprite spriteMG;

    MG(sf::Vector2f initialPosition);

    void fire(sf::Vector2f shootervierPosition) override;
    void update() override;
};

