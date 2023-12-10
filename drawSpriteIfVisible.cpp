#include "drawSpriteIfVisible.h"
#include <cmath>

#define M_PI 3.14159265358979323846
namespace Towerdefense
{
    void drawSpriteIfVisible::drawSpriteVisible(sf::RenderWindow& window, sf::Sprite& sprite, sf::Vector2f shooterPosition, sf::Vector2f origin) {
           sprite.setOrigin(origin);
           //sprite.setRotation(rotation);
           sprite.setPosition(shooterPosition);
           window.draw(sprite);
    }
}