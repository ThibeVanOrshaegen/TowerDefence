// Wave.h

#ifndef WAVE_H
#define WAVE_H

#include "HealthBar.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Towerdefense
{
    class EnemyOne;

    class Wave
    {
    private:
        std::vector<EnemyOne> EnemyOnewave; // The enemies in the wave

    public:
        Wave(); // Constructor
        //virtual ~Wave() = default; // Virtual destructor
        const std::vector<EnemyOne>& getEnemyOnewave() const {
            return EnemyOnewave;
        }

        // Function to update all enemies in the wave
        void updateEnemy();

        void addEnemyOne(const sf::Vector2f& position, const sf::Vector2f& size, int health, float speed);

        // Function to send enemies
        //void sendEnemies();

        // Function to check if the wave is complete (all enemies defeated)
        //bool isWaveComplete() const;

    };
} // namespace Towerdefense

#endif // WAVE_H

