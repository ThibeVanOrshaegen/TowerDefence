#pragma once

#include "TextureManager.h"

class Gold {
private:
    TextureManager textureManager;

public:
    int maxGold;
    int currentGold;

    Gold(sf::Vector2f GoldPosition, int maxGold);
};

