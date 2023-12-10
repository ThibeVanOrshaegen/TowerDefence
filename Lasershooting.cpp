#include "Lasershooting.h"
#include "TextureManager.h"
namespace Towerdefense
{
    Lasershooting::Lasershooting() : spriteLaserKogeltwee(), laserstraalPosition(sf::Vector2f(0, 0))
    {
        textureManager.textureKogelLaser.loadFromFile("./Missile.png");
        spriteLaserKogeltwee.setTexture(textureManager.textureKogelCanon);
        spriteLaserKogeltwee.setScale(0.4f, 0.4f);
    }
    Lasershooting::Lasershooting(sf::Vector2f initialPosition) : spriteLaserKogeltwee(), laserstraalPosition(initialPosition) {
        textureManager.textureKogelLaser.loadFromFile("./Missile.png");
        spriteLaserKogeltwee.setTexture(textureManager.textureKogelLaser);
        spriteLaserKogeltwee.setPosition(initialPosition);
        spriteLaserKogeltwee.setScale(0.3f, 0.4f);
        //spriteLaserKogeltwee.setRotation(180);
    }

    void Lasershooting::fire(sf::Vector2f shooterPosition) {
        const unsigned char laserSpeed = 7; //const reference for variable 
        laserstraalPosition.y += laserSpeed;
        laserstraalPosition.x += laserSpeed;

        spriteLaserKogeltwee.setPosition(laserstraalPosition);
        if (laserstraalPosition.y > 1000 || laserstraalPosition.x > 1000)
        {
            laserstraalPosition = shooterPosition;
        }
    }

    void Lasershooting::update() {
        const unsigned char laserSpeed = 20; //const reference for variable 
        spriteLaserKogeltwee.move(-laserSpeed, -laserSpeed);
    }
}
