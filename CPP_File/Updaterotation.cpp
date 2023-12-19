#include "Updaterotation.h"
#include "TextureManager.h"
#include <cmath>

#define M_PI 3.14159265358979323846

namespace Towerdefense {

    bool Towerdefense::Updaterotation::TurnAmmoOn = false;

    void Updaterotation::updateShooterRotationCanon(Canon* canonplaats, Enemy* snel, int Graden) {

        sf::Vector2f EnemyOnePosition = snel->spriteEnemy.getPosition();
        sf::Vector2f shooterPositionRotation = canonplaats->spritecanonleveleen.getPosition();

        float AfstandEnemyOneX = EnemyOnePosition.x - shooterPositionRotation.x;
        float AfstandEnemyOneY = EnemyOnePosition.y - shooterPositionRotation.y;

        float BerekeningHoekeen = std::sqrt(AfstandEnemyOneX * AfstandEnemyOneX + AfstandEnemyOneY * AfstandEnemyOneY);

        float Hoek = atan2(AfstandEnemyOneY, AfstandEnemyOneX) * 180 / M_PI;

        if (BerekeningHoekeen < 200)
        {
            canonplaats->spritecanonleveleen.setRotation(Hoek + 90 + Graden);
            canonplaats->spritecanonleveleen.setOrigin(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2);
            TurnAmmoOn = true;
        }
        else
        {
            canonplaats->spritecanonleveleen.setRotation(0);
            canonplaats->spritecanonleveleen.setOrigin(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2);
            TurnAmmoOn = false;
        }
    }
    void Updaterotation::updateShooterRotationLaser(Laser* laserplaats, Enemy* traag, int Graden) {

        sf::Vector2f EnemyOnePosition = traag->spriteEnemy.getPosition();
        sf::Vector2f shooterPositionRotation = laserplaats->spritelaserleveleen.getPosition();

        float AfstandEnemyOneX = EnemyOnePosition.x - shooterPositionRotation.x;
        float AfstandEnemyOneY = EnemyOnePosition.y - shooterPositionRotation.y;

        float BerekeningHoekeen = std::sqrt(AfstandEnemyOneX * AfstandEnemyOneX + AfstandEnemyOneY * AfstandEnemyOneY);

        float Hoek = atan2(AfstandEnemyOneY, AfstandEnemyOneX) * 180 / M_PI;

        laserplaats->spritelaserleveleen.setRotation(Hoek + 90 + Graden);
        laserplaats->spritelaserleveleen.setOrigin(laserplaats->spritelaserleveleen.getLocalBounds().width / 2, laserplaats->spritelaserleveleen.getLocalBounds().height / 2);

        //textureManager.spriteKogelCanon.setRotation(Hoek + 90 + Graden);
        //textureManager.spriteKogelCanon.setOrigin(textureManager.spriteKogelCanon.getLocalBounds().width / 2, textureManager.spriteKogelCanon.getLocalBounds().height / 2);
    }
    void Updaterotation::updateShooterRotationCanonkogel(Canonshooting* canonplaats, Enemy* snel, int Graden)
    {
        sf::Vector2f EnemyOnePosition = snel->spriteEnemy.getPosition();
        sf::Vector2f shooterPositionRotation = canonplaats->spriteCanonKogeltwee.getPosition();

        float AfstandEnemyOneX = EnemyOnePosition.x - shooterPositionRotation.x;
        float AfstandEnemyOneY = EnemyOnePosition.y - shooterPositionRotation.y;

        float BerekeningHoekeen = std::sqrt(AfstandEnemyOneX * AfstandEnemyOneX + AfstandEnemyOneY * AfstandEnemyOneY);

        float Hoek = atan2(AfstandEnemyOneY, AfstandEnemyOneX) * 180 / M_PI;

        canonplaats->spriteCanonKogeltwee.setRotation(Hoek + 90 + Graden);
        canonplaats->spriteCanonKogeltwee.setOrigin(canonplaats->spriteCanonKogeltwee.getLocalBounds().width / 2, canonplaats->spriteCanonKogeltwee.getLocalBounds().height / 2);

    }
    void Updaterotation::updateShooterRotationLaserkogel(Lasershooting* laserplaats, Enemy* traag, int Graden)
    {
        sf::Vector2f EnemyOnePosition = traag->spriteEnemy.getPosition();
        sf::Vector2f shooterPositionRotation = laserplaats->spriteLaserKogeltwee.getPosition();

        float AfstandEnemyOneX = EnemyOnePosition.x - shooterPositionRotation.x;
        float AfstandEnemyOneY = EnemyOnePosition.y - shooterPositionRotation.y;

        float BerekeningHoekeen = std::sqrt(AfstandEnemyOneX * AfstandEnemyOneX + AfstandEnemyOneY * AfstandEnemyOneY);

        float Hoek = atan2(AfstandEnemyOneY, AfstandEnemyOneX) * 180 / M_PI;

        laserplaats->spriteLaserKogeltwee.setRotation(Hoek + 90 + Graden);
        laserplaats->spriteLaserKogeltwee.setOrigin(laserplaats->spriteLaserKogeltwee.getLocalBounds().width / 2, laserplaats->spriteLaserKogeltwee.getLocalBounds().height / 2);
    }

}