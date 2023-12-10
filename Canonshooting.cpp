#include "Canonshooting.h"
#include "EnemyOne.h"

namespace Towerdefense {

    Canonshooting::Canonshooting() : spriteCanonKogeltwee(), arrowPosition(sf::Vector2f(0, 0)), direction(sf::Vector2f(-1, -1)) {
        textureManager.textureKogelCanon.loadFromFile("./Bullet_Cannon.png");
        spriteCanonKogeltwee.setTexture(textureManager.textureKogelCanon);
        spriteCanonKogeltwee.setScale(0.4f, 0.4f);
    }

    Canonshooting::Canonshooting(sf::Vector2f initialPosition) : spriteCanonKogeltwee(), arrowPosition(initialPosition), direction(sf::Vector2f(-1, -1)) {
        textureManager.textureKogelCanon.loadFromFile("./Bullet_Cannon.png");
        spriteCanonKogeltwee.setTexture(textureManager.textureKogelCanon);
        spriteCanonKogeltwee.setPosition(initialPosition);
        spriteCanonKogeltwee.setScale(0.4f, 0.4f);
    }

    void Canonshooting::fire(sf::Vector2f shooterPosition) {
        const unsigned char arrowSpeed = 10;

        // Move in the specified direction
        arrowPosition.x += direction.x * arrowSpeed;
        arrowPosition.y += direction.y * arrowSpeed;

        spriteCanonKogeltwee.setPosition(arrowPosition);

        // Reset position if out of bounds
        if (arrowPosition.y < 0 || arrowPosition.x < 0) {
            arrowPosition = shooterPosition;
        }
    }

    void Canonshooting::update() {
        const unsigned char arrowSpeed = 10;
        spriteCanonKogeltwee.move(direction.x * arrowSpeed, direction.y * arrowSpeed);
    }

    void Canonshooting::setDirection(sf::Vector2f targetPosition) {
        sf::Vector2f delta = targetPosition - arrowPosition;
        float length = std::sqrt(delta.x * delta.x + delta.y * delta.y);
        direction = delta / length;
    }

    void Canonshooting::update(sf::Vector2f targetPosition, sf::Vector2f shooterPosition) {
        setDirection(targetPosition);
        fire(shooterPosition);
    }
}
