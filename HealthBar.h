#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SFML/Graphics.hpp>

class HealthBar
{
public:
    sf::RectangleShape bar;
    sf::Vector2f position;
    int maxHealth = 100;
    int currentHealth = 0;

    HealthBar(sf::Vector2f enemyPosition, sf::Vector2f size, int maxHealth);
    int getCurrentHealth() const;
    void setCurrentHealth(int health);
    void applyDamage();
    void updatePosition(const sf::Vector2f& newPosition);
};
#endif

