#include "drawSpriteIfVisible.h"
#include <cmath>

#define M_PI 3.14159265358979323846

void drawSpriteIfVisible::drawSpriteVisible(sf::RenderWindow& window, sf::Sprite& sprite, bool isVisible) {
    if (isVisible) {
        window.draw(sprite);
    }
}