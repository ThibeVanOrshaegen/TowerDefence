#ifndef DRAW_SPRITE_IF_VISIBLE_SHOOT_H
#define DRAW_SPRITE_IF_VISIBLE_SHOOT_H

#include <SFML/Graphics.hpp>
#include "HealthBar.h"
namespace Towerdefense
{

    class drawSpriteIfVisibleshoot : public HealthBar {
    public:
        static void drawSpriteVisibleshoot(sf::RenderWindow& window, sf::Sprite& sprite);
    };
}
#endif
