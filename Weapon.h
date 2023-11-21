#ifndef WEAPONS_H
#define WEAPONS_H

#include <SFML/Graphics.hpp>

class Weapon {
public:
    virtual ~Weapon() = default;
    virtual void fire(sf::Vector2f shooterPosition) = 0;
    virtual void update() = 0;
};
#endif
