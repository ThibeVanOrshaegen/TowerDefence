#include "Game.h"
#include "Laser.h"
#include "Canon.h"
#include "MG.h"
#include "Weapon.h"

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
    mg(sf::Vector2f(65, 340)),
    enemyManager(laser, canon, mg)

{
    weapons.push_back(std::make_unique<Canon>(sf::Vector2f(100, 100)));
}

void Game::updateShooterRotation() {
    sf::Vector2f shooterdriePosition = textureManager.spriteshooterdrie.getPosition();
    sf::Vector2f shootereenPosition = textureManager.spriteshootereen.getPosition();
    sf::Vector2f shootervierPosition = textureManager.spriteshootervier.getPosition();

    sf::Vector2f laserPosition = laser.spritelaser.getPosition();
    sf::Vector2f MGPosition = mg.spriteMG.getPosition();
    sf::Vector2f arrowPosition = canon.arrow.getPosition();

    sf::Vector2f robotPosition = traag.spriterobottwee.getPosition();
    sf::Vector2f robotPositionsnel = snel.spriterobottwee.getPosition();
    sf::Vector2f robotPositionsnelxtraagy = snelxtraagy.spriterobottwee.getPosition();
    sf::Vector2f robotPositiontraagxsnely = traagxsnely.spriterobottwee.getPosition();

    //////////////////////////////////////////////////////////
    float dxeen = robotPosition.x - shootereenPosition.x;
    float dyeen = robotPosition.y - shootereenPosition.y;

    float dxdrie = robotPosition.x - shooterdriePosition.x;
    float dydrie = robotPosition.y - shooterdriePosition.y;

    float dxvier = robotPosition.x - shootervierPosition.x;
    float dyvier = robotPosition.y - shootervierPosition.y;
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

    if (distancedrie < 150.0f)
    {
        float angledrie = atan2(dydrie, dxdrie) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledrie + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        laser.spritelaser.setRotation(angledrie + 90); //werkt
        laser.spritelaser.setOrigin(laser.spritelaser.getLocalBounds().width / 2, laser.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelasereen = true;
    }
    if (distancedrieeen < 150.0f)
    {
        float angledrieeen = atan2(dydrieeen, dxdrieeen) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledrieeen + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        laser.spritelaser.setRotation(angledrieeen + 90); //werkt
        laser.spritelaser.setOrigin(laser.spritelaser.getLocalBounds().width / 2, laser.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelasereen = true;
    }
    if (distancedrietwee < 150.0f)
    {
        float angledrietwee = atan2(dydrietwee, dxdrietwee) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledrietwee + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        laser.spritelaser.setRotation(angledrietwee + 90); //werkt
        laser.spritelaser.setOrigin(laser.spritelaser.getLocalBounds().width / 2, laser.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelasertwee = true;
    }
    if (distancedriedrie < 150.0f)
    {
        float angledriedrie = atan2(dydriedrie, dxdriedrie) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledriedrie + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        laser.spritelaser.setRotation(angledriedrie + 90); //werkt
        laser.spritelaser.setOrigin(laser.spritelaser.getLocalBounds().width / 2, laser.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelasereen = true;
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
        float anglevierdrie= atan2(dyvierdrie, dxvierdrie) * 90 / M_PI;
        textureManager.spriteshootervier.setRotation(anglevierdrie + 90);
        textureManager.spriteshootervier.setOrigin(textureManager.spriteshootervier.getLocalBounds().width / 2, textureManager.spriteshootervier.getLocalBounds().height / 2);

        mg.spriteMG.setRotation(anglevierdrie + 90); //werkt
        mg.spriteMG.setOrigin(mg.spriteMG.getLocalBounds().width / 2, mg.spriteMG.getLocalBounds().height / 2);

        spriteVisiblemg = true;
    }
    else if (distancedrie > 150.0)
    {
        textureManager.spriteshooterdrie.setRotation(180);
        spriteVisiblelasereen = false;
        spriteVisiblelasertwee = false;
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

// Inside the Game.cpp file
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

            window.draw(snel.spriterobottwee);
            window.draw(traag.spriterobottwee);
            window.draw(snelxtraagy.spriterobottwee);
            window.draw(traagxsnely.spriterobottwee);

            updateShooterRotation();

            snel.update();
            traag.update();
            snelxtraagy.update();
            traagxsnely.update();


            useWeapon(laser, textureManager.spriteshooterdrie.getPosition());
            if (spriteVisiblelasereen || spriteVisiblelasertwee)
                window.draw(laser.spritelaser);

 
            useWeapon(mg, textureManager.spriteshootervier.getPosition());
            if (spriteVisiblemg)
                window.draw(mg.spriteMG);

            useWeapon(canon, textureManager.spriteshootereen.getPosition());
            if (spriteVisiblecanon)
                window.draw(canon.arrow);

            healthBar_een.updatePosition(sf::Vector2f(snel.spriterobottwee.getPosition()));
            healthBar_twee.updatePosition(sf::Vector2f(traag.spriterobottwee.getPosition()));
            healthBar_drie.updatePosition(sf::Vector2f(snelxtraagy.spriterobottwee.getPosition()));
            healthBar_vier.updatePosition(sf::Vector2f(traagxsnely.spriterobottwee.getPosition()));

            redhealthBar_een.updatePosition(sf::Vector2f(snel.spriterobottwee.getPosition()));
            redhealthBar_twee.updatePosition(sf::Vector2f(traag.spriterobottwee.getPosition()));
            redhealthBar_drie.updatePosition(sf::Vector2f(snelxtraagy.spriterobottwee.getPosition()));
            redhealthBar_vier.updatePosition(sf::Vector2f(traagxsnely.spriterobottwee.getPosition()));

            if (laser.spritelaser.getGlobalBounds().intersects(traag.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_een.applyDamage();
            }
            if (laser.spritelaser.getGlobalBounds().intersects(snel.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_twee.applyDamage();
            }
            if (laser.spritelaser.getGlobalBounds().intersects(snelxtraagy.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_drie.applyDamage();
            }
            if (laser.spritelaser.getGlobalBounds().intersects(traagxsnely.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_vier.applyDamage();
            }
            if (mg.spriteMG.getGlobalBounds().intersects(traag.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_een.applyDamage();
            }
            if (mg.spriteMG.getGlobalBounds().intersects(snel.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_twee.applyDamage();
            }
            if (mg.spriteMG.getGlobalBounds().intersects(snelxtraagy.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_drie.applyDamage();
            }
            if (mg.spriteMG.getGlobalBounds().intersects(traagxsnely.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_vier.applyDamage();
            }
            if (canon.arrow.getGlobalBounds().intersects(traag.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_een.applyDamage();
            }
            if (canon.arrow.getGlobalBounds().intersects(snel.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_twee.applyDamage();
            }
            if (canon.arrow.getGlobalBounds().intersects(snelxtraagy.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_drie.applyDamage();
            }
            if (canon.arrow.getGlobalBounds().intersects(traagxsnely.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_vier.applyDamage();
            }

            //if currenthealt <0 then richt op volgend targent, if currenthealt <0 then spriterobot twee verdwijnen kijk naar vorige codes

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


