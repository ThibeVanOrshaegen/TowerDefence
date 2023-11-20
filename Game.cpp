#include "Game.h"

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
    mg(sf::Vector2f(65, 340)) {
}

void Game::updateShooterRotation() {
    sf::Vector2f shooterdriePosition = textureManager.spriteshooterdrie.getPosition();
    sf::Vector2f shootereenPosition = textureManager.spriteshootereen.getPosition();
    sf::Vector2f shootervierPosition = textureManager.spriteshootervier.getPosition();

    sf::Vector2f laserPosition = laser.spritelaser.getPosition();
    sf::Vector2f MGPosition = mg.spriteMG.getPosition();
    sf::Vector2f arrowPosition = canon.arrow.getPosition();

    sf::Vector2f robotPosition = traag.spriterobottwee.getPosition();

    float dxdrie = robotPosition.x - shooterdriePosition.x;
    float dydrie = robotPosition.y - shooterdriePosition.y;

    float dxeen = robotPosition.x - shootereenPosition.x;
    float dyeen = robotPosition.y - shootereenPosition.y;

    float dxvier = robotPosition.x - shootervierPosition.x;
    float dyvier = robotPosition.y - shootervierPosition.y;



    float distancedrie = std::sqrt(dxdrie * dxdrie + dydrie * dydrie);
    float distanceeen = std::sqrt(dxeen * dxeen + dyeen * dyeen);
    float distancevier = std::sqrt(dxvier * dxvier + dyvier * dyvier);

    if (distancedrie < 150.0f)
    {
        float angledrie = atan2(dydrie, dxdrie) * 180 / M_PI;
        textureManager.spriteshooterdrie.setRotation(angledrie + 90);
        textureManager.spriteshooterdrie.setOrigin(textureManager.spriteshooterdrie.getLocalBounds().width / 2, textureManager.spriteshooterdrie.getLocalBounds().height / 2);

        laser.spritelaser.setRotation(angledrie + 90); //werkt
        laser.spritelaser.setOrigin(laser.spritelaser.getLocalBounds().width / 2, laser.spritelaser.getLocalBounds().height / 2); // Instelling van de oorsprong

        spriteVisiblelaser = true;

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

    if (distancevier < 100.0f)
    {
        float anglevier = atan2(dyvier, dxvier) * 90 / M_PI;
        textureManager.spriteshootervier.setRotation(anglevier + 90);
        textureManager.spriteshootervier.setOrigin(textureManager.spriteshootervier.getLocalBounds().width / 2, textureManager.spriteshootervier.getLocalBounds().height / 2);

        mg.spriteMG.setRotation(anglevier + 90); //werkt
        mg.spriteMG.setOrigin(mg.spriteMG.getLocalBounds().width / 2, mg.spriteMG.getLocalBounds().height / 2);

        spriteVisiblemg = true;

    }
    else if (distancedrie > 150.0)
    {
        textureManager.spriteshooterdrie.setRotation(180);
        spriteVisiblelaser = false;
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

void Game::useWeapon(Weapon& weapon, sf::Vector2f shooterPosition) {
    weapon.fire(shooterPosition);
}

void Game::run(sf::RenderWindow& window) {
    window.setFramerateLimit(60);

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

            if (spriteVisiblelaser)
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

            if (canon.arrow.getGlobalBounds().intersects(traag.spriterobottwee.getGlobalBounds()))
            {
                redhealthBar_twee.applyDamage();
            }

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
