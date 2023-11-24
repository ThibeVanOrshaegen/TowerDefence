#include "Laser.h"
#include "TextureManager.h"
namespace Towerdefense
{
Laser::Laser(sf::Vector2f initialPosition) : spritelaser(), laserPosition(initialPosition) {
    textureManager.texturelaser.loadFromFile("./Missile.png");
    spritelaser.setTexture(textureManager.texturelaser);
    spritelaser.setPosition(initialPosition);
    spritelaser.setScale(0.4f, 0.4f);
    spritelaser.setRotation(180);
}

void Laser::fire(sf::Vector2f shootereenPosition) {
    const float laserSpeed = 7;
    laserPosition.y += laserSpeed;
    laserPosition.x += laserSpeed;

    spritelaser.setPosition(laserPosition);
    if (laserPosition.y > 500 || laserPosition.x > 700)
    {
        laserPosition.y = 410;
        laserPosition.x = 600;
    }
}

void Laser::update() {
    const float laserSpeed = 5;
    spritelaser.move(-laserSpeed, -laserSpeed);
}
}