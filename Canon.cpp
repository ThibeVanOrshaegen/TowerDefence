#include "Canon.h"
namespace Towerdefense
{
    Canon::Canon(sf::Vector2f initialPosition) : spritecanonred(), arrowPosition(initialPosition) {
        textureManager.texturecanonred.loadFromFile("./Bullet_Cannon.png");
        spritecanonred.setTexture(textureManager.texturecanonred);
        spritecanonred.setPosition(initialPosition);
        spritecanonred.setScale(0.4f, 0.4f);
        spritecanonred.setRotation(180);
    }

    void Canon::fire(sf::Vector2f shooterPosition) {
        const float arrowSpeed = 5;
        arrowPosition.y += arrowSpeed;
        arrowPosition.x -= arrowSpeed;

        spritecanonred.setPosition(arrowPosition);
        if (arrowPosition.y < 0 || arrowPosition.x < 0)
        {
            arrowPosition.y = 240;
            arrowPosition.x = 240;
        }
    }

    void Canon::update() {
        const float arrowSpeed = 10; //2 useful unsigned chars or other better usage of memory efficient type?
        spritecanonred.move(0, -arrowSpeed);
    }
}