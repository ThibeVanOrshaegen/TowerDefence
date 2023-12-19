#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SFML/Graphics.hpp>

namespace Towerdefense
{
    class HealthBar
    {
    public:
        sf::RectangleShape bar; 
        sf::Vector2f position;

        // Maximum health value (constant for all instances)

        unsigned char maxHealth = 100; //usefull member variabel
        int currentHealth = 10; //usefull member variabel

        // Constructor for creating a HealthBar with specified parameters
        HealthBar(sf::Vector2f enemyPosition, sf::Vector2f size, unsigned char maxHealth);
       
        // Copy constructor for creating a copy of an existing HealthBar
        HealthBar(const HealthBar& other);// const refernces for function

        sf::RectangleShape getBar() const;
        sf::Vector2f getPosition() const;

        // Getter methods to retrieve information about the health bar
        int getMaxHealth() const;
        int getCurrentHealth() const;

        // Setter methods to modify the health bar's properties
        void setBar(const sf::RectangleShape& newBar);
        void setPosition(const sf::Vector2f& newPosition);
        void setMaxHealth(int newMaxHealth);
        void setCurrentHealth(int newCurrentHealth);

        void applyDamage();
        void subtractHealth(int amountofdamage);

        void updatePositionHealth(const sf::Vector2f& newPosition);
    };
}
#endif
