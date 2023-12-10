// Wave.cpp

#include "Wave.h"
#include <SFML/Graphics.hpp>
#include "EnemyOne.h"
namespace Towerdefense
{
    Wave::Wave()
    {
        // Initialize any necessary members in the constructor if needed
    }

    void Wave::addEnemyOne(const sf::Vector2f& position, const sf::Vector2f& size, int health, float speed)
    {
        // Create a new EnemyOne object using the provided parameters
        EnemyOne newEnemy(position, size, health, speed, speed);

        // Add the newEnemy to the EnemyOnewave vector
        EnemyOnewave.push_back(newEnemy);
    }
    void Wave::updateEnemy()
    {
        // Implement the updateEnemy function
        for (auto& enemy : EnemyOnewave)
        {
            enemy.update();
        }
    }

}
