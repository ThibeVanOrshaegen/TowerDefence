#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Game.h"
#include "CurrentMoney.h"
#include "Enemy.h"
#include "HandleIntersectionAndDamage.h"
#include "drawSpriteIfVisible.h"
#include "drawSpriteIfVisibleshoot.h"
#include "Updaterotation.h"
#include "mouseEventHandler.h"
#include "Laser.h"
#include <thread>
#include <cmath>

#define M_PI 3.14159265358979323846

namespace Towerdefense
{
    void Game::init() {
        redhealthBar_een_copy.bar.setFillColor(sf::Color::Green);
        redhealthBar_twee_copy.bar.setFillColor(sf::Color::Green);

    }

    Game::Game() : healthBar_een(sf::Vector2f(0, 410), sf::Vector2f(70, 10), 50),
        redhealthBar_een_copy(healthBar_een),
        healthBar_twee(sf::Vector2f(0, 410), sf::Vector2f(70, 10), 60),
        redhealthBar_twee_copy(healthBar_een),
        currentmoneyklein(new CurrentMoney(100)), //don't provide this value, the default value of 10 will be used.
        snel(new Enemy(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 10, 3.0f, 3.0f)),
        traag(new Enemy(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 10, 1.0f, 1.0f)),

        canonkogel(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogeltwee(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogeldrie(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogelvier(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogelvijf(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogelzes(new Canonshooting(sf::Vector2f(150, 180))),

        canonplaats(new Canon(sf::Vector2f(500, 260))),
        canonplaatstwee(new Canon(sf::Vector2f(500, 260))),
        canonplaatsdrie(new Canon(sf::Vector2f(500, 260))),
        canonplaatsvier(new Canon(sf::Vector2f(500, 260))),
        canonplaatsvijf(new Canon(sf::Vector2f(500, 260))),
        canonplaatszes(new Canon(sf::Vector2f(500, 260))),

        laserkogel(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogeltwee(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogeldrie(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogelvier(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogelvijf(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogelzes(new Lasershooting(sf::Vector2f(150, 180))),

        laserplaats(new Laser(sf::Vector2f(500, 260))),
        laserplaatstwee(new Laser(sf::Vector2f(500, 260))),
        laserplaatsdrie(new Laser(sf::Vector2f(500, 260))),
        laserplaatsvier(new Laser(sf::Vector2f(500, 260))),
        laserplaatsvijf(new Laser(sf::Vector2f(500, 260))),
        laserplaatszes(new Laser(sf::Vector2f(500, 260))),

        mouseEventHandler(textureManager) {
        init();
    }
    Game::~Game()
    {
        delete snel;
        delete traag;
        delete currentmoneyklein;
    }

    bool Towerdefense::Game::isPKeyPressed = false;
    bool Towerdefense::Game::spriteVisibleP = false;
    bool Towerdefense::Game::spriteTruePlay = false;
    bool Towerdefense::Game::spriteTruePause = false;
    bool Towerdefense::Game::spriteTrueOpenOption = false;
    bool Towerdefense::Game::spriteAmmorotation = false;

    bool Towerdefense::Game::spriteSelleen = false;
    bool Towerdefense::Game::spriteBuyblue = false;
    bool Towerdefense::Game::spriteBuyRed = false;

    bool Towerdefense::Game::spriteSelltwee = false;
    bool Towerdefense::Game::spriteBuybluetwee = false;
    bool Towerdefense::Game::spriteBuyRedtwee = false;

    bool Towerdefense::Game::spriteSelldrie = false;
    bool Towerdefense::Game::spriteBuybluedrie = false;
    bool Towerdefense::Game::spriteBuyReddrie = false;

    bool Towerdefense::Game::spriteSellvier = false;
    bool Towerdefense::Game::spriteBuybluevier = false;
    bool Towerdefense::Game::spriteBuyRedvier = false;

    bool Towerdefense::Game::spriteSellvijf = false;
    bool Towerdefense::Game::spriteBuybluevijf = false;
    bool Towerdefense::Game::spriteBuyRedvijf = false;

    bool Towerdefense::Game::spriteSellzes = false;
    bool Towerdefense::Game::spriteBuybluezes = false;
    bool Towerdefense::Game::spriteBuyRedzes = false;

    bool Towerdefense::Game::PlaceOneEmpty = true;
    bool Towerdefense::Game::PlaceTwoEmpty = true;
    bool Towerdefense::Game::PlaceThreeEmpty = true;
    bool Towerdefense::Game::PlaceFourEmpty = true;
    bool Towerdefense::Game::PlaceFiveEmpty = true;
    bool Towerdefense::Game::PlaceSixEmpty = true;


    void Game::backgroundTask(Game& game)
    {
        while (game.isRunning())
        {

            std::this_thread::sleep_for(std::chrono::milliseconds(16));

            game.updatehealthBarGame();
            game.updateHandleIntersectionAndDamage();
            game.updateRotationGame();

        }
    }

    void Game::updateEnemies() {

        std::thread snelUpdateThread(&Enemy::updateMoveHealth, snel);
        std::thread traagUpdateThread(&Enemy::updateMoveHealth, traag);

        snelUpdateThread.join();
        traagUpdateThread.join();
    }

    void Game::updatehealthBarGame() {

        healthBar_een.updatePositionHealth(sf::Vector2f(snel->spriteEnemy.getPosition()));
        redhealthBar_een_copy.updatePositionHealth(sf::Vector2f(snel->spriteEnemy.getPosition()));

        healthBar_twee.updatePositionHealth(sf::Vector2f(traag->spriteEnemy.getPosition()));
        redhealthBar_twee_copy.updatePositionHealth(sf::Vector2f(traag->spriteEnemy.getPosition()));
    }

    void Game::updateRotationGame() {
        updaterotation.updateShooterRotationCanon(canonplaats, snel,0);
        updaterotation.updateShooterRotationCanon(canonplaatstwee, snel, 0);
        updaterotation.updateShooterRotationCanon(canonplaatsdrie, snel, 0);
        updaterotation.updateShooterRotationCanon(canonplaatsvier, snel, 0);
        updaterotation.updateShooterRotationCanon(canonplaatsvijf, snel, 0);
        updaterotation.updateShooterRotationCanon(canonplaatszes, snel, 0);

        updaterotation.updateShooterRotationCanonkogel(canonkogel, snel, 0);
        updaterotation.updateShooterRotationCanonkogel(canonkogeltwee, snel, 0);
        updaterotation.updateShooterRotationCanonkogel(canonkogeldrie, snel, 0);
        updaterotation.updateShooterRotationCanonkogel(canonkogelvier, snel, 0);
        updaterotation.updateShooterRotationCanonkogel(canonkogelvijf, snel, 0);
        updaterotation.updateShooterRotationCanonkogel(canonkogelzes, snel, 0);

        updaterotation.updateShooterRotationLaser(laserplaats, traag, 0);
        updaterotation.updateShooterRotationLaser(laserplaatstwee, traag, 0);
        updaterotation.updateShooterRotationLaser(laserplaatsdrie, traag, 0);
        updaterotation.updateShooterRotationLaser(laserplaatsvier, traag, 0);
        updaterotation.updateShooterRotationLaser(laserplaatsvijf, traag, 0);
        updaterotation.updateShooterRotationLaser(laserplaatszes, traag, 0);
    }

    void Game::useWeapon(Weapon& weapon, sf::Vector2f shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four)
    {
        weapon.fire(shooterPosition, limit_one,limit_two,limit_three,limit_four);
    }

    void Game::updateHandleIntersectionAndDamage() {//canonkogeltwee,...

        HandleIntersectionAndDamage::handleIntersectionsAndDamage(canonkogel->spriteCanonKogeltwee, snel->spriteEnemy, redhealthBar_een_copy); //handle.. is 4
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(canonkogeltwee->spriteCanonKogeltwee, snel->spriteEnemy, redhealthBar_een_copy); //handle.. is 4
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(canonkogeldrie->spriteCanonKogeltwee, snel->spriteEnemy, redhealthBar_een_copy); //handle.. is 4
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(canonkogelvier->spriteCanonKogeltwee, snel->spriteEnemy, redhealthBar_twee_copy);
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(canonkogelvijf->spriteCanonKogeltwee, snel->spriteEnemy, redhealthBar_een_copy); //handle.. is 4
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(canonkogelzes->spriteCanonKogeltwee, snel->spriteEnemy, redhealthBar_een_copy); //handle.. is 4

        HandleIntersectionAndDamage::handleIntersectionsAndDamage(laserkogel->spriteLaserKogeltwee, traag->spriteEnemy, redhealthBar_twee_copy); //redhealthBar_een hoort bij enemey_one
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(laserkogeltwee->spriteLaserKogeltwee, traag->spriteEnemy, redhealthBar_twee_copy); //redhealthBar_een hoort bij enemey_one
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(laserkogeldrie->spriteLaserKogeltwee, traag->spriteEnemy, redhealthBar_twee_copy); //redhealthBar_een hoort bij enemey_one
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(laserkogelvier->spriteLaserKogeltwee, traag->spriteEnemy, redhealthBar_twee_copy); //redhealthBar_een hoort bij enemey_one
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(laserkogelvijf->spriteLaserKogeltwee, traag->spriteEnemy, redhealthBar_twee_copy);
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(laserkogelzes->spriteLaserKogeltwee, traag->spriteEnemy, redhealthBar_twee_copy); //redhealthBar_een hoort bij enemey_one
    }

    template <typename T>
    void swap(T& x, T& y) {
        T temp;
        temp = x;
        x = y;
        y = temp;

        return;
    }

    sf::Clock timer;

    void Game::run(sf::RenderWindow& window) {

        int moneyIncrement = 1;
        int moneyDecrement = 2;
        int nextmoneyIncrement;

        sf::Vector2f shooterPosition;
        sf::Vector2f shooterPositiontwee;
        sf::Vector2f shooterPositiondrie;
        sf::Vector2f shooterPositionvier;
        sf::Vector2f shooterPositionvijf;
        sf::Vector2f shooterPositionzes;

        sf::Vector2f direction;

        Canon canon(shooterPosition);
        Laser laser(shooterPosition);

        shooterPosition = sf::Vector2f(328, 294);
        shooterPositiontwee = sf::Vector2f(85, 330);
        shooterPositiondrie = sf::Vector2f(85, 518);
        shooterPositionvier = sf::Vector2f(344, 482);
        shooterPositionvijf = sf::Vector2f(605, 395);
        shooterPositionzes = sf::Vector2f(901, 458);


        running = true;

        std::thread backgroundThread([&]() { backgroundTask(*this); }); //this and lamba


         //handleinteraction

        sf::Clock moneyUpdateTimer; // Timer voor geldupdate
        sf::Clock elapsedTimer;

        while (window.isOpen())
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

            }
            sf::Time elapsed = elapsedTimer.getElapsedTime();

            if (elapsed.asSeconds() >= 3) {
                auto incrementMoney = [this, moneyIncrement]() {
                    if (currentmoneyklein != nullptr)
                    {
                        currentmoneyklein->sum(currentmoneyklein->currentmoney, moneyIncrement);
                    }
                    };
                incrementMoney();

                elapsedTimer.restart(); // Herstart de timer
            }

            auto decrementMoney = [this, moneyDecrement]() {
                if (currentmoneyklein != nullptr)
                {
                    currentmoneyklein->subtract(currentmoneyklein->currentmoney, moneyDecrement);
                }
                };

            if (moneyUpdateTimer.getElapsedTime().asSeconds() >= 3) {
                std::cout << "Current Money: " << currentmoneyklein->currentmoney << std::endl;
                std::cout << "Level 1" << std::endl;
                std::cout << std::endl;
                moneyUpdateTimer.restart(); // Herstart de timer voor de uitvoer
            }

            bool buttonClicked = mouseEventHandler.handleMouseClick(event, window);

            if (mouseEventHandler.getPlay())
            {
                spriteTruePlay = true;
            }
            if (mouseEventHandler.getStop())
            {
                spriteTruePlay = false;
            }
            if (updaterotation.getAmmo())
            {
                spriteAmmorotation = true;
            }
            //--------------------------------------------------------
            if (mouseEventHandler.getSelleen() && !PlaceOneEmpty)
            {
                spriteSelleen = true;
                spriteBuyblue = false;
                spriteBuyRed = false;

                PlaceOneEmpty = true;
                
            }
            if (mouseEventHandler.getBuyBlue() && PlaceOneEmpty && currentmoneyklein->currentmoney >= 2 )
            {
                spriteBuyRed = true;
                PlaceOneEmpty = false;
                decrementMoney();
                
            }
            if (mouseEventHandler.getBuyRed() && PlaceOneEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuyblue = true;
                PlaceOneEmpty = false;
                decrementMoney();
            }
            //--------------------------------------------------------
            if (mouseEventHandler.getSelltwee() && !PlaceTwoEmpty)
            {
                spriteSelltwee = true;
                spriteBuybluetwee = false;
                spriteBuyRedtwee = false;
                PlaceTwoEmpty = true;
            }
            if (mouseEventHandler.getBuyBluetwee() && PlaceTwoEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuyRedtwee = true;
                PlaceTwoEmpty = false;
                decrementMoney();
            }
            if (mouseEventHandler.getBuyRedtwee() && PlaceTwoEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuybluetwee = true;
                PlaceTwoEmpty = false;
                decrementMoney();
            }
            //--------------------------------------------------------
            if (mouseEventHandler.getSelldrie() && !PlaceThreeEmpty)
            {
                spriteSelldrie = true;
                spriteBuybluedrie = false;
                spriteBuyReddrie = false;
                PlaceThreeEmpty = true;
            }
            if (mouseEventHandler.getBuyBluedrie() && PlaceThreeEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuyReddrie = true;
                PlaceThreeEmpty = false;
                decrementMoney();
            }
            if (mouseEventHandler.getBuyReddrie() && PlaceThreeEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuybluedrie = true;
                PlaceThreeEmpty = false;
                decrementMoney();
            }
            //--------------------------------------------------------
            if (mouseEventHandler.getSellvier() && !PlaceFourEmpty)
            {
                spriteSellvier = true;
                spriteBuybluevier = false;
                spriteBuyRedvier = false;
                PlaceFourEmpty = true;
            }
            if (mouseEventHandler.getBuyBluevier() && PlaceFourEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuyRedvier = true;
                PlaceFourEmpty = false;
                decrementMoney();
            }
            if (mouseEventHandler.getBuyRedvier() && PlaceFourEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuybluevier = true;
                PlaceFourEmpty = false;
                decrementMoney();
            }
            //--------------------------------------------------------
            if (mouseEventHandler.getSellvijf() && !PlaceFiveEmpty)
            {
                spriteSellvijf = true;
                spriteBuybluevijf = false;
                spriteBuyRedvijf = false;
                PlaceFiveEmpty = true;
            }
            if (mouseEventHandler.getBuyBluevijf() && PlaceFiveEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuyRedvijf = true;
                PlaceFiveEmpty = false;
                decrementMoney();
            }
            if (mouseEventHandler.getBuyRedvijf() && PlaceFiveEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuybluevijf = true;
                PlaceFiveEmpty = false;
                decrementMoney();
            }
            //--------------------------------------------------------
            if (mouseEventHandler.getSellzes() && !PlaceSixEmpty)
            {
                spriteSellzes = true;
                spriteBuybluezes = false;
                spriteBuyRedzes = false;
                PlaceSixEmpty = true;
                //geen geld voor verkoop
            }
            if (mouseEventHandler.getBuyBluezes() && PlaceSixEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuyRedzes = true;
                PlaceSixEmpty = false;
                decrementMoney();
            }
            if (mouseEventHandler.getBuyRedzes() && PlaceSixEmpty && currentmoneyklein->currentmoney >= 2)
            {
                spriteBuybluezes = true;
                PlaceSixEmpty = false;
                decrementMoney();
            }
            //--------------------------------------------------------
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                isPKeyPressed = true;
                spriteVisibleP = true;
            }
            else
            {
                isPKeyPressed = false;
            }

            window.clear();
            window.setVerticalSyncEnabled(true);

            window.draw(*(textureManager.spriteAchtergrond));
            window.draw(*(textureManager.spritecastle));
            window.draw(*(textureManager.spritetowereen));
            window.draw(*(textureManager.spritetowertwee));
            window.draw(*(textureManager.spritetowerdrie));
            window.draw(*(textureManager.spritetowervier));
            window.draw(*(textureManager.spritetowervijf));
            window.draw(*(textureManager.spritetowerzes));
            window.draw(*(textureManager.spritePlayButton));
            window.draw(*(textureManager.spritePauseButton));
            window.draw(*(textureManager.spriteOptionButton));

            window.draw(*(textureManager.spriteShopeenButton));
            window.draw(*(textureManager.spriteSelleenButton));
            window.draw(*(textureManager.spriteShopeenBlueButton));

            window.draw(*(textureManager.spriteShoptweeButton));
            window.draw(*(textureManager.spriteSelltweeButton));
            window.draw(*(textureManager.spriteShoptweeBlueButton));

            window.draw(*(textureManager.spriteShopdrieButton));
            window.draw(*(textureManager.spriteSelldrieButton));
            window.draw(*(textureManager.spriteShopdrieBlueButton));

            window.draw(*(textureManager.spriteShopvierButton));
            window.draw(*(textureManager.spriteSellvierButton));
            window.draw(*(textureManager.spriteShopvierBlueButton));

            window.draw(*(textureManager.spriteShopvijfButton));
            window.draw(*(textureManager.spriteSellvijfButton));
            window.draw(*(textureManager.spriteShopvijfBlueButton));

            window.draw(*(textureManager.spriteShopzesButton));
            window.draw(*(textureManager.spriteSellzesButton));
            window.draw(*(textureManager.spriteShopzesBlueButton));

            if (spriteBuyblue)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatstwee->spritecanonleveleen, shooterPositiontwee, sf::Vector2f(canon.spritecanonleveleen.getLocalBounds().width / 2, canon.spritecanonleveleen.getLocalBounds().height / 2));
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogeltwee->spriteCanonKogeltwee);

                useWeapon(*canonplaatstwee, textureManager.spritecanonleveleen.getPosition(), 1080, 600, 0, 0);
                useWeapon(*canonkogeltwee, shooterPositiontwee, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);
                
                    if (snel->spriteEnemy.getPosition().x < canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatstwee->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(-1.0f, -1.0f);  // move right
                        canonkogeltwee->update(direction.x, direction.y);
                        canonkogeltwee->fire(shooterPositiontwee,1080,600,0,0);
                    }
                    if (snel->spriteEnemy.getPosition().x < canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatstwee->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(-1.0f, 0.0f);  // move right
                        canonkogeltwee->update(direction.x, direction.y);
                        canonkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
                    }
                    if (snel->spriteEnemy.getPosition().x < canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatstwee->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(-1.0f, 1.0f);  // move right
                        canonkogeltwee->update(direction.x, direction.y);
                        canonkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
                    }
                    if (snel->spriteEnemy.getPosition().x < canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatstwee->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(-1.0f, -1.0f);  // move right
                        canonkogeltwee->update(direction.x, direction.y);
                        canonkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
                    }
                    else if (snel->spriteEnemy.getPosition().x == canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatstwee->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(0.0f, 1.0f);  // move right
                        canonkogeltwee->update(direction.x, direction.y);
                        canonkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
                    }
                    else if (snel->spriteEnemy.getPosition().x > canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatstwee->spritecanonleveleen.getPosition().y)
                    {
                        direction = sf::Vector2f(+1.0f, 1.0f);  // move left
                        canonkogeltwee->update(direction.x, direction.y);
                        canonkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
                    }
                    else if (snel->spriteEnemy.getPosition().x > canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatstwee->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(+1.0f, 0.0f);  // move right
                        canonkogeltwee->update(direction.x, direction.y);
                        canonkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
                    }
                    else if (snel->spriteEnemy.getPosition().x > canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatstwee->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(+1.0f, -1.0f);  // move right
                        canonkogeltwee->update(direction.x, direction.y);
                        canonkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
                }
                
            }
            if (spriteBuyRed)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, laserplaatstwee->spritelaserleveleen, shooterPositiontwee, sf::Vector2f(laser.spritelaserleveleen.getLocalBounds().width / 2, laser.spritelaserleveleen.getLocalBounds().height / 2));
                useWeapon(*laserplaatstwee, textureManager.spritelaserleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogeltwee->spriteLaserKogeltwee);
                useWeapon(*laserkogeltwee, shooterPositiontwee, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);
                laserkogeltwee->updateprobeer();
                laserplaatstwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
                laserkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
            }
            //--------------------------------------------------------
            if (spriteBuybluetwee) //stuur iets naar de terminal
            {
                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatsdrie->spritecanonleveleen, shooterPositiondrie, sf::Vector2f(canon.spritecanonleveleen.getLocalBounds().width / 2, canon.spritecanonleveleen.getLocalBounds().height / 2));
                useWeapon(*canonplaatsdrie, textureManager.spritecanonleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogeldrie->spriteCanonKogeltwee);
                useWeapon(*canonkogeldrie, shooterPositiondrie, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);

                if (snel->spriteEnemy.getPosition().x < canonplaatsdrie->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatsdrie->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, -1.0f);  // move right
                    canonkogeldrie->update(direction.x, direction.y);
                    canonkogeldrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
                }
                if (snel->spriteEnemy.getPosition().x < canonplaatsdrie->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatsdrie->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, 0.0f);  // move right
                    canonkogeldrie->update(direction.x, direction.y);
                    canonkogeldrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
                }
                if (snel->spriteEnemy.getPosition().x < canonplaatsdrie->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsdrie->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, 1.0f);  // move right
                    canonkogeldrie->update(direction.x, direction.y);
                    canonkogeldrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x == canonplaatsdrie->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsdrie->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(0.0f, 1.0f);  // move right
                    canonkogeldrie->update(direction.x, direction.y);
                    canonkogeldrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsdrie->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsdrie->spritecanonleveleen.getPosition().y)
                {
                    direction = sf::Vector2f(+1.0f, 1.0f);  // move left
                    canonkogeldrie->update(direction.x, direction.y);
                    canonkogeldrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsdrie->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatsdrie->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(+1.0f, 0.0f);  // move right
                    canonkogeldrie->update(direction.x, direction.y);
                    canonkogeldrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsdrie->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatsdrie->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(+1.0f, -1.0f);  // move right
                    canonkogeldrie->update(direction.x, direction.y);
                    canonkogeldrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
                }
            }
            if (spriteBuyRedtwee)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, laserplaatsdrie->spritelaserleveleen,shooterPositiondrie, sf::Vector2f(laser.spritelaserleveleen.getLocalBounds().width / 2, laser.spritelaserleveleen.getLocalBounds().height / 2));
                useWeapon(*laserplaatsdrie, textureManager.spritelaserleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogeldrie->spriteLaserKogeltwee);
                useWeapon(*laserkogeldrie, shooterPositiondrie, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);
                laserkogeldrie->updateprobeer();
                laserplaatsdrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
                laserkogeldrie->fire(shooterPositiondrie, 1080, 600, 0, 0);
            }
            //--------------------------------------------------------
            if (spriteBuybluedrie)
            {
                
                    drawSpriteIfVisible::drawSpriteVisible(window, canonplaats->spritecanonleveleen, shooterPosition, sf::Vector2f(canon.spritecanonleveleen.getLocalBounds().width / 2, canon.spritecanonleveleen.getLocalBounds().height / 2));
                    useWeapon(*canonplaats, textureManager.spritecanonleveleen.getPosition(), 1080, 600, 0, 0);
                    drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogel->spriteCanonKogeltwee);
                    useWeapon(*canonkogel, shooterPosition,1080, 600, 0, 0);
                    //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);

                    if (snel->spriteEnemy.getPosition().x < canonplaats->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaats->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(-1.0f, -1.0f);  // move right
                        canonkogel->update(direction.x, direction.y);
                        canonkogel->fire(shooterPosition, 1080, 600, 0, 0);
                    }
                    if (snel->spriteEnemy.getPosition().x < canonplaats->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaats->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(-1.0f, 0.0f);  // move right
                        canonkogel->update(direction.x, direction.y);
                        canonkogel->fire(shooterPosition, 1080, 600, 0, 0);
                    }
                    if (snel->spriteEnemy.getPosition().x < canonplaats->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaats->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(-1.0f, 1.0f);  // move right
                        canonkogel->update(direction.x, direction.y);
                        canonkogel->fire(shooterPosition, 1080, 600, 0, 0);
                    }
                    else if (snel->spriteEnemy.getPosition().x == canonplaats->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaats->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(0.0f, 1.0f);  // move right
                        canonkogel->update(direction.x, direction.y);
                        canonkogel->fire(shooterPosition, 1080, 600, 0, 0);
                    }
                    else if (snel->spriteEnemy.getPosition().x > canonplaats->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaats->spritecanonleveleen.getPosition().y)
                    {
                        direction = sf::Vector2f(+1.0f, 1.0f);  // move left
                        canonkogel->update(direction.x, direction.y);
                        canonkogel->fire(shooterPosition, 1080, 600, 0, 0);
                    }
                    else if (snel->spriteEnemy.getPosition().x > canonplaats->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaats->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(+1.0f, 0.0f);  // move right
                        canonkogel->update(direction.x, direction.y);
                        canonkogel->fire(shooterPosition, 1080, 600, 0, 0);
                    }
                    else if (snel->spriteEnemy.getPosition().x > canonplaats->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaats->spritecanonleveleen.getPosition().y)
                    {
                        sf::Vector2f direction(+1.0f, -1.0f);  // move right
                        canonkogel->update(direction.x, direction.y);
                        canonkogel->fire(shooterPosition, 1080, 600, 0, 0);
                }
            }
            if (spriteBuyReddrie)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, laserplaats->spritelaserleveleen, shooterPosition, sf::Vector2f(laser.spritelaserleveleen.getLocalBounds().width / 2, laser.spritelaserleveleen.getLocalBounds().height / 2));
                useWeapon(*laserplaats, textureManager.spritelaserleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogel->spriteLaserKogeltwee);
                useWeapon(*laserkogel, shooterPosition,1080,600,0,0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);
                laserkogel->updateprobeer();
                laserplaats->fire(shooterPosition, 1080, 600, 0, 0);
                laserkogel->fire(shooterPosition, 1080, 600, 0, 0);
            }
            //--------------------------------------------------------
            if (spriteBuybluevier)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatsvier->spritecanonleveleen, shooterPositionvier, sf::Vector2f(canon.spritecanonleveleen.getLocalBounds().width / 2, canon.spritecanonleveleen.getLocalBounds().height / 2));
                useWeapon(*canonplaatsvier, textureManager.spritecanonleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogelvier->spriteCanonKogeltwee);
                useWeapon(*canonkogelvier, shooterPositionvier, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);

                if (snel->spriteEnemy.getPosition().x < canonplaatsvier->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatsvier->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, -1.0f);  // move right
                    canonkogelvier->update(direction.x, direction.y);
                    canonkogelvier->fire(shooterPositionvier, 1080, 600, 0, 0);
                }
                if (snel->spriteEnemy.getPosition().x < canonplaatsvier->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatsvier->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, 0.0f);  // move right
                    canonkogelvier->update(direction.x, direction.y);
                    canonkogelvier->fire(shooterPositionvier, 1080, 600, 0, 0);
                }
                if (snel->spriteEnemy.getPosition().x < canonplaatsvier->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsvier->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, 1.0f);  // move right
                    canonkogelvier->update(direction.x, direction.y);
                    canonkogelvier->fire(shooterPositionvier, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x == canonplaatsvier->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsvier->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(0.0f, 1.0f);  // move right
                    canonkogelvier->update(direction.x, direction.y);
                    canonkogelvier->fire(shooterPositionvier, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsvier->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsvier->spritecanonleveleen.getPosition().y)
                {
                    direction = sf::Vector2f(+1.0f, 1.0f);  // move left
                    canonkogelvier->update(direction.x, direction.y);
                    canonkogelvier->fire(shooterPositionvier, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsvier->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatsvier->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(+1.0f, 0.0f);  // move right
                    canonkogelvier->update(direction.x, direction.y);
                    canonkogelvier->fire(shooterPositionvier, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsvier->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatsvier->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(+1.0f, -1.0f);  // move right
                    canonkogelvier->update(direction.x, direction.y);
                    canonkogelvier->fire(shooterPositionvier, 1080, 600, 0, 0);
                }
            }
            if (spriteBuyRedvier)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, laserplaatsvier->spritelaserleveleen, shooterPositionvier, sf::Vector2f(laser.spritelaserleveleen.getLocalBounds().width / 2, laser.spritelaserleveleen.getLocalBounds().height / 2));
                useWeapon(*laserplaatsvier, textureManager.spritelaserleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogelvier->spriteLaserKogeltwee);
                useWeapon(*laserkogelvier, shooterPositionvier, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);
                laserkogelvier->updateprobeer();
                laserplaatsvier->fire(shooterPositionvier, 1080, 600, 0, 0);
                laserkogelvier->fire(shooterPositionvier, 1080, 600, 0, 0);
            }
            //--------------------------------------------------------
            if (spriteBuybluevijf)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatsvijf->spritecanonleveleen, shooterPositionvijf, sf::Vector2f(canon.spritecanonleveleen.getLocalBounds().width / 2, canon.spritecanonleveleen.getLocalBounds().height / 2));
                useWeapon(*canonplaatsvijf, textureManager.spritecanonleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogelvijf->spriteCanonKogeltwee);
                useWeapon(*canonkogelvijf, shooterPositionvijf, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);

                if (snel->spriteEnemy.getPosition().x < canonplaatsvijf->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatsvijf->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, -1.0f);  // move right
                    canonkogelvijf->update(direction.x, direction.y);
                    canonkogelvijf->fire(shooterPositionvijf, 1080, 600, 0, 0);
                }
                if (snel->spriteEnemy.getPosition().x < canonplaatsvijf->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatsvijf->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, 0.0f);  // move right
                    canonkogelvijf->update(direction.x, direction.y);
                    canonkogelvijf->fire(shooterPositionvier, 1080, 600, 0, 0);
                }
                if (snel->spriteEnemy.getPosition().x < canonplaatsvijf->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsvijf->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, 1.0f);  // move right
                    canonkogelvijf->update(direction.x, direction.y);
                    canonkogelvijf->fire(shooterPositionvijf, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x == canonplaatsvijf->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsvijf->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(0.0f, 1.0f);  // move right
                    canonkogelvijf->update(direction.x, direction.y);
                    canonkogelvijf->fire(shooterPositionvijf, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsvijf->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatsvijf->spritecanonleveleen.getPosition().y)
                {
                    direction = sf::Vector2f(+1.0f, 1.0f);  // move left
                    canonkogelvijf->update(direction.x, direction.y);
                    canonkogelvijf->fire(shooterPositionvijf, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsvijf->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatsvijf->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(+1.0f, 0.0f);  // move right
                    canonkogeltwee->update(direction.x, direction.y);
                    canonkogeltwee->fire(shooterPositionvijf, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatsvijf->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatsvijf->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(+1.0f, -1.0f);  // move right
                    canonkogelvijf->update(direction.x, direction.y);
                    canonkogelvijf->fire(shooterPositionvijf, 1080, 600, 0, 0);
                }

            }
            if (spriteBuyRedvijf)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, laserplaatsvijf->spritelaserleveleen, shooterPositionvijf, sf::Vector2f(laser.spritelaserleveleen.getLocalBounds().width / 2, laser.spritelaserleveleen.getLocalBounds().height / 2)); // nog 180 grade kunne draaien toevoegen in de functie, rood en blauw wissele en verkopen toevoegen
                useWeapon(*laserplaatsvijf, textureManager.spritelaserleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogelvijf->spriteLaserKogeltwee);
                useWeapon(*laserkogelvijf, shooterPositionvijf, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);
                laserkogelvijf->updateprobeer();
                laserplaatsvijf->fire(shooterPositionvijf, 1080, 600, 0, 0);
                laserkogelvijf->fire(shooterPositionvijf, 1080, 600, 0, 0);
            }
            //--------------------------------------------------------
            if (spriteBuybluezes)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatszes->spritecanonleveleen, shooterPositionzes, sf::Vector2f(canon.spritecanonleveleen.getLocalBounds().width / 2, canon.spritecanonleveleen.getLocalBounds().height / 2));
                useWeapon(*canonplaatszes, textureManager.spritecanonleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogelzes->spriteCanonKogeltwee);
                useWeapon(*canonkogelzes, shooterPositionzes, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);
                if (snel->spriteEnemy.getPosition().x < canonplaatszes->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatszes->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, -1.0f);  // move right
                    canonkogelzes->update(direction.x, direction.y);
                    canonkogelzes->fire(shooterPositionzes, 1080, 600, 0, 0);
                }
                if (snel->spriteEnemy.getPosition().x < canonplaatszes->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatszes->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, 0.0f);  // move right
                    canonkogelzes->update(direction.x, direction.y);
                    canonkogelzes->fire(shooterPositionzes, 1080, 600, 0, 0);
                }
                if (snel->spriteEnemy.getPosition().x < canonplaatszes->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatszes->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(-1.0f, 1.0f);  // move right
                    canonkogelzes->update(direction.x, direction.y);
                    canonkogelzes->fire(shooterPositionzes, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x == canonplaatszes->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatszes->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(0.0f, 1.0f);  // move right
                    canonkogelzes->update(direction.x, direction.y);
                    canonkogelzes->fire(shooterPositionzes, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatszes->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y > canonplaatszes->spritecanonleveleen.getPosition().y)
                {
                    direction = sf::Vector2f(+1.0f, 1.0f);  // move left
                    canonkogelzes->update(direction.x, direction.y);
                    canonkogelzes->fire(shooterPositionzes, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatszes->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y == canonplaatszes->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(+1.0f, 0.0f);  // move right
                    canonkogelzes->update(direction.x, direction.y);
                    canonkogelzes->fire(shooterPositionzes, 1080, 600, 0, 0);
                }
                else if (snel->spriteEnemy.getPosition().x > canonplaatszes->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatszes->spritecanonleveleen.getPosition().y)
                {
                    sf::Vector2f direction(+1.0f, -1.0f);  // move right
                    canonkogelzes->update(direction.x, direction.y);
                    canonkogelzes->fire(shooterPositionzes, 1080, 600, 0, 0);
                }
            }
            if (spriteBuyRedzes)
            {
                drawSpriteIfVisible::drawSpriteVisible(window, laserplaatszes->spritelaserleveleen, shooterPositionzes, sf::Vector2f(laser.spritelaserleveleen.getLocalBounds().width / 2, laser.spritelaserleveleen.getLocalBounds().height / 2));
                useWeapon(*laserplaatszes, textureManager.spritelaserleveleen.getPosition(), 1080, 600, 0, 0);
                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogelzes->spriteLaserKogeltwee);
                useWeapon(*laserkogelzes, shooterPositionzes, 1080, 600, 0, 0);
                //canonkogel->update(snel->spriteEnemy.getPosition(), shooterPosition);
                laserkogelzes->updateprobeer();
                laserplaatszes->fire(shooterPosition, 1080, 600, 0, 0);
                laserkogelzes->fire(shooterPosition, 1080, 600, 0, 0);
            }

            /*mss nie allemaal laten richten op snel bv de Laser alleen lucht (nieuwe enemeyvlieg) en de Canon alleen grond Enmey, snel->spriteEnemy
            */


            if (spriteVisibleP)
            {
                //if (redhealthBar_een_copy.currentHealth > 40)
                //{
                    window.draw(snel->spriteEnemy);

                    window.draw(healthBar_een.bar);
                    window.draw(redhealthBar_een_copy.bar);
                //}
                if (redhealthBar_twee_copy.currentHealth > 40)
                {
                    window.draw(traag->spriteEnemy);

                    window.draw(healthBar_twee.bar);
                    window.draw(redhealthBar_twee_copy.bar);
                }
                //std::cout << "The health is " << redhealthBar_een_copy.getCurrentHealth() << std::endl; //String class
                //std::cout << "The healthtwee is " << redhealthBar_twee_copy.getCurrentHealth() << std::endl; //String class

                if (spriteTruePlay)
                {

                    nextmoneyIncrement = 1;
                    swap(moneyIncrement, nextmoneyIncrement);
                    //std::cout << "moneyIncrement: " << moneyIncrement << ", nextmoneyIncrement: " << nextmoneyIncrement << std::endl;

                    updateEnemies();

                }
                if (!spriteTruePlay)
                {
                    nextmoneyIncrement = 0;
                    swap(moneyIncrement, nextmoneyIncrement); //call-by-reference

                }
                if (spriteTrueOpenOption)
                {
                    window.draw(*(textureManager.spriteRolwapens));
                }
            }
            window.display();
        }
        running = false;
        backgroundThread.join();
    }
}

//geen unsigned char gebruikt want heb aangpast in healthbar mss kan ik nog doen met template