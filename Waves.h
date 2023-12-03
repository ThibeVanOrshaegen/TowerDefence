// wave.h
#ifndef WAVE_H
#define WAVE_H

#include "Enemy.h"
#include <vector>

namespace Towerdefense
{
    class Wave
    {
    private:
        std::vector<Enemy> enemies; // The enemies in the wave

    public:
        Wave(); // Constructor
        virtual ~Wave() = default; // Virtual destructor

        // Function to add an enemy to the wave
        void addEnemy(sf::Vector2f initialPosition, sf::Vector2f size, int RandommaxHealth, float xVelocity, float yVelocity);

        // Function to update all enemies in the wave
        void update();

        // Function to check if the wave is complete (all enemies defeated)
        bool isComplete() const;

        // Function to get the enemies in the wave
        const std::vector<Enemy>& getEnemies() const;
    };
} // namespace Towerdefense

#endif // WAVE_H

