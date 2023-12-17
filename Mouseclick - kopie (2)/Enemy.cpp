#include "Enemy.h"
#include "HealthBar.h"
#include "Beweging.h"

#include <iostream>

namespace Towerdefense
{
    Enemy::Enemy(sf::Vector2f initialPosition, sf::Vector2f size, unsigned char health, float xVelocity, float yVelocity) //Takes parameters initialPosition, size, health, xVelocity, and yVelocity, a parameterized constructor.
        : HealthBar(initialPosition, size, maxHealth), beweging(xVelocity, yVelocity) {
        textureManager.textureEnemy.loadFromFile("./Afbeelding/Robottwee.png");
        spriteEnemy.setTexture(textureManager.textureEnemy);
        spriteEnemy.setPosition(initialPosition);
        spriteEnemy.setScale(0.3f, 0.3f);
    }

    // Copy constructor implementation
    Enemy::Enemy(const Enemy& other)
        : HealthBar(other),  // Call base class copy constructor
        textureManager(other.textureManager),
        beweging(other.beweging),
        spriteEnemy(other.spriteEnemy) {
    }

    void Enemy::updateMoveHealth() {
        sf::Vector2f EnemyPosition = spriteEnemy.getPosition();
        beweging.move(EnemyPosition);
        spriteEnemy.setPosition(EnemyPosition);
        if (spriteEnemy.getPosition().x >= 1002)
        {
            spriteEnemy.setPosition(sf::Vector2f(0, 410));
        }
        //std::cout << "Enemy Position enemy: (" << spriteEnemy.getPosition().x << ", " << spriteEnemy.getPosition().y << ")" << std::endl;
        updateHealthBar();
    }

    void Enemy::updateHealthBar() {
        float healthPercentage = static_cast<float>(getCurrentHealth()) / static_cast<float>(maxHealth);
        sf::Vector2f newSize(healthPercentage * bar.getSize().x, bar.getSize().y);
        bar.setSize(newSize);
    }
    void Enemy::updatePosition()
    {
        sf::Vector2f EnemyOnePosition = spriteEnemy.getPosition();
        beweging.move(EnemyOnePosition);
        spriteEnemy.setPosition(EnemyOnePosition);

    }
}