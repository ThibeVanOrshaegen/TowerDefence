#include "ShooterUpdaterdrie.h"
#include "drawSpriteIfVisible.h"

#define M_PI 3.14159265358979323846

void ShooterUpdaterdrie::updateRotation(sf::Sprite& shooter, sf::Sprite& weapon, float distance, float dy, float dx) {
    if (distance < 150.0f) {
        float angle = atan2(dy, dx) * 180 / M_PI;
        shooter.setRotation(angle + 90);
        shooter.setOrigin(shooter.getLocalBounds().width / 2, shooter.getLocalBounds().height / 2);

        weapon.setRotation(angle + 90);
        weapon.setOrigin(weapon.getLocalBounds().width / 2, weapon.getLocalBounds().height / 2);
    }
    else if (distance > 150.0f) {
        shooter.setRotation(180);
    }
}
