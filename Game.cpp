#include "Game.h"
#include "Laser.h"
#include "Canon.h"
#include "MG.h"
#include "Weapon.h"
#include "ShooterUpdaterdrie.h"
#include "HandleIntersectionAndDamage.h"
#include "drawSpriteIfVisible.h"

#define M_PI 3.14159265358979323846

Game::Game()
    : healthBar_een(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50),
    healthBar_twee(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70),
    healthBar_drie(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50),
    healthBar_vier(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70),

    redhealthBar_een(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50),
    redhealthBar_twee(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70),
    redhealthBar_drie(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50),
    redhealthBar_vier(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70),

    snel(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 30, 9.0f, 9.0f),
    traag(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 70, 2.5f, 2.5f),
    snelxtraagy(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 30, 5.0f, 2.5f),
    traagxsnely(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 70, 2.5f, 5.0f),

    canon(sf::Vector2f(150, 180)),
    laser(sf::Vector2f(610, 400)),
    mg(sf::Vector2f(65, 340))
{
    weapons.push_back(std::make_unique<Canon>(sf::Vector2f(100, 100)));
}

void Game::updateShooterRotation() {
    sf::Vector2f shooterdriePosition = textureManager.spriteshooterdrie.getPosition();
    sf::Vector2f shootereenPosition = textureManager.spriteshootereen.getPosition();
    sf::Vector2f shootervierPosition = textureManager.spriteshootervier.getPosition();

    sf::Vector2f laserPosition = laser.spritelaser.getPosition();
    sf::Vector2f MGPosition = mg.spriteMG.getPosition();
    sf::Vector2f arrowPosition = canon.spritecanonred.getPosition();

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

    ShooterUpdaterdrie::updateRotation(textureManager.spriteshooterdrie, laser.spritelaser, distancedrie, dydrie, dxdrie);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshooterdrie, laser.spritelaser, distancedrieeen, dydrieeen, dxdrieeen);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshooterdrie, laser.spritelaser, distancedrietwee, dydrietwee, dxdrietwee);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshooterdrie, laser.spritelaser, distancedriedrie, dydriedrie, dxdriedrie);

    ShooterUpdaterdrie::updateRotation(textureManager.spriteshootervier, mg.spriteMG, distancevier, dyvier, dxvier);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshootervier, mg.spriteMG, distanceviereen, dyviereen, dxviereen);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshootervier, mg.spriteMG, distanceviertwee, dyviertwee, dxviertwee);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshootervier, mg.spriteMG, distancevierdrie, dyvierdrie, dxvierdrie);

    ShooterUpdaterdrie::updateRotation(textureManager.spriteshootereen, canon.spritecanonred, distanceeen, dyeen, dxeen);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshootereen, canon.spritecanonred, distanceeeneen, dyeeneen, dxeeneen);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshootereen, canon.spritecanonred, distanceeentwee, dyeentwee, dxeentwee);
    ShooterUpdaterdrie::updateRotation(textureManager.spriteshootereen, canon.spritecanonred, distanceeendrie, dyeendrie, dxeendrie);

    sf::Vector2f fixedPositiondrie = textureManager.spriteshooterdrie.getPosition();
    textureManager.spriteshooterdrie.setPosition(fixedPositiondrie);

    sf::Vector2f fixedPositioneen = textureManager.spriteshootereen.getPosition();
    textureManager.spriteshootereen.setPosition(fixedPositioneen);

    sf::Vector2f fixedPositionvier = textureManager.spriteshootervier.getPosition();
    textureManager.spriteshootervier.setPosition(fixedPositionvier);
}

void Game::useWeapon(Weapon& weapon, sf::Vector2f shooterPosition)
{
    weapon.fire(shooterPosition);
}

void Game::run(sf::RenderWindow& window) {
    window.setFramerateLimit(60);
    sf::Vector2f shooterPosition;

    bool isRKeyPressed = false;
    bool isPKeyPressed = false;
    bool isCKeyPressed = false;

    redhealthBar_een.bar.setFillColor(sf::Color::Green);
    redhealthBar_twee.bar.setFillColor(sf::Color::Green);
    redhealthBar_drie.bar.setFillColor(sf::Color::Green);
    redhealthBar_vier.bar.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                isPKeyPressed = true;
                isRKeyPressed = false;
                isCKeyPressed = false;
                spriteVisibleP = true;
                spriteVisibleC = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                isRKeyPressed = true;
                isPKeyPressed = false;
                isCKeyPressed = false;
                spriteVisibleP = false;
                spriteVisibleC = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                isCKeyPressed = true;
                isRKeyPressed = false;
                isPKeyPressed = false;
                spriteVisibleP = false;
                spriteVisibleC = true;
            }
            else
            {
                isRKeyPressed = false;
                isPKeyPressed = false;
                isCKeyPressed = false;
            }
            for (auto& weapon : weapons) {
                weapon->update();

            }

        }


        // Render
        window.clear();

        window.draw(textureManager.spriteAchtergrond);
        window.draw(textureManager.spritetowerdefensetext);
        window.draw(textureManager.spritetitle);
        window.draw(textureManager.spriteplay);
        window.draw(textureManager.spriteoption);

        if (spriteVisibleP)
        {

            window.draw(*(textureManager.sprite));
            window.draw(textureManager.spritecastle);


            /* window.draw(textureManager.spritepaper);
             window.draw(textureManager.spritevbCannon);
             window.draw(textureManager.spritevbCannon2);
             window.draw(textureManager.spritevbCannon3);

             window.draw(textureManager.spritevbMG);
             window.draw(textureManager.spritevbMG2);
             window.draw(textureManager.spritevbMG3);

             window.draw(textureManager.spritevbMissile_Launcher);
             window.draw(textureManager.spritevbMissile_Launcher2);
             window.draw(textureManager.spritevbMissile_Launcher3);*/

             //if (spriteVisibleC)
             //{
            window.draw(textureManager.spritemudeen);
            window.draw(textureManager.spritemudtwee);
            window.draw(textureManager.spritemuddrie);
            window.draw(textureManager.spritemudvier);
            window.draw(textureManager.spritemudvijf);

            window.draw(textureManager.spriteshootereen);
            window.draw(textureManager.spriteshootertwee);
            window.draw(textureManager.spriteshooterdrie);
            window.draw(textureManager.spriteshootervier);

            window.draw(snel.spriterobottwee);
            window.draw(traag.spriterobottwee);
            window.draw(snelxtraagy.spriterobottwee);
            window.draw(traagxsnely.spriterobottwee);

            window.draw(textureManager.spritemudeen);
            window.draw(textureManager.spritemudtwee);
            window.draw(textureManager.spritemuddrie);
            window.draw(textureManager.spritemudvier);
            window.draw(textureManager.spritemudvijf);
            window.draw(textureManager.spritemudzes);

            window.draw(textureManager.spritetowereen);
            window.draw(textureManager.spritetowertwee);
            window.draw(textureManager.spritetowerdrie);
            window.draw(textureManager.spritetowervier);
            window.draw(textureManager.spritetowervijf);
            window.draw(textureManager.spritetowerzes);

            window.draw(textureManager.spriteshootereen);
            window.draw(textureManager.spriteshootertwee);
            window.draw(textureManager.spriteshooterdrie);
            window.draw(textureManager.spriteshootervier);


            updateShooterRotation();

            snel.update();
            traag.update();
            snelxtraagy.update();
            traagxsnely.update();

            useWeapon(laser, textureManager.spriteshooterdrie.getPosition());
            useWeapon(mg, textureManager.spriteshootervier.getPosition());
            useWeapon(canon, textureManager.spriteshootereen.getPosition());
            
            spriteVisiblelaser = true;
            drawSpriteIfVisible::drawSpriteVisible(window, laser.spritelaser, spriteVisiblelaser);
            spriteVisiblemg = true;
            drawSpriteIfVisible::drawSpriteVisible(window, mg.spriteMG, spriteVisiblemg);
            spriteVisiblecanon = true;
            drawSpriteIfVisible::drawSpriteVisible(window, canon.spritecanonred, spriteVisiblecanon);

            HandleIntersectionAndDamage::handleIntersectionsAndDamage(laser.spritelaser, snel.spriterobottwee, redhealthBar_een);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(laser.spritelaser, traag.spriterobottwee, redhealthBar_twee);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(laser.spritelaser, snelxtraagy.spriterobottwee, redhealthBar_drie);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(laser.spritelaser, traagxsnely.spriterobottwee, redhealthBar_vier);

            HandleIntersectionAndDamage::handleIntersectionsAndDamage(mg.spriteMG, snel.spriterobottwee, redhealthBar_een);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(mg.spriteMG, traag.spriterobottwee, redhealthBar_twee);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(mg.spriteMG, snelxtraagy.spriterobottwee, redhealthBar_drie);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(mg.spriteMG, traagxsnely.spriterobottwee, redhealthBar_vier);

            HandleIntersectionAndDamage::handleIntersectionsAndDamage(canon.spritecanonred, snel.spriterobottwee, redhealthBar_een);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(canon.spritecanonred, traag.spriterobottwee, redhealthBar_twee);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(canon.spritecanonred, snelxtraagy.spriterobottwee, redhealthBar_drie);
            HandleIntersectionAndDamage::handleIntersectionsAndDamage(canon.spritecanonred, traagxsnely.spriterobottwee, redhealthBar_vier);

            healthBar_een.updatePosition(sf::Vector2f(snel.spriterobottwee.getPosition()));
            healthBar_twee.updatePosition(sf::Vector2f(traag.spriterobottwee.getPosition()));
            healthBar_drie.updatePosition(sf::Vector2f(snelxtraagy.spriterobottwee.getPosition()));
            healthBar_vier.updatePosition(sf::Vector2f(traagxsnely.spriterobottwee.getPosition()));

            redhealthBar_een.updatePosition(sf::Vector2f(snel.spriterobottwee.getPosition()));
            redhealthBar_twee.updatePosition(sf::Vector2f(traag.spriterobottwee.getPosition()));
            redhealthBar_drie.updatePosition(sf::Vector2f(snelxtraagy.spriterobottwee.getPosition()));
            redhealthBar_vier.updatePosition(sf::Vector2f(traagxsnely.spriterobottwee.getPosition()));
          
            window.draw(healthBar_een.bar);
            window.draw(healthBar_twee.bar);
            window.draw(healthBar_drie.bar);
            window.draw(healthBar_vier.bar);

            window.draw(redhealthBar_een.bar);
            window.draw(redhealthBar_twee.bar);
            window.draw(redhealthBar_drie.bar);
            window.draw(redhealthBar_vier.bar);

            //}
        }

        window.display();
    }
}

