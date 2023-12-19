#include "Canonshooting.h"
#include "Enemy.h"
#include <iostream>
#include <cmath>

namespace Towerdefense {

    Canonshooting::Canonshooting() : spriteCanonKogeltwee(), arrowPosition(sf::Vector2f(0, 0)), direction(sf::Vector2f(-1, -1)) {
        textureManager.textureKogelCanon.loadFromFile("./Bullet_Cannon.png");
        spriteCanonKogeltwee.setTexture(textureManager.textureKogelCanon);
        spriteCanonKogeltwee.setScale(0.4f, 0.4f);
    }

    Canonshooting::Canonshooting(const sf::Vector2f& initialPosition) : spriteCanonKogeltwee(), arrowPosition(initialPosition), direction(sf::Vector2f(-1, -1)) {
        textureManager.textureKogelCanon.loadFromFile("./Bullet_Cannon.png");
        spriteCanonKogeltwee.setTexture(textureManager.textureKogelCanon);
        spriteCanonKogeltwee.setPosition(initialPosition);
        spriteCanonKogeltwee.setScale(0.4f, 0.4f);
    }

    void Canonshooting::fire(sf::Vector2f& shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four) { // call-by-reference
        arrowPosition.x += direction.x * arrowSpeed;
        arrowPosition.y += direction.y * arrowSpeed;

        spriteCanonKogeltwee.setPosition(arrowPosition);
        if (arrowPosition.y > limit_one || arrowPosition.x > limit_two || arrowPosition.y < limit_three || arrowPosition.x< limit_four) {
            arrowPosition = shooterPosition;
        }
    }

    void Canonshooting::update(float directionX, float directionY) { // separate x and y components
        direction.x = directionX;
        direction.y = directionY;
        spriteCanonKogeltwee.move(direction.x * arrowSpeed, direction.y * arrowSpeed);
    }

    void Canonshooting::updateprobeer() {
        spriteCanonKogeltwee.move(direction.x * arrowSpeed, direction.y * arrowSpeed);
    }
}
