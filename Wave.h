/*#ifndef WAVE_H
#define WAVE_H

#include "HealthBar.h"
#include "EnemyOne.h"
#include <vector>

namespace Towerdefense
{
    class Wave
    {
    private:
        std::vector<HealthBar> algemenehealthbar; // The enemies in the wave


    public:
        Wave(); // Constructor
        virtual ~Wave() = default; // Virtual destructor

        // Function to add an enemy to the wave
        void addHealthbarr(const EnemyOne& algemenebar);

        // Function to update all enemies in the wave
        void update();

        // Function to check if the wave is complete (all enemies defeated)
        bool isComplete() const;

        // Function to get the enemies in the wave
        const std::vector<HealthBar>& getHealthbarss() const;
    };
} // namespace Towerdefense

#endif // WAVE_H*/

