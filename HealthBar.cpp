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

    HealthBar::HealthBar(const HealthBar& other)
        : maxHealth(other.maxHealth), currentHealth(other.currentHealth)
    {
        // Copy other's position and bar attributes
        position = other.position;
        bar.setPosition(other.bar.getPosition());
        bar.setSize(other.bar.getSize());
        bar.setFillColor(other.bar.getFillColor());
    }

    //getter
    int HealthBar::getCurrentHealth() const//const reference for function
    {
        return currentHealth;
    }
    //setter
    void HealthBar::setCurrentHealth(int health)//constroleren health mee
    {
        currentHealth = health;
    }

    void HealthBar::applyDamage()
    {
        float redHealthBarSizeIncrease = 2.0f;
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
    inline int subtract(int a, int b)
    {
        return a - b;
    }
    void HealthBar::subtractHealth(int amountofdamage)
    {
        currentHealth = subtract(currentHealth, amountofdamage);
    }
    void HealthBar::updatePosition(const sf::Vector2f& newPosition)
    {
        position = newPosition;
        bar.setPosition(position);
    }

    void HealthBar::SendWave(sf::Vector2f WaveStartPosition)
    {
        // Implementation for SendWave
    }

    void HealthBar::updatewave()
    {
        // Implementation for updatewave
    }
}
