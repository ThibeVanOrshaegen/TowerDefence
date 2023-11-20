#pragma once

#include "Weapon.h"
#include "TextureManager.h"

class Laser : public Weapon {
private:
    sf::Vector2f laserPosition;
    TextureManager textureManager;
    //sf::Sprite spritelaser;

public:
    sf::Sprite spritelaser;

    Laser(sf::Vector2f initialPosition);

    void fire(sf::Vector2f shootereenPosition) override;
    void update() override;

    //sf::Vector2f getPosition() const {
       // return spritelaser.getPosition();
    //}
};

