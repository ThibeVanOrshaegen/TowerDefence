#pragma once
#include <SFML/Graphics.hpp>
#include "Weapon.h"

class EnemyManager {
private:

    Weapon& laser;
    Weapon& canon;
    Weapon& mg;

public:
    EnemyManager(Weapon& laser, Weapon& canon, Weapon& mg);

    void updateEnemyInteractions(const sf::Vector2f& laserPosition, const sf::Vector2f& canonPosition, const sf::Vector2f& mgPosition);
    void checkCollisions();
};
