#include "EnemyOne.h"
#include "Beweging.h"
#include "TextureManager.h"
#include "HealthBar.h"

namespace Towerdefense
{
    EnemyOne::EnemyOne(sf::Vector2f initialPosition, sf::Vector2f size, int health, float xVelocity, float yVelocity)
        : HealthBar(initialPosition, size, maxHealth), beweging(xVelocity, yVelocity) {
        textureManager.textureEnemyOne.loadFromFile("./Robottwee.png");
        spriteEnemyOne.setTexture(textureManager.textureEnemyOne);
        spriteEnemyOne.setPosition(initialPosition);
        spriteEnemyOne.setScale(0.3f, 0.3f);
    }

    /*EnemyOne::EnemyOne(const EnemyOne& other)
        : HealthBar(other), textureManager(other.textureManager), beweging(other.beweging)
    {
        // Copy other's spriteEnemyOne attributes
        spriteEnemyOne.setTexture(textureManager.textureEnemyOne);
        spriteEnemyOne.setPosition(other.spriteEnemyOne.getPosition());
        spriteEnemyOne.setScale(other.spriteEnemyOne.getScale());
    }*/

    void EnemyOne::update() {
        sf::Vector2f EnemyOnePosition = spriteEnemyOne.getPosition();
        beweging.move(EnemyOnePosition);
        spriteEnemyOne.setPosition(EnemyOnePosition);

        updateHealthBar();
    }

    void EnemyOne::updateHealthBar() {
        float healthPercentage = static_cast<float>(getCurrentHealth()) / static_cast<float>(maxHealth);
        sf::Vector2f newSize(healthPercentage * bar.getSize().x, bar.getSize().y);
        bar.setSize(newSize);
    }
}
