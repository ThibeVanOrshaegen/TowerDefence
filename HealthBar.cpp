#include "HealthBar.h"
namespace Towerdefense
{
    HealthBar::HealthBar(sf::Vector2f enemyPosition, sf::Vector2f size, int maxHealth)
        : currentHealth(maxHealth)
    {
        bar.setPosition(enemyPosition.x, enemyPosition.y - 20);
        bar.setSize(size);
        bar.setFillColor(sf::Color::Red);
    }

    int HealthBar::getCurrentHealth() const
    {
        return currentHealth;
    }

    void HealthBar::setCurrentHealth(int health)
    {
        currentHealth = health;
    }

    void HealthBar::applyDamage()
    {
        float redHealthBarSizeIncrease = 0.1f;
        sf::Vector2f newSize = bar.getSize() - sf::Vector2f(50 * redHealthBarSizeIncrease, 0);
        bar.setSize(newSize);
        if (newSize.x > 0)
        {
            bar.setSize(newSize);
        }
        else
        {
            bar.setSize(sf::Vector2f(0, bar.getSize().y));
        }
    }

    void HealthBar::updatePosition(const sf::Vector2f& newPosition)
    {
        position = newPosition;
        bar.setPosition(position);
    }
}

