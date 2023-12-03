// wave.cpp
#include "Waves.h"

namespace Towerdefense
{
    Wave::Wave() {} // You may implement this constructor if needed

    void Wave::addEnemy(sf::Vector2f initialPosition, sf::Vector2f size, int RandommaxHealth, float xVelocity, float yVelocity)
    {
        enemies.emplace_back(initialPosition, size, RandommaxHealth, xVelocity, yVelocity);
    }

    void Wave::update()
    {
        for (auto& enemy : enemies)
        {
            enemy.update();
        }
    }

    bool Wave::isComplete() const
    {
        // Check if all enemies are defeated
        for (const auto& enemy : enemies)
        {
            if (enemy.getCurrentHealth() > 0)
            {
                return false; // At least one enemy is still alive
            }
        }
        return true; // All enemies are defeated
    }

    const std::vector<Enemy>& Wave::getEnemies() const
    {
        return enemies;
    }
} // namespace Towerdefense
