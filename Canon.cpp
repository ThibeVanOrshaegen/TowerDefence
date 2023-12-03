#include "Canon.h"
#include "EnemyOne.h"
namespace Towerdefense
{
    Canon::Canon(sf::Vector2f initialPosition) : spriteCanonKogeltwee(), arrowPosition(initialPosition) {//constrcutor,  member initialization in contructor
        textureManager.textureKogelCanon.loadFromFile("./Bullet_Cannon.png");
        spriteCanonKogeltwee.setTexture(textureManager.textureKogelCanon);
        spriteCanonKogeltwee.setPosition(initialPosition);
        spriteCanonKogeltwee.setScale(0.4f, 0.4f);
    }

    void Canon::fire(sf::Vector2f shooterPosition) {
        const float arrowSpeed = 20; //const reference for variable 

        arrowPosition.y += arrowSpeed;
        arrowPosition.x -= arrowSpeed;

        spriteCanonKogeltwee.setPosition(arrowPosition);
        if (arrowPosition.y < 0 || arrowPosition.x < 0)
        {
            arrowPosition.y = 240;
            arrowPosition.x = 240;
        }

    }
    void Canon::update() {
        const float arrowSpeed = 20; //const reference for variable 
        spriteCanonKogeltwee.move(-arrowSpeed, -arrowSpeed);
    }
}
