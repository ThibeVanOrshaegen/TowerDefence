#ifndef HANDLE_INTERSECTION_AND_DAMAGE_H
#define HANDLE_INTERSECTION_AND_DAMAGE_H


#include <SFML/Graphics.hpp>
#include "HealthBar.h" 
namespace Towerdefense
{
    class HandleIntersectionAndDamage : public HealthBar {
    public:
        static void handleIntersectionsAndDamage(sf::Sprite& weaponSprite, sf::Sprite& robotSprite, HealthBar& healthBar);
    };
}
#endif 

