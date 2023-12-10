#include "Laser.h"
#include "EnemyOne.h"
namespace Towerdefense
{
    Laser::Laser(sf::Vector2f initialPosition) : spritelaserleveleen(), laserstraalPosition(initialPosition) {
        textureManager.texturelaserleveleen.loadFromFile("./Missile_Launcher.png");
        spritelaserleveleen.setTexture(textureManager.texturelaserleveleen);
        spritelaserleveleen.setPosition(initialPosition);
        spritelaserleveleen.setScale(0.4f, 0.4f);
        //spritelaserleveleen.setRotation(180);
    }
}