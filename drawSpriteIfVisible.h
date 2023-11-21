#ifndef DRAW_SPRITE_IF_VISIBLE_H
#define DRAW_SPRITE_IF_VISIBLE_H

#include <SFML/Graphics.hpp>

class drawSpriteIfVisible {
public:
    static void drawSpriteVisible(sf::RenderWindow& window, sf::Sprite& sprite, bool isVisible);
};
#endif
