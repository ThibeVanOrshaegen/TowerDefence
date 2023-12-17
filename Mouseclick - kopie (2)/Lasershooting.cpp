#include "Lasershooting.h"
#include "TextureManager.h"
#include "Enemy.h"
#include <iostream>
#include <cmath>

namespace Towerdefense
{
    Lasershooting::Lasershooting() : spriteLaserKogeltwee(), laserstraalPosition(sf::Vector2f(0, 0)), direction(sf::Vector2f(-1, -1))
    {
        textureManager.textureKogelLaser.loadFromFile("./Afbeelding/Missile.png");
        spriteLaserKogeltwee.setTexture(textureManager.textureKogelCanon);
        spriteLaserKogeltwee.setScale(0.4f, 0.4f);
    }
    Lasershooting::Lasershooting(const sf::Vector2f& initialPosition) : spriteLaserKogeltwee(), laserstraalPosition(initialPosition), direction(sf::Vector2f(-1, -1)) {
        textureManager.textureKogelLaser.loadFromFile("./Afbeelding/Missile.png");
        spriteLaserKogeltwee.setTexture(textureManager.textureKogelLaser);
        spriteLaserKogeltwee.setPosition(initialPosition);
        spriteLaserKogeltwee.setScale(0.3f, 0.4f);
        //spriteLaserKogeltwee.setRotation(180);
    }

    void Lasershooting::fire(sf::Vector2f& shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four) {
        laserstraalPosition.y += LaserSpeed;
        laserstraalPosition.x += LaserSpeed;

        spriteLaserKogeltwee.setPosition(laserstraalPosition);
        if (laserstraalPosition.y > limit_one || laserstraalPosition.x > limit_two || laserstraalPosition.y < limit_three|| laserstraalPosition.x < limit_four)
        {
            laserstraalPosition = shooterPosition;
        }
    }
    void Lasershooting::update(float directionX, float directionY) {
        spriteLaserKogeltwee.move(direction.x * LaserSpeed, direction.y * LaserSpeed);
    }
    void Lasershooting::updateprobeer() {
        spriteLaserKogeltwee.move(direction.x * LaserSpeed, direction.y * LaserSpeed);
    }
};