#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
#include <string>
#include "drawSpriteIfVisible.h"
#include "HandleIntersectionAndDamage.h"
#include "Gold.h"
#include "HealthBar.h"
#include "Game.h"
#include "Wave.h"

#define M_PI 3.14159265358979323846

using namespace std;
namespace Towerdefense
{
    Game::Game()
        :healthBar_een(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50), //parameterized constructors
        redhealthBar_een_copy(healthBar_een), //Copy constructor

        healthBar_twee(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 30), //parameterized constructors
        redhealthBar_twee_copy(healthBar_twee), //Copy constructor

        snel(new EnemyOne(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 10, 9.0f, 9.0f)), //door new automatisch gebruik van nullptr?
        traag(new EnemyOne(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 10, 9.0f, 5.0f)),
        canon(new Canon(sf::Vector2f(150, 180))),
        laser(new Laser(sf::Vector2f(150, 180))),
        gold(10)
    {

    }
    Towerdefense::Gold<int> goldInt(20);
    Towerdefense::Gold<double> goldDouble(1.0);

    Game::~Game()
    {
        // Release dynamically allocated memory
        delete snel;
        delete traag;
        delete canon;
        delete laser;
    }

    void Game::useWeapon(Weapon& weapon, sf::Vector2f shooterPosition)
    {
        weapon.fire(shooterPosition);
    }

    void Game::run(sf::RenderWindow& window) {

        window.setFramerateLimit(60);
        sf::Vector2f shooterPosition;

        string CanonMoney = "4";
        string LaserMoney = "7";

        redhealthBar_een_copy.bar.setFillColor(sf::Color::Green);
        redhealthBar_twee_copy.bar.setFillColor(sf::Color::Green);

        // Bool
        bool isPKeyPressed = false;
        bool isKKeyPressed = false; //Continue
        bool isEKeyPressed = false;
        bool isLkeyPressed = false;
        bool isQKeyPressed = false;
        bool isCKeyPressed = false;
        bool isSKeyPressed = false;
        bool isDKeyPressed = false;

        bool spriteVisibleP = false;
        bool spriteVisibleC = false;
        bool spriteVisibleE = false;
        bool spriteVisibleL = false;
        bool spriteVisibleQ = false;

        bool PlaceEIsEmty = true;


        //Window
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {

                isPKeyPressed = true;
                spriteVisibleP = true;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                isEKeyPressed = false;
                spriteVisibleE = false;
            }
            //Knop E
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                isEKeyPressed = true;
                spriteVisibleE = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isEKeyPressed && PlaceEIsEmty)
            {
                isLkeyPressed = true;
                spriteVisibleL = true;
                PlaceEIsEmty = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isEKeyPressed && !PlaceEIsEmty)
            {
                string strL = "Can not place something here you have to sell it";
                std::cout << "" << strL << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isEKeyPressed && PlaceEIsEmty) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleC = true;
                PlaceEIsEmty = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && isEKeyPressed && !PlaceEIsEmty && spriteVisibleC) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << CanonMoney << " Dollar worth" << endl; //String class
                std::cout << "" << goldDouble.getCurrentGold() << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
                cout << endl;

                goldInt.addMoney(4); //call-by-reference
                goldInt.subtractMoney(2); //call-by-reference
                goldDouble.addMoney(0.1); //call-by-reference
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && isEKeyPressed && !PlaceEIsEmty && spriteVisibleL) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << LaserMoney << "Worth" << endl; //String class
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isEKeyPressed && !PlaceEIsEmty)
            {
                string strC = "Can not place something here you have to sell it";
                std::cout << "" << strC << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isEKeyPressed && !PlaceEIsEmty && spriteVisibleC) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleC = false;
                spriteVisibleL = false;
                PlaceEIsEmty = true; //extra geld geven 
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isEKeyPressed && !PlaceEIsEmty && spriteVisibleL) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleC = false;
                spriteVisibleL = false;
                PlaceEIsEmty = true; //extra geld geven 
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isEKeyPressed && PlaceEIsEmty)
            {
                string strS = "You have nothing to sell!";
                std::cout << "" << strS << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                isEKeyPressed = false;
                spriteVisibleE = false;
            }
            else
            {
                isCKeyPressed = false;
                isKKeyPressed = false;
                isPKeyPressed = false;
                isEKeyPressed = false;
                isLkeyPressed = false; //hoofdletter
                isQKeyPressed = false;
                isSKeyPressed = false;
            }



            //Window leeg maken

            window.clear();

            //Titlescherm

            window.draw(*(textureManager.spriteAchtergrond));
            window.draw(*(textureManager.spritepaper));
            window.draw(*(textureManager.spritetowerdefensetext));
            window.draw(*(textureManager.spriteplay));
            window.draw(*(textureManager.spriteoption));


            if (spriteVisibleP)
            {
                window.draw(*(textureManager.spritepad));
                window.draw(*(textureManager.spritecastle));
                window.draw(*(textureManager.spritetowereen));
                window.draw(*(textureManager.spritetowertwee));
                window.draw(*(textureManager.spritetowerdrie));
                window.draw(*(textureManager.spritetowervier));
                window.draw(*(textureManager.spritetowervijf));
                window.draw(*(textureManager.spritetowerzes));
                window.draw(*(textureManager.spriteinsideMoneyrec));
                window.draw(*(textureManager.spriteMoneyrec));
                window.draw(*(textureManager.spriteE));
                window.draw(*(textureManager.spriteGoldname));

                if (redhealthBar_een_copy.currentHealth > 45)
                {
                    window.draw(snel->spriteEnemyOne);
                    window.draw(healthBar_een.bar);
                    window.draw(redhealthBar_een_copy.bar);
                }

                if (redhealthBar_twee_copy.currentHealth > 25)
                {
                    window.draw(traag->spriteEnemyOne);
                    window.draw(healthBar_twee.bar);
                    window.draw(redhealthBar_twee_copy.bar);
                }

                std::thread snelUpdateThread(&EnemyOne::update, snel); //Thread
                std::thread traagUpdateThread(&EnemyOne::update, traag); //Thread

                // Wait for threads to finish before proceeding
                snelUpdateThread.join(); //Thread
                traagUpdateThread.join();


                std::cout << "The health is " << redhealthBar_een_copy.getCurrentHealth() << endl; //String class
                std::cout << "The health is " << redhealthBar_twee_copy.getCurrentHealth() << endl; //String class


                if (spriteVisibleE)
                {
                    shooterPosition = sf::Vector2f(240, 240);
                    window.draw(*(textureManager.spriteRolwapens)); //als c wordt geduwt dan sluit e staat hierboven zo gedefineerd
                    //hier moeten de wapens gekozen worden doen door threaths ofzo 
                }
                if (spriteVisibleC)
                {
                    window.draw(*(textureManager.spritecanonleveleen));//als andere letter ook waar is ook op true zetten
                    useWeapon(*canon, shooterPosition);
                    drawSpriteIfVisible::drawSpriteVisible(window, canon->spriteCanonKogeltwee);

                }
                if (spriteVisibleL)
                {
                    window.draw(*(textureManager.spritelaserleveleen));
                    useWeapon(*laser, shooterPosition);
                    drawSpriteIfVisible::drawSpriteVisible(window, laser->spritelasertwee);
                    laser->update();
                }

                HandleIntersectionAndDamage::handleIntersectionsAndDamage(laser->spritelasertwee, snel->spriteEnemyOne, redhealthBar_een_copy); //redhealthBar_een hoort bij enemey_one
                HandleIntersectionAndDamage::handleIntersectionsAndDamage(canon->spriteCanonKogeltwee, snel->spriteEnemyOne, redhealthBar_een_copy); //handle.. is 4

                HandleIntersectionAndDamage::handleIntersectionsAndDamage(laser->spritelasertwee, traag->spriteEnemyOne, redhealthBar_twee_copy); //redhealthBar_een hoort bij enemey_one
                HandleIntersectionAndDamage::handleIntersectionsAndDamage(canon->spriteCanonKogeltwee, traag->spriteEnemyOne, redhealthBar_twee_copy); //handle.. is 4

                healthBar_een.updatePosition(sf::Vector2f(snel->spriteEnemyOne.getPosition()));
                redhealthBar_een_copy.updatePosition(sf::Vector2f(snel->spriteEnemyOne.getPosition()));

                healthBar_twee.updatePosition(sf::Vector2f(traag->spriteEnemyOne.getPosition()));
                redhealthBar_twee_copy.updatePosition(sf::Vector2f(traag->spriteEnemyOne.getPosition()));

            }
            window.display();
        }
    }
}

//wat is een inline?
//mss hartjes maken in plaats van balk of toch sommige enemys
//mss useWeapon kunne toepassen hier ik snap niet goed wat dit doen
//plaatsdrie < Weapons < Canon, Laser, MG class colision ofzo
//moet geld genoeg hebben voor wapen te kunne kopen
//verschillende Waves

/*
if (sellPriceCanon)
{
std::cout << "The Cannon is " << CanonMoney << "Worth" << endl;
}
*/