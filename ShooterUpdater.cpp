// ShooterUpdater.cpp
/*
#include "ShooterUpdater.h"
#include "HealthBar.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Canon.h"
#include "Laser.h"
#include "MG.h"
//#include "EnemyManager.h"
#include "TextureManager.h"
#include <vector>

#define M_PI 3.14159265358979323846


void ShooterUpdater::updateShooterRotation(sf::Sprite& shooterSprite, sf::Sprite& laserSprite, float& spriteVisibleLaser, const sf::Vector2f& robotPosition, const sf::Vector2f& shooterPosition, float& distance) {
    sf::Vector2f shooterdriePosition = textureManager.spriteshooterdrie.getPosition();
    sf::Vector2f shootereenPosition = textureManager.spriteshootereen.getPosition();
    sf::Vector2f shootervierPosition = textureManager.spriteshootervier.getPosition();

    sf::Vector2f laserPosition = laser.spritelaser.getPosition();
    sf::Vector2f laserPositioneen = lasereen.spritelaser.getPosition();
    sf::Vector2f laserPositiontwee = lasertwee.spritelaser.getPosition();
    sf::Vector2f laserPositiondrie = laserdrie.spritelaser.getPosition();

    sf::Vector2f MGPosition = mg.spriteMG.getPosition();
    sf::Vector2f arrowPosition = canon.arrow.getPosition();

    sf::Vector2f robotPositiontraag = traag.spriterobottwee.getPosition();
    sf::Vector2f robotPositionsnel = snel.spriterobottwee.getPosition();
    sf::Vector2f robotPositionsnelxtraagy = snelxtraagy.spriterobottwee.getPosition();
    sf::Vector2f robotPositiontraagxsnely = traagxsnely.spriterobottwee.getPosition();

    //////////////////////////////////////////////////////////
    float dxeen = robotPositiontraag.x - shootereenPosition.x;
    float dyeen = robotPositiontraag.y - shootereenPosition.y;

    float dxdrie = robotPositiontraag.x - shooterdriePosition.x;
    float dydrie = robotPositiontraag.y - shooterdriePosition.y;

    float dxvier = robotPositiontraag.x - shootervierPosition.x;
    float dyvier = robotPositiontraag.y - shootervierPosition.y;
    //////////////////////////////////////////////////////////
    float dxdrieeen = robotPositionsnel.x - shooterdriePosition.x;
    float dydrieeen = robotPositionsnel.y - shooterdriePosition.y;

    float dxeeneen = robotPositionsnel.x - shootereenPosition.x;
    float dyeeneen = robotPositionsnel.y - shootereenPosition.y;

    float dxviereen = robotPositionsnel.x - shootervierPosition.x;
    float dyviereen = robotPositionsnel.y - shootervierPosition.y;
    //////////////////////////////////////////////////////////

    float dxdrietwee = robotPositionsnelxtraagy.x - shooterdriePosition.x;
    float dydrietwee = robotPositionsnelxtraagy.y - shooterdriePosition.y;

    float dxeentwee = robotPositionsnelxtraagy.x - shootereenPosition.x;
    float dyeentwee = robotPositionsnelxtraagy.y - shootereenPosition.y;

    float dxviertwee = robotPositionsnelxtraagy.x - shootervierPosition.x;
    float dyviertwee = robotPositionsnelxtraagy.y - shootervierPosition.y;
    //////////////////////////////////////////////////////////
    float dxdriedrie = robotPositiontraagxsnely.x - shooterdriePosition.x;
    float dydriedrie = robotPositiontraagxsnely.y - shooterdriePosition.y;

    float dxeendrie = robotPositiontraagxsnely.x - shootereenPosition.x;
    float dyeendrie = robotPositiontraagxsnely.y - shootereenPosition.y;

    float dxvierdrie = robotPositiontraagxsnely.x - shootervierPosition.x;
    float dyvierdrie = robotPositiontraagxsnely.y - shootervierPosition.y;
    //////////////////////////////////////////////////////////
    float distanceeen = std::sqrt(dxeen * dxeen + dyeen * dyeen);
    float distancedrie = std::sqrt(dxdrie * dxdrie + dydrie * dydrie);
    float distancevier = std::sqrt(dxvier * dxvier + dyvier * dyvier);

    float distanceeeneen = std::sqrt(dxeeneen * dxeeneen + dyeeneen * dyeeneen);
    float distancedrieeen = std::sqrt(dxdrieeen * dxdrieeen + dydrieeen * dydrieeen);
    float distanceviereen = std::sqrt(dxviereen * dxviereen + dyviereen * dyviereen);

    float distanceeentwee = std::sqrt(dxeentwee * dxeentwee + dyeentwee * dyeentwee);
    float distancedrietwee = std::sqrt(dxdrietwee * dxdrietwee + dydrietwee * dydrietwee);
    float distanceviertwee = std::sqrt(dxviertwee * dxviertwee + dyviertwee * dyviertwee);

    float distanceeendrie = std::sqrt(dxeendrie * dxeendrie + dyeendrie * dyeendrie);
    float distancedriedrie = std::sqrt(dxdriedrie * dxdriedrie + dydriedrie * dydriedrie);
    float distancevierdrie = std::sqrt(dxvierdrie * dxvierdrie + dyvierdrie * dyvierdrie);

    float gezondheidsnel = snel.getCurrentHealth();
    float gezondheidtraag = traag.getCurrentHealth();
    float gezondheidsnelxtraagy = snelxtraagy.getCurrentHealth();
    float gezondheidtraagxsnely = traagxsnely.getCurrentHealth();



    //if ((distancedrie < 150.0f) && (gezondheidtraag > 0))
    if (distancedrie < 150.0f)
    {//traag
        float angledrie = atan2(dydrie, dxdrie) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledrie + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        laser.spritelaser.setRotation(angledrie + 90); //werkt
        laser.spritelaser.setOrigin(laser.spritelaser.getLocalBounds().width / 2, laser.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelaser = true;


    } //if dictancedrie <distancedrieeen && distancedrie currenthealt > 0 else if distancedrieeen < distancedrie && distancedrie currenthealt > 0
    //zolang de ene is aan het schieten kan de andere niet schieten
    //mss else if van maken
    //if ((distancedrieeen < 150.0f) && (gezondheidsnel > 0))
    if (distancedrieeen < 150.0f)
    {//snel
        float angledrieeen = atan2(dydrieeen, dxdrieeen) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledrieeen + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        lasereen.spritelaser.setRotation(angledrieeen + 90); //werkt
        lasereen.spritelaser.setOrigin(lasereen.spritelaser.getLocalBounds().width / 2, lasereen.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelasereen = true;

    }
    //if ((distancedrietwee < 150.0f ) && (gezondheidsnelxtraagy > 0))
    if (distancedrietwee < 150.0f)
    {
        float angledrietwee = atan2(dydrietwee, dxdrietwee) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledrietwee + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        laser.spritelaser.setRotation(angledrietwee + 90); //werkt
        laser.spritelaser.setOrigin(lasertwee.spritelaser.getLocalBounds().width / 2, lasertwee.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelasertwee = true;

    }
    //if ((distancedriedrie < 150.0f) && (gezondheidsnelxtraagy > 0))
    if (distancedriedrie < 150.0f)
    {
        float angledriedrie = atan2(dydriedrie, dxdriedrie) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledriedrie + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        laser.spritelaser.setRotation(angledriedrie + 90); //werkt
        laser.spritelaser.setOrigin(laserdrie.spritelaser.getLocalBounds().width / 2, laserdrie.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelaserdrie = true;
    }

    if (distanceeen < 300.0f)
    {
        float angleeen = atan2(dyeen, dxeen) * 180 / M_PI;
        textureManager.spriteshootereen.setRotation(angleeen + 270);
        textureManager.spriteshootereen.setOrigin(textureManager.spriteshootereen.getLocalBounds().width / 2, textureManager.spriteshootereen.getLocalBounds().height / 2);

        canon.arrow.setRotation(angleeen + 270);
        canon.arrow.setOrigin(canon.arrow.getLocalBounds().width / 2, canon.arrow.getLocalBounds().height / 2);

        spriteVisiblecanon = true;
    }
    if (distanceeeneen < 300.0f)
    {
        float angleeeneen = atan2(dyeeneen, dxeeneen) * 180 / M_PI;
        textureManager.spriteshootereen.setRotation(angleeeneen + 270);
        textureManager.spriteshootereen.setOrigin(textureManager.spriteshootereen.getLocalBounds().width / 2, textureManager.spriteshootereen.getLocalBounds().height / 2);

        canon.arrow.setRotation(angleeeneen + 270);
        canon.arrow.setOrigin(canon.arrow.getLocalBounds().width / 2, canon.arrow.getLocalBounds().height / 2);

        spriteVisiblecanon = true;
    }

    if (distanceeentwee < 300.0f)
    {
        float angleeentwee = atan2(dyeentwee, dxeentwee) * 180 / M_PI;
        textureManager.spriteshootereen.setRotation(angleeentwee + 270);
        textureManager.spriteshootereen.setOrigin(textureManager.spriteshootereen.getLocalBounds().width / 2, textureManager.spriteshootereen.getLocalBounds().height / 2);

        canon.arrow.setRotation(angleeentwee + 270);
        canon.arrow.setOrigin(canon.arrow.getLocalBounds().width / 2, canon.arrow.getLocalBounds().height / 2);

        spriteVisiblecanon = true;
    }
    if (distanceeendrie < 300.0f)
    {
        float angleeendrie = atan2(dyeendrie, dxeendrie) * 180 / M_PI;
        textureManager.spriteshootereen.setRotation(angleeendrie + 270);
        textureManager.spriteshootereen.setOrigin(textureManager.spriteshootereen.getLocalBounds().width / 2, textureManager.spriteshootereen.getLocalBounds().height / 2);

        canon.arrow.setRotation(angleeendrie + 270);
        canon.arrow.setOrigin(canon.arrow.getLocalBounds().width / 2, canon.arrow.getLocalBounds().height / 2);

        spriteVisiblecanon = true;
    }

    if (distancevier < 100.0f)
    {
        float anglevier = atan2(dyvier, dxvier) * 90 / M_PI;
        textureManager.spriteshootervier.setRotation(anglevier + 90);
        textureManager.spriteshootervier.setOrigin(textureManager.spriteshootervier.getLocalBounds().width / 2, textureManager.spriteshootervier.getLocalBounds().height / 2);

        mg.spriteMG.setRotation(anglevier + 90); //werkt
        mg.spriteMG.setOrigin(mg.spriteMG.getLocalBounds().width / 2, mg.spriteMG.getLocalBounds().height / 2);

        spriteVisiblemg = true;
    }
    if (distanceviereen < 100.0f)
    {
        float anglevier = atan2(dyviereen, dxviereen) * 90 / M_PI;
        textureManager.spriteshootervier.setRotation(anglevier + 90);
        textureManager.spriteshootervier.setOrigin(textureManager.spriteshootervier.getLocalBounds().width / 2, textureManager.spriteshootervier.getLocalBounds().height / 2);

        mg.spriteMG.setRotation(anglevier + 90); //werkt
        mg.spriteMG.setOrigin(mg.spriteMG.getLocalBounds().width / 2, mg.spriteMG.getLocalBounds().height / 2);

        spriteVisiblemg = true;
    }
    if (distanceviertwee < 100.0f)
    {
        float angleviertwee = atan2(dyviertwee, dxviertwee) * 90 / M_PI;
        textureManager.spriteshootervier.setRotation(angleviertwee + 90);
        textureManager.spriteshootervier.setOrigin(textureManager.spriteshootervier.getLocalBounds().width / 2, textureManager.spriteshootervier.getLocalBounds().height / 2);

        mg.spriteMG.setRotation(angleviertwee + 90); //werkt
        mg.spriteMG.setOrigin(mg.spriteMG.getLocalBounds().width / 2, mg.spriteMG.getLocalBounds().height / 2);

        spriteVisiblemg = true;
    }
    if (distancevierdrie < 100.0f)
    {
        float anglevierdrie = atan2(dyvierdrie, dxvierdrie) * 90 / M_PI;
        textureManager.spriteshootervier.setRotation(anglevierdrie + 90);
        textureManager.spriteshootervier.setOrigin(textureManager.spriteshootervier.getLocalBounds().width / 2, textureManager.spriteshootervier.getLocalBounds().height / 2);

        mg.spriteMG.setRotation(anglevierdrie + 90); //werkt
        mg.spriteMG.setOrigin(mg.spriteMG.getLocalBounds().width / 2, mg.spriteMG.getLocalBounds().height / 2);

        spriteVisiblemg = true;
    }
    else if (distancedrie > 150.0)
    {
        textureManager.spriteshooterdrie.setRotation(180);
        spriteVisiblelaser = false;
    }
    else if (distancedrieeen > 150.0)
    {
        textureManager.spriteshooterdrie.setRotation(180);
        spriteVisiblelasereen = false;
    }
    else if (distancedrietwee > 150.0)
    {
        textureManager.spriteshooterdrie.setRotation(180);
        spriteVisiblelasertwee = false;
    }
    else if (distancedriedrie > 150.0)
    {
        textureManager.spriteshooterdrie.setRotation(180);
        spriteVisiblelaserdrie = false;
    }

    else if (distanceeen > 300.0f)
    {
        textureManager.spriteshootereen.setRotation(180);
        spriteVisiblecanon = false;
    }
    else if (distancevier > 50.0f)
    {
        textureManager.spriteshootervier.setRotation(180);
        spriteVisiblemg = false;
    }
    else
    {
        textureManager.spriteshooterdrie.setRotation(180);
        textureManager.spriteshootereen.setRotation(180);
        textureManager.spriteshootervier.setRotation(180);
    }

    sf::Vector2f fixedPositiondrie = textureManager.spriteshooterdrie.getPosition();
    textureManager.spriteshooterdrie.setPosition(fixedPositiondrie);

    sf::Vector2f fixedPositioneen = textureManager.spriteshootereen.getPosition();
    textureManager.spriteshootereen.setPosition(fixedPositioneen);

    sf::Vector2f fixedPositionvier = textureManager.spriteshootervier.getPosition();
    textureManager.spriteshootervier.setPosition(fixedPositionvier);
}
}
*/