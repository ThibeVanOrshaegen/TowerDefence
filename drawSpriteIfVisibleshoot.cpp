#include "drawSpriteIfVisibleshoot.h"
#include <cmath>

#define M_PI 3.14159265358979323846
namespace Towerdefense
{
    void drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(sf::RenderWindow& window, sf::Sprite& sprite) {
        window.draw(sprite);
    }
}