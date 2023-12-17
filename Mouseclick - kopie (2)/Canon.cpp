#include "Canon.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Towerdefense
{
    Canon::Canon(sf::Vector2f initialPosition) : spritecanonleveleen(), Canonposition(initialPosition) {
        //textureManager.texturecanonleveleen.loadFromFile("./Afbeelding/Cannon.png");
        if (!textureManager.texturecanonleveleen.loadFromFile("./Afbeelding/Cannon.png")) {
            // Handle error, e.g., print an error message
            std::cerr << "Failed to load Cannon.png" << std::endl;
        }
        spritecanonleveleen.setTexture(textureManager.texturecanonleveleen);
        spritecanonleveleen.setPosition(initialPosition);
        spritecanonleveleen.setScale(0.35f, 0.35f);
    }
    Canon::Canon() : spritecanonleveleen(), Canonposition(sf::Vector2f(0, 0)) {
    }
}