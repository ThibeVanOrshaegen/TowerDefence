#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SFML/Graphics.hpp>
#include "CreatingWave.h"
namespace Towerdefense
{
    class EnemyOne;
    class Wave;
    class Game;

    class HealthBar : public CreateWave
    {
    public:
        sf::RectangleShape bar;
        sf::Vector2f position;
        unsigned char maxHealth = 100;
        unsigned char currentHealth = 10;

        HealthBar(sf::Vector2f enemyPosition, sf::Vector2f size, int maxHealth);
        HealthBar(const HealthBar& other); //Copy

        void setCurrentHealth(int health);
        void applyDamage();
        void updatePosition(const sf::Vector2f& newPosition);
        void subtractHealth(int amountofdamage);
        int getCurrentHealth() const;

        void SendWave(sf::Vector2f WaveStartPosition) override;
        void updatewave() override;
    private:


        friend class EnemyOne; //friend class
        friend class Wave; //friend class
        friend class HealthBar;
        friend class Game;
    };
}
#endif

