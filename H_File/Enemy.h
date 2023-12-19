#ifndef ENEMY_ONE_H
#define ENEMY_ONE_H

#include "HealthBar.h"
#include "TextureManager.h"
#include "Beweging.h"

namespace Towerdefense
{
    // Declaration of the Enemy class, derived from HealthBar
    class Enemy : public HealthBar {
    public:
        // TextureManager for handling textures
        TextureManager textureManager;

        // Beweging for handling movement
        Beweging beweging;

        // Sprite representing the enemy
        sf::Sprite spriteEnemy;

        // Virtual destructor for proper polymorphic behavior
        virtual ~Enemy() = default;

        // Constructor for creating an Enemy with specified parameters
        Enemy(sf::Vector2f initialPosition, sf::Vector2f size, unsigned char RandommaxHealth, int xVelocity, int  yVelocity);

        // Copy constructor for creating a copy of an existing Enemy
        Enemy(const Enemy& other);

        // Method to update the movement and health of the enemy
        void updateMoveHealth();

        // Method to update the position of the enemy
        void updatePosition();

        // Method to update the health bar of the enemy
        void updateHealthBar();

    };
}

#endif
