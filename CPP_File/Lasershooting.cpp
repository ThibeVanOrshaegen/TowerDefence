#include "Lasershooting.h"
#include "TextureManager.h"
#include "Enemy.h"
#include <iostream>
#include <cmath>

namespace Towerdefense
{
    Lasershooting::Lasershooting() : spriteLaserKogeltwee(), laserstraalPosition(sf::Vector2f(0, 0)), direction(sf::Vector2f(-1, -1))
    {
        textureManager.textureKogelLaser.loadFromFile("./Missile.png");
        spriteLaserKogeltwee.setTexture(textureManager.textureKogelCanon);
        spriteLaserKogeltwee.setScale(0.4f, 0.4f);
    }

    // Constructor definition for Lasershooting, initializing with an initial position
    Lasershooting::Lasershooting(const sf::Vector2f& initialPosition) : spriteLaserKogeltwee(), laserstraalPosition(initialPosition), direction(sf::Vector2f(-1, -1)) {
        textureManager.textureKogelLaser.loadFromFile("./Missile.png");
        spriteLaserKogeltwee.setTexture(textureManager.textureKogelLaser);
        spriteLaserKogeltwee.setPosition(initialPosition);
        spriteLaserKogeltwee.setScale(0.3f, 0.4f);
        //spriteLaserKogeltwee.setRotation(180);
    }
    // Definition of a static member variable for Lasershooting to track if it's out of range
    bool Towerdefense::Lasershooting::outOfRange = false;

    void Lasershooting::fire(sf::Vector2f& shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four) {
        laserstraalPosition.y += direction.x * LaserSpeed;
        laserstraalPosition.x += direction.y * LaserSpeed;

        spriteLaserKogeltwee.setPosition(laserstraalPosition);
        if (laserstraalPosition.y > limit_one || laserstraalPosition.x > limit_two || laserstraalPosition.y < limit_three|| laserstraalPosition.x < limit_four)
        {
            laserstraalPosition = shooterPosition;
            outOfRange = true;
        }
    }

    void Lasershooting::update(float directionX, float directionY) {
        direction.x = directionX;
        direction.y = directionY;
        spriteLaserKogeltwee.move(direction.x * LaserSpeed, direction.y * LaserSpeed);
    }
    void Lasershooting::updateprobeer() {
        spriteLaserKogeltwee.move(direction.x * LaserSpeed, direction.y * LaserSpeed);
    }
};

