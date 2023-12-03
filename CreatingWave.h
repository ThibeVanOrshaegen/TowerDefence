#ifndef CREATING_WAVE_H
#define CREATING_WAVE_H

#include <SFML/Graphics.hpp>
namespace Towerdefense
{
    class CreateWave {
    public:
        virtual ~CreateWave() = default;
        virtual void SendWave(sf::Vector2f WaveStartPosition) = 0; //polymorfisme
        virtual void updatewave() = 0; //abstract
    };
}
#endif

