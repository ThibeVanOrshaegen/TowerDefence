#include "Updaterotation.h"
#include "TextureManager.h"
#include <cmath>

#define M_PI 3.14159265358979323846

namespace Towerdefense {

    void Updaterotation::updateShooterRotation(Canon* canonplaats, EnemyOne* snel, int Graden) {

            sf::Vector2f EnemyOnePosition = snel->spriteEnemyOne.getPosition();
            sf::Vector2f shooterPositionRotation = canonplaats->spritecanonleveleen.getPosition();

            float AfstandEnemyOneX = EnemyOnePosition.x - shooterPositionRotation.x;
            float AfstandEnemyOneY = EnemyOnePosition.y - shooterPositionRotation.y;

            float BerekeningHoekeen = std::sqrt(AfstandEnemyOneX * AfstandEnemyOneX + AfstandEnemyOneY * AfstandEnemyOneY);

            float Hoek = atan2(AfstandEnemyOneY, AfstandEnemyOneX) * 180 / M_PI;

            canonplaats->spritecanonleveleen.setRotation(Hoek + 90 + Graden);
            canonplaats->spritecanonleveleen.setOrigin(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2);

            //textureManager.spriteKogelCanon.setRotation(Hoek + 90 + Graden);
            //textureManager.spriteKogelCanon.setOrigin(textureManager.spriteKogelCanon.getLocalBounds().width / 2, textureManager.spriteKogelCanon.getLocalBounds().height / 2);
        }
}  // namespace Towerdefense
