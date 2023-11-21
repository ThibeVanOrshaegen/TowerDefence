#ifndef DRAW_SPRITE_IF_VISIBLE_H
#define DRAW_SPRITE_IF_VISIBLE_H

#include <SFML/Graphics.hpp>
#include "HealthBar.h"

class drawSpriteIfVisible : public HealthBar{
public:
    static void drawSpriteVisible(sf::RenderWindow& window, sf::Sprite& sprite, bool isVisible);
};
#endif
