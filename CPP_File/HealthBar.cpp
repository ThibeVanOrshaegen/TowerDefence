#include "HealthBar.h"
namespace Towerdefense
{
 
    HealthBar::HealthBar(sf::Vector2f enemyPosition, sf::Vector2f size, unsigned char maxHealth) // primary constructor, Takes parameters enemyPosition, size, and maxHealth, a parameterized constructor.
        : currentHealth(maxHealth)
        //currentHealth member variable with the value of maxHealth that is passed as a parameter to the constructor
    {
        bar.setPosition(enemyPosition.x, enemyPosition.y - 20);
        bar.setSize(size);
        bar.setFillColor(sf::Color::Red);
    }

    HealthBar::HealthBar(const HealthBar& other) // const references for variables, copy constructor
        : maxHealth(other.maxHealth), currentHealth(other.currentHealth)
    {
        // Copy other's position and bar attributes
        position = other.position;
        bar.setPosition(other.bar.getPosition());
        bar.setSize(other.bar.getSize());
        bar.setFillColor(other.bar.getFillColor());
    }

    // Getter implementations
    sf::RectangleShape HealthBar::getBar() const 
    {
        return bar;
    }

    sf::Vector2f HealthBar::getPosition() const 
    {
        return position;
    }

    int HealthBar::getMaxHealth() const 
    {
        return maxHealth;
    }

    int HealthBar::getCurrentHealth() const 
    {
        return currentHealth;
    }

    // Setter implementations
    void HealthBar::setBar(const sf::RectangleShape& newBar)
    {
        bar = newBar;
    }

    void HealthBar::setPosition(const sf::Vector2f& newPosition)
    {
        position = newPosition;
    }

    void HealthBar::setMaxHealth(int newMaxHealth)
    {
        maxHealth = newMaxHealth;
    }

    void HealthBar::setCurrentHealth(int newCurrentHealth)
    {
        currentHealth = newCurrentHealth;
    }

    void HealthBar::updatePositionHealth(const sf::Vector2f& newPosition)
    {
        position = newPosition;
        bar.setPosition(position);
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

}
