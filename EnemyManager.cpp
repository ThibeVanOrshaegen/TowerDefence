#include "EnemyManager.h"
#include <cmath>

namespace Towerdefense
{
    EnemyManager::EnemyManager(Weapon& laser, Weapon& canon, Weapon& mg)
        : laser(laser), canon(canon), mg(mg) {}

    void EnemyManager::updateEnemyInteractions(const sf::Vector2f& laserPosition, const sf::Vector2f& canonPosition, const sf::Vector2f& mgPosition) {

    }

    void EnemyManager::checkCollisions() {

    }
}