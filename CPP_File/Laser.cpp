#include "Laser.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Towerdefense
{
    Laser::Laser(sf::Vector2f initialPosition) : spritelaserleveleen(), laserstraalPosition(initialPosition) {
        // Load the texture for the laser from a file
        textureManager.texturelaserleveleen.loadFromFile("./Missile_Launcher.png");
        spritelaserleveleen.setTexture(textureManager.texturelaserleveleen);

        // Set the initial position and scale for the laser sprite
        spritelaserleveleen.setPosition(initialPosition);
        spritelaserleveleen.setScale(0.35f, 0.35f);
        //spritelaserleveleen.setRotation(180);
    }
    Laser::Laser() : spritelaserleveleen(), laserstraalPosition(sf::Vector2f(0, 0)) {
    }
}
