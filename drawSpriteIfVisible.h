#pragma once

#include <SFML/Graphics.hpp>

class drawSpriteIfVisible {
public:
    static void drawSpriteVisible(sf::RenderWindow& window, sf::Sprite& sprite, bool isVisible);
};
