#include "MG.h"
namespace Towerdefense
{
    MG::MG(sf::Vector2f initialPosition) : spriteMG(), MGPosition(initialPosition) {
        textureManager.textureMG.loadFromFile("./Bullet_MG.png");
        spriteMG.setTexture(textureManager.textureMG);
        spriteMG.setPosition(initialPosition);
        spriteMG.setScale(0.4f, 0.4f);
    }

    void MG::fire(sf::Vector2f shootervierPosition) {
        const float MGSpeed = 7;
        MGPosition.y += MGSpeed;
        MGPosition.x += MGSpeed;
        spriteMG.setPosition(MGPosition);
        if (MGPosition.y > 400 || MGPosition.x > 150)
        {
            MGPosition.y = 320;
            MGPosition.x = 65;
        }
    }

    void MG::update() {
        const float MGSpeed = 5;
        spriteMG.move(0, -MGSpeed);
    }
}