#include "Enemy.h"

Enemy::Enemy(sf::Vector2f initialPosition, sf::Vector2f size, int RandommaxHealth, float xVelocity, float yVelocity)
    : HealthBar(initialPosition, size, maxHealth), beweging(xVelocity, yVelocity) {
    textureManager.texturerobottwee.loadFromFile("./Robottwee.png");
    spriterobottwee.setTexture(textureManager.texturerobottwee);
    spriterobottwee.setPosition(initialPosition);
    spriterobottwee.setScale(0.3f, 0.3f);
}

void Enemy::update() {
    sf::Vector2f positionRobottwee = spriterobottwee.getPosition();
    beweging.move(positionRobottwee);
    spriterobottwee.setPosition(positionRobottwee);

    updateHealthBar();
}

void Enemy::updateHealthBar() {
    float healthPercentage = static_cast<float>(getCurrentHealth()) / static_cast<float>(maxHealth);
    sf::Vector2f newSize(healthPercentage * bar.getSize().x, bar.getSize().y);
    bar.setSize(newSize);
}
