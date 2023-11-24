#include "Game.h"
#include "Laser.h"
#include "Canon.h"
#include "MG.h"
#include "Weapon.h"
#include "ShooterUpdaterdrie.h"
#include "HandleIntersectionAndDamage.h"
#include "drawSpriteIfVisible.h"
#include "Data.h"
#include <iostream>

#define M_PI 3.14159265358979323846

using namespace std;

namespace Towerdefense
{
    Game::Game()
        : healthBar_een(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50), //parameterized constructor
        healthBar_twee(sf::Vector2f(800, 400), sf::Vector2f(70, 10), 70), //parameterized constructor
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
        weapons.push_back(std::make_unique<Canon>(sf::Vector2f(150, 180)));
    }

    void Game::updateShooterRotation() {

        sf::Vector2f laserPosition = laser.spritelaser.getPosition();
        sf::Vector2f MGPosition = mg.spriteMG.getPosition();
        sf::Vector2f arrowPosition = canon.spritecanonred.getPosition();

        sf::Vector2f shooterdriePosition = textureManager.spriteshooterdrie.getPosition();
        sf::Vector2f shootereenPosition = textureManager.spriteshootereen.getPosition();
        sf::Vector2f shootervierPosition = textureManager.spriteshootervier.getPosition();

        sf::Vector2f robotPositiontraag = traag.spriterobottwee.getPosition();
        sf::Vector2f robotPositionsnel = snel.spriterobottwee.getPosition();
        sf::Vector2f robotPositionsnelxtraagy = snelxtraagy.spriterobottwee.getPosition();
        sf::Vector2f robotPositiontraagxsnely = traagxsnely.spriterobottwee.getPosition();

        //////////////////////////////////////////////////////////
        float dxeen = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraag, shootereenPosition).x;
        float dyeen = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraag, shootereenPosition).y;

        float dxdrie = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraag, shooterdriePosition).x;
        float dydrie = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraag, shooterdriePosition).y;

        float dxvier = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraag, shootervierPosition).x;
        float dyvier = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraag, shootervierPosition).y;
        //////////////////////////////////////////////////////////
        float dxdrieeen = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnel, shootereenPosition).x;
        float dydrieeen = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnel, shootereenPosition).y;

        float dxeeneen = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnel, shooterdriePosition).x;
        float dyeeneen = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnel, shooterdriePosition).y;

        float dxviereen = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnel, shootervierPosition).x;
        float dyviereen = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnel, shootervierPosition).y;
        //////////////////////////////////////////////////////////
        float dxdrietwee = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnelxtraagy, shootereenPosition).x;
        float dydrietwee = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnelxtraagy, shootereenPosition).y;

        float dxeentwee = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnelxtraagy, shooterdriePosition).x;
        float dyeentwee = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnelxtraagy, shooterdriePosition).y;

        float dxviertwee = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnelxtraagy, shootervierPosition).x;
        float dyviertwee = ShooterPositionCalculator::calculateShooterPosition(robotPositionsnelxtraagy, shootervierPosition).y;
        //////////////////////////////////////////////////////////
        float dxdriedrie = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraagxsnely, shootereenPosition).x;
        float dydriedrie = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraagxsnely, shootereenPosition).y;

        float dxeendrie = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraagxsnely, shooterdriePosition).x;
        float dyeendrie = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraagxsnely, shooterdriePosition).y;

        float dxvierdrie = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraagxsnely, shootervierPosition).x;
        float dyvierdrie = ShooterPositionCalculator::calculateShooterPosition(robotPositiontraagxsnely, shootervierPosition).y;
        //////////////////////////////////////////////////////////
        float distanceeen = ShooterPositionCalculator::calculateDistance(robotPositiontraag, shootereenPosition);
        float distancedrie = ShooterPositionCalculator::calculateDistance(robotPositiontraag, shooterdriePosition);
        float distancevier = ShooterPositionCalculator::calculateDistance(robotPositiontraag, shootervierPosition);

        float distanceeeneen = ShooterPositionCalculator::calculateDistance(robotPositionsnel, shootereenPosition);
        float distancedrieeen = ShooterPositionCalculator::calculateDistance(robotPositionsnel, shooterdriePosition);
        float distanceviereen = ShooterPositionCalculator::calculateDistance(robotPositionsnel, shootervierPosition);

        float distanceeentwee = ShooterPositionCalculator::calculateDistance(robotPositionsnelxtraagy, shootereenPosition);
        float distancedrietwee = ShooterPositionCalculator::calculateDistance(robotPositionsnelxtraagy, shooterdriePosition);
        float distanceviertwee = ShooterPositionCalculator::calculateDistance(robotPositionsnelxtraagy, shootervierPosition);

        float distanceeendrie = ShooterPositionCalculator::calculateDistance(robotPositiontraagxsnely, shootereenPosition);
        float distancedriedrie = ShooterPositionCalculator::calculateDistance(robotPositiontraagxsnely, shooterdriePosition);
        float distancevierdrie = ShooterPositionCalculator::calculateDistance(robotPositiontraagxsnely, shootervierPosition);

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

    void Game::useWeapon(Weapon & weapon, sf::Vector2f shooterPosition)
    {
        weapon.fire(shooterPosition);
    }

    void Game::run(sf::RenderWindow & window) {
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

                if (spriteVisibleC)
                {
                    window.draw(textureManager.spritepaper);
                    window.draw(textureManager.spritevbCannon);
                    window.draw(textureManager.spritevbCannon2);
                    window.draw(textureManager.spritevbCannon3);

                    window.draw(textureManager.spritevbMG);
                    window.draw(textureManager.spritevbMG2);
                    window.draw(textureManager.spritevbMG3);

                    window.draw(textureManager.spritevbMissile_Launcher);
                    window.draw(textureManager.spritevbMissile_Launcher2);
                    window.draw(textureManager.spritevbMissile_Launcher3);
                }
                else

                {
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

                }
            }

            window.display();
        }
    }

}