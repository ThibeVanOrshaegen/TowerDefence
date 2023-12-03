#include "Laser.h"
#include "TextureManager.h"
namespace Towerdefense
{
    Laser::Laser(sf::Vector2f initialPosition) : spritelasertwee(), laserPosition(initialPosition) {
        textureManager.textureKogelLaser.loadFromFile("./Missile.png");
        spritelasertwee.setTexture(textureManager.textureKogelLaser);
        spritelasertwee.setPosition(initialPosition);
        spritelasertwee.setScale(0.3f, 0.4f);
        spritelasertwee.setRotation(180);
    }

    void Laser::fire(sf::Vector2f shooterPosition) {
        const float laserSpeed = 7; //const reference for variable 
        laserPosition.y += laserSpeed;
        laserPosition.x += laserSpeed;

        spritelasertwee.setPosition(laserPosition);
        if (laserPosition.y > 500 || laserPosition.x > 700)
        {
            laserPosition = shooterPosition;
        }
    }

    void Laser::update() {
        const float laserSpeed = 20; //const reference for variable 
        spritelasertwee.move(-laserSpeed, -laserSpeed);
    }
}