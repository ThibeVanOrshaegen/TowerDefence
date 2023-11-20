#include "EnemyManager.h"
#include <cmath>

EnemyManager::EnemyManager(Weapon& laser, Weapon& canon, Weapon& mg)
    : laser(laser), canon(canon), mg(mg) {}

void EnemyManager::updateEnemyInteractions(const sf::Vector2f& laserPosition, const sf::Vector2f& canonPosition, const sf::Vector2f& mgPosition) {
    // ... Calculate distances and angles as needed ...

    // Update rotations based on distances and angles

    // Check if weapons should be visible

    // Set sprite rotations and origins
}

void EnemyManager::checkCollisions() {
    // Check for collisions between weapons and enemies
}