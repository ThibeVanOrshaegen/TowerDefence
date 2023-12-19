#include "drawSpriteIfVisible.h"
#include <cmath>

#define M_PI 3.14159265358979323846
namespace Towerdefense
{
    // Function to draw a sprite if it is visible
    void drawSpriteIfVisible::drawSpriteVisible(sf::RenderWindow& window, sf::Sprite& sprite, sf::Vector2f shooterPosition, sf::Vector2f origin) {
        sprite.setOrigin(origin);
        //sprite.setRotation(rotation);
        // Set the position of the sprite to the shooter's position
        sprite.setPosition(shooterPosition);
        window.draw(sprite);
    }
}
