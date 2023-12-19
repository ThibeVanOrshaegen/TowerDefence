#include <SFML/Graphics.hpp>
#include "HealthBar.h" 
namespace Towerdefense
{
    // Declaration of HandleIntersectionAndDamage class, derived from HealthBar

    class HandleIntersectionAndDamage : public HealthBar {
    public:
        // Static method to handle intersections and damage between weapon and robot

        static void handleIntersectionsAndDamage(sf::Sprite& weaponSprite, sf::Sprite& robotSprite, HealthBar& healthBar);
    };
}
#endif 


