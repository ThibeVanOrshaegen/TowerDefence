#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>
#include <time.h>
#include <string>
#include "drawSpriteIfVisible.h"
#include "drawSpriteIfVisibleshoot.h"
#include "HandleIntersectionAndDamage.h"
#include "Updaterotation.h"
#include "Gold.h"
#include "HealthBar.h"
#include "Game.h"
#include "Wave.h"
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;
namespace Towerdefense
{
    Game::Game()
        :healthBar_een(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 50), //parameterized constructors //default value in function definition '50'
        redhealthBar_een_copy(healthBar_een), //Copy constructor

        healthBar_twee(sf::Vector2f(100, 400), sf::Vector2f(70, 10), 30), //parameterized constructors
        redhealthBar_twee_copy(healthBar_twee), //Copy constructor

        snel(new EnemyOne(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 10, 3.0f, 3.0f)), //door new automatisch gebruik van nullptr?
        traag(new EnemyOne(sf::Vector2f(0, 410), sf::Vector2f(50, 50), 10, 3.0f, 3.0f)),
        canonkogel(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogeltwee(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogeldrie(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogelvier(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogelvijf(new Canonshooting(sf::Vector2f(150, 180))),
        canonkogelzes(new Canonshooting(sf::Vector2f(150, 180))),

        laserkogel(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogeltwee(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogeldrie(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogelvier(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogelvijf(new Lasershooting(sf::Vector2f(150, 180))),
        laserkogelzes(new Lasershooting(sf::Vector2f(150, 180))),

        canonplaats(new Canon(sf::Vector2f(500, 260))),
        canonplaatstwee(new Canon(sf::Vector2f(500, 260))),
        canonplaatsdrie(new Canon(sf::Vector2f(500, 260))),
        canonplaatsvier(new Canon(sf::Vector2f(500, 260))),
        canonplaatsvijf(new Canon(sf::Vector2f(500, 260))),
        canonplaatszes(new Canon(sf::Vector2f(500, 260))),
        laserplaats(new Laser(sf::Vector2f(150, 180))),
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
        delete canonkogel;//een,twee,...
        delete laserkogel;
    }
    // Initialize static members
    bool Game::isPKeyPressed = false;
    bool Game::isGKeyPressed = false;

    bool Game::isKKeyPressed = false;
    bool Game::isLkeyPressed = false;
    bool Game::isQKeyPressed = false;
    bool Game::isCKeyPressed = false;
    bool Game::isSKeyPressed = false;
    bool Game::isMKeyPressed = false;

    bool Game::isEKeyPressed = false;
    bool Game::isTKeyPressed = false;
    bool Game::isDKeyPressed = false;
    bool Game::isVKeyPressed = false;
    bool Game::isWKeyPressed = false;
    bool Game::isZKeyPressed = false;

    bool Game::spriteVisibleP = false;
    bool Game::spriteVisibleG = false;
    bool Game::spriteVisibleO = false;

    bool Game::spriteVisibleC = false;
    bool Game::spriteVisibleCtwee = false;
    bool Game::spriteVisibleCdrie = false;
    bool Game::spriteVisibleCvier = false;
    bool Game::spriteVisibleCvijf = false;
    bool Game::spriteVisibleCzes = false;

    bool Game::spriteVisibleRotation = false;

    bool Game::spriteVisibleL = false;
    bool Game::spriteVisibleLtwee = false;
    bool Game::spriteVisibleLdrie = false;
    bool Game::spriteVisibleLvier = false;
    bool Game::spriteVisibleLvijf = false;
    bool Game::spriteVisibleLzes = false;

    bool Game::spriteVisibleQ = false;

    bool Game::spriteVisibleE = false;
    bool Game::spriteVisibleT = false;
    bool Game::spriteVisibleD = false;
    bool Game::spriteVisibleV = false;
    bool Game::spriteVisibleW = false;
    bool Game::spriteVisibleZ = false;

    bool Game::shooterposition = false;

    bool Game::EshootPosition = false;
    bool Game::TshootPosition = false;
    bool Game::DshootPosition = false;
    bool Game::VshootPosition = false;
    bool Game::WshootPosition = false;
    bool Game::ZshootPosition = false;

    bool Game::ELshootPosition = false;
    bool Game::TLshootPosition = false;
    bool Game::DLshootPosition = false;
    bool Game::VLshootPosition = false;
    bool Game::WLshootPosition = false;
    bool Game::ZLshootPosition = false;

    bool Game::PlaceEIsEmty = true;
    bool Game::PlaceTIsEmty = true;
    bool Game::PlaceDIsEmty = true;
    bool Game::PlaceVIsEmty = true;
    bool Game::PlaceWIsEmty = true;
    bool Game::PlaceZIsEmty = true;

    bool Game::WaveOneCompleet = false;

    void Game::useWeapon(Weapon& weapon, sf::Vector2f shooterPosition)
    {
        weapon.fire(shooterPosition);
    }

    void Game::updateEnemies() {

        std::thread snelUpdateThread(&EnemyOne::update, snel);
        std::thread traagUpdateThread(&EnemyOne::update, traag);

        // Wait for threads to finish before proceeding
        snelUpdateThread.join();
        traagUpdateThread.join();

        /*if (snel->spriteEnemyOne.getPosition().x >= 1002) {

            snel->resetPosition();

            redhealthBar_een_copy.currentHealth = 50; //terug opnieuw spam zo blijft spel altijd doorgaan
        }*/

    }
    void Game::updateHandleIntersectionAndDamage() {//canonkogeltwee,...

        HandleIntersectionAndDamage::handleIntersectionsAndDamage(laserkogel->spriteLaserKogeltwee, snel->spriteEnemyOne, redhealthBar_een_copy); //redhealthBar_een hoort bij enemey_one
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(canonkogel->spriteCanonKogeltwee, snel->spriteEnemyOne, redhealthBar_een_copy); //handle.. is 4

        HandleIntersectionAndDamage::handleIntersectionsAndDamage(laserkogel->spriteLaserKogeltwee, traag->spriteEnemyOne, redhealthBar_twee_copy); //redhealthBar_een hoort bij enemey_one
        HandleIntersectionAndDamage::handleIntersectionsAndDamage(canonkogel->spriteCanonKogeltwee, traag->spriteEnemyOne, redhealthBar_twee_copy); //handle.. is 4
    }

    void Game::updatehealthBar() {

        healthBar_een.updatePosition(sf::Vector2f(snel->spriteEnemyOne.getPosition()));
        redhealthBar_een_copy.updatePosition(sf::Vector2f(snel->spriteEnemyOne.getPosition()));

        healthBar_twee.updatePosition(sf::Vector2f(traag->spriteEnemyOne.getPosition()));
        redhealthBar_twee_copy.updatePosition(sf::Vector2f(traag->spriteEnemyOne.getPosition()));

        if (redhealthBar_een_copy.currentHealth <= 49 ) {
            // Plaats snel terug op de oorspronkelijke positie
            snel->resetPosition();
            //redhealthBar_een_copy.currentHealth = 50; //terug opnieuw spam zo blijft spel altijd doorgaan
        }
        
    }


    void Game::run(sf::RenderWindow& window) {

        window.setFramerateLimit(60);
        sf::Vector2f shooterPosition;
        sf::Vector2f shooterPositiontwee;
        sf::Vector2f shooterPositiondrie;
        sf::Vector2f shooterPositionvier;
        sf::Vector2f shooterPositionvijf;
        sf::Vector2f shooterPositionzes;

        sf::Vector2f shooterPositionL;
        sf::Vector2f shooterPositiontweeL;
        sf::Vector2f shooterPositiondrieL;
        sf::Vector2f shooterPositionvierL;
        sf::Vector2f shooterPositionvijfL;
        sf::Vector2f shooterPositionzesL;

        shooterPosition = sf::Vector2f(328, 294);
        shooterPositiontwee = sf::Vector2f(85, 330);
        shooterPositiondrie = sf::Vector2f(85, 518);
        shooterPositionvier = sf::Vector2f(344, 482);
        shooterPositionvijf = sf::Vector2f(605, 395);
        shooterPositionzes = sf::Vector2f(901, 458);

        string CanonMoney = "4";
        string LaserMoney = "7";

        redhealthBar_een_copy.bar.setFillColor(sf::Color::Green);
        redhealthBar_twee_copy.bar.setFillColor(sf::Color::Green);


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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
            {
                isGKeyPressed = true;
                spriteVisibleG = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
            {
                isGKeyPressed = false;
                spriteVisibleG = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                isEKeyPressed = false;
                spriteVisibleE = false;
            }

           
//---------------------------------------------------------------------------------------------------------------------------------------------------
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
                ELshootPosition = true;
                PlaceEIsEmty = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isEKeyPressed && !PlaceEIsEmty)
            {
                string strL = "Can not place something here you have to sell it"; 
                std::cout << "" <<strL<<endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isEKeyPressed && PlaceEIsEmty) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleC = true;
                EshootPosition = true;
                PlaceEIsEmty = false;
                goldInt.subtractMoney(2); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isEKeyPressed && !PlaceEIsEmty && spriteVisibleC) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << CanonMoney << " Dollar worth" << endl; //String class
                std::cout <<"" << goldDouble.getCurrentGold()<< " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
                cout << endl;
                //goldDouble.addMoney(0.1); //call-by-reference
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isEKeyPressed && !PlaceEIsEmty && spriteVisibleL) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << LaserMoney << "Worth" << endl; //String class
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isEKeyPressed && !PlaceEIsEmty)
            {
                string strC = "Can not place something here you have to sell it";
                std::cout << "" <<strC<< endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isEKeyPressed && !PlaceEIsEmty && spriteVisibleC) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleC = false;
                EshootPosition = false;
                spriteVisibleL = false;
                PlaceEIsEmty = true; //extra geld geven 
                goldInt.addMoney(4); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isEKeyPressed && !PlaceEIsEmty && spriteVisibleL) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleC = false;
                spriteVisibleL = false;
                PlaceEIsEmty = true; //extra geld geven 
                ELshootPosition = false;
                goldInt.addMoney(4); //call-by-reference
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isEKeyPressed && PlaceEIsEmty)
            {
                string strS = "You have nothing to sell!";
                std::cout << "" << strS << endl; //String class
            }
 //---------------------------------------------------------------------------------------------------------------------------------------------------
            //knop T
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
            {
                isTKeyPressed = true;
                spriteVisibleT = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isTKeyPressed && PlaceTIsEmty)
            {
                isLkeyPressed = true;
                spriteVisibleLtwee = true;
                TLshootPosition = true;
                PlaceTIsEmty = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isTKeyPressed && !PlaceTIsEmty)
            {
                string strL = "Can not place something here you have to sell it";
                std::cout << "" << strL << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isTKeyPressed && PlaceTIsEmty) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCtwee = true;
                TshootPosition = true;
                PlaceTIsEmty = false;
                goldInt.subtractMoney(2); //call-by-refp erence
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isTKeyPressed && !PlaceTIsEmty && spriteVisibleCtwee) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << CanonMoney << " Dollar worth" << endl; //String class
                std::cout << "" << goldDouble.getCurrentGold() << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
                cout << endl;
                //goldDouble.addMoney(0.1); //call-by-reference
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isTKeyPressed && !PlaceTIsEmty && spriteVisibleLtwee) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << LaserMoney << "Worth" << endl; //String class
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isTKeyPressed && !PlaceTIsEmty)
            {
                string strC = "Can not place something here you have to sell it";
                std::cout << "" << strC << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isTKeyPressed && !PlaceTIsEmty && spriteVisibleCtwee) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCtwee = false;
                TshootPosition = false;
                spriteVisibleLtwee = false;
                PlaceTIsEmty = true; //extra geld geven 

                goldInt.addMoney(4); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isTKeyPressed && !PlaceTIsEmty && spriteVisibleLtwee) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCtwee = false;
                TLshootPosition = false;
                spriteVisibleLtwee = false;
                PlaceTIsEmty = true; //extra geld geven 
                goldInt.addMoney(4); //call-by-reference //hier is iets mis mee deze verkoopt niet
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isTKeyPressed && PlaceTIsEmty)
            {
                string strS = "You have nothing to sell!";
                std::cout << "" << strS << endl; //String class
            }
//---------------------------------------------------------------------------------------------------------------------------------------------------
            //Knop V
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
            {
                isVKeyPressed = true;
                spriteVisibleV = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isVKeyPressed && PlaceVIsEmty)
            {
                isLkeyPressed = true;
                spriteVisibleLdrie = true;
                VLshootPosition = true;
                PlaceVIsEmty = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isVKeyPressed && !PlaceVIsEmty)
            {
                string strL = "Can not place something here you have to sell it";
                std::cout << "" << strL << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isVKeyPressed && PlaceVIsEmty) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCdrie = true;
                VshootPosition = true;
                PlaceVIsEmty = false;
                goldInt.subtractMoney(2); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isVKeyPressed && !PlaceVIsEmty && spriteVisibleCdrie) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << CanonMoney << " Dollar worth" << endl; //String class
                std::cout << "" << goldDouble.getCurrentGold() << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
                cout << endl;
                //goldDouble.addMoney(0.1); //call-by-reference
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isVKeyPressed && !PlaceVIsEmty && spriteVisibleLdrie) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << LaserMoney << "Worth" << endl; //String class
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isVKeyPressed && !PlaceVIsEmty)
            {
                string strC = "Can not place something here you have to sell it";
                std::cout << "" << strC << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isVKeyPressed && !PlaceVIsEmty && spriteVisibleCdrie) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCdrie = false;
                VshootPosition = false;
                spriteVisibleLdrie = false;
                PlaceVIsEmty = true; //extra geld geven 
                goldInt.addMoney(4); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isVKeyPressed && !PlaceVIsEmty && spriteVisibleLdrie) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCdrie = false;
                spriteVisibleLdrie = false;
                PlaceVIsEmty = true; //extra geld geven 
                VLshootPosition = false;
                goldInt.addMoney(4); //call-by-reference
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isEKeyPressed && PlaceEIsEmty)
            {
                string strS = "You have nothing to sell!";
                std::cout << "" << strS << endl; //String class
            }
 //---------------------------------------------------------------------------------------------------------------------------------------------------
            //Knop D
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                isDKeyPressed = true;
                spriteVisibleD = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isDKeyPressed && PlaceDIsEmty)
            {
                isLkeyPressed = true;
                spriteVisibleLvier = true;
                DLshootPosition = true;
                PlaceDIsEmty = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isDKeyPressed && !PlaceDIsEmty)
            {
                string strL = "Can not place something here you have to sell it";
                std::cout << "" << strL << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isDKeyPressed && PlaceDIsEmty) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCvier = true;
                DshootPosition = true;
                PlaceDIsEmty = false;
                goldInt.subtractMoney(2); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isDKeyPressed && !PlaceDIsEmty && spriteVisibleCvier) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << CanonMoney << " Dollar worth" << endl; //String class
                std::cout << "" << goldDouble.getCurrentGold() << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
                cout << endl;
                //goldDouble.addMoney(0.1); //call-by-reference
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isDKeyPressed && !PlaceDIsEmty && spriteVisibleLvier) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << LaserMoney << "Worth" << endl; //String class
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isDKeyPressed && !PlaceDIsEmty)
            {
                string strC = "Can not place something here you have to sell it";
                std::cout << "" << strC << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isDKeyPressed && !PlaceDIsEmty && spriteVisibleCvier) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCvier = false;
                DshootPosition = false;
                spriteVisibleLvier = false;
                PlaceDIsEmty = true; //extra geld geven 
                goldInt.addMoney(4); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isDKeyPressed && !PlaceDIsEmty && spriteVisibleLvier) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCvier = false;
                spriteVisibleLvier = false;
                PlaceDIsEmty = true; //extra geld geven 
                DLshootPosition = false;
                goldInt.addMoney(4); //call-by-reference
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isDKeyPressed && PlaceDIsEmty)
            {
                string strS = "You have nothing to sell!";
                std::cout << "" << strS << endl; //String class
            }
//---------------------------------------------------------------------------------------------------------------------------------------------------
             //Knop W
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                isWKeyPressed = true;
                spriteVisibleW = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isWKeyPressed && PlaceWIsEmty)
            {
                isLkeyPressed = true;
                spriteVisibleLvijf = true;
                WLshootPosition = true;
                PlaceWIsEmty = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isWKeyPressed && !PlaceWIsEmty)
            {
                string strL = "Can not place something here you have to sell it";
                std::cout << "" << strL << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isWKeyPressed && PlaceWIsEmty) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCvijf = true;
                WshootPosition = true;
                PlaceWIsEmty = false;
                goldInt.subtractMoney(2); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isWKeyPressed && !PlaceWIsEmty && spriteVisibleCvijf) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << CanonMoney << " Dollar worth" << endl; //String class
                std::cout << "" << goldDouble.getCurrentGold() << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
                cout << endl;
                //goldDouble.addMoney(0.1); //call-by-reference
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isWKeyPressed && !PlaceWIsEmty && spriteVisibleLvijf) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << LaserMoney << "Worth" << endl; //String class
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isWKeyPressed && !PlaceWIsEmty)
            {
                string strC = "Can not place something here you have to sell it";
                std::cout << "" << strC << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isWKeyPressed && !PlaceWIsEmty && spriteVisibleCvijf) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCvijf = false;
                WshootPosition = false;
                spriteVisibleLvijf = false;
                PlaceWIsEmty = true; //extra geld geven 
                goldInt.addMoney(4); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isWKeyPressed && !PlaceWIsEmty && spriteVisibleLvijf) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCvijf = false;
                spriteVisibleLvijf = false;
                PlaceWIsEmty = true; //extra geld geven 
                WLshootPosition = false;
                goldInt.addMoney(4); //call-by-reference
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isWKeyPressed && PlaceWIsEmty)
            {
                string strS = "You have nothing to sell!";
                std::cout << "" << strS << endl; //String class
            }
//---------------------------------------------------------------------------------------------------------------------------------------------------
            //Knop Z
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                isZKeyPressed = true;
                spriteVisibleZ = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isZKeyPressed && PlaceZIsEmty)
            {
                isLkeyPressed = true;
                spriteVisibleLzes = true;
                ZLshootPosition = true;
                PlaceZIsEmty = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && isZKeyPressed && !PlaceZIsEmty)
            {
                string strL = "Can not place something here you have to sell it";
                std::cout << "" << strL << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isZKeyPressed && PlaceZIsEmty) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCzes = true;
                ZshootPosition = true;
                PlaceZIsEmty = false;
                goldInt.subtractMoney(2); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isZKeyPressed && !PlaceZIsEmty && spriteVisibleCzes) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << CanonMoney << " Dollar worth" << endl; //String class
                std::cout << "" << goldDouble.getCurrentGold() << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
                cout << endl;
                //goldDouble.addMoney(0.1); //call-by-reference
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && isZKeyPressed && !PlaceZIsEmty && spriteVisibleLzes) //&&geld genoeg hebben
            {
                std::cout << "The Cannon is " << LaserMoney << "Worth" << endl; //String class
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isZKeyPressed && !PlaceZIsEmty)
            {
                string strC = "Can not place something here you have to sell it";
                std::cout << "" << strC << endl; //String class
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isZKeyPressed && !PlaceZIsEmty && spriteVisibleCzes) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCzes = false;
                ZshootPosition = false;
                spriteVisibleLzes = false;
                PlaceZIsEmty = true; //extra geld geven 
                goldInt.addMoney(4); //call-by-reference
                std::cout << " Current_Gold: " << goldInt.getCurrentGold() << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isZKeyPressed && !PlaceZIsEmty && spriteVisibleLzes) //&&geld genoeg hebben
            {
                isCKeyPressed = true;
                spriteVisibleCzes = false;
                spriteVisibleLzes = false;
                PlaceZIsEmty = true; //extra geld geven 
                ZLshootPosition = false;
                goldInt.addMoney(4); //call-by-reference
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isZKeyPressed && PlaceZIsEmty)
            {
                string strS = "You have nothing to sell!";
                std::cout << "" << strS << endl; //String class
            }
    //---------------------------------------------------------------------------------------------------------------------------------------------------           
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
                isGKeyPressed = false;
                isEKeyPressed = false;
                isLkeyPressed = false; //hoofdletter
                isQKeyPressed = false;
                isSKeyPressed = false;
                isTKeyPressed = false;
                isDKeyPressed = false;
                isVKeyPressed = false;
                isWKeyPressed = false;
                isZKeyPressed = false;
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
                window.draw(*(textureManager.spriteT));
                window.draw(*(textureManager.spriteD));
                window.draw(*(textureManager.spriteV));
                window.draw(*(textureManager.spriteW));
                window.draw(*(textureManager.spriteZ));
                window.draw(*(textureManager.spriteGoldname));

                    //std::cout << " "<<snel->spriteEnemyOne.getPosition().x << endl;
          
                        if (redhealthBar_een_copy.currentHealth > 45)
                        {
                            window.draw(snel->spriteEnemyOne);
                            window.draw(healthBar_een.bar);
                            window.draw(redhealthBar_een_copy.bar);
                        }


                        if (WaveOneCompleet/* redhealthBar_twee_copy.currentHealth > 25*/)
                        {
                            std::cout << "Enemy traag wordt toegevoegd" << endl;
                            window.draw(traag->spriteEnemyOne);
                            window.draw(healthBar_twee.bar);
                            window.draw(redhealthBar_twee_copy.bar);
                        }

                        //std::cout << "The health is " << redhealthBar_een_copy.getCurrentHealth() << endl; //String class

                        if (spriteVisibleE)
                        {
                            window.draw(*(textureManager.spriteRolwapens));
                            //hier moeten de wapens gekozen worden
                        }
                        if (spriteVisibleC || spriteVisibleCtwee || spriteVisibleCdrie || spriteVisibleCvier || spriteVisibleCvijf || spriteVisibleCzes)
                        {
                            if (EshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, canonplaats->spritecanonleveleen, shooterPosition, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*canonplaats, textureManager.spritecanonleveleen.getPosition());
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogel->spriteCanonKogeltwee);
                                useWeapon(*canonkogel, shooterPosition);
                                //canonkogel->update(); //niet nuttig denk ik
                                canonkogel->update(snel->spriteEnemyOne.getPosition(),shooterPosition);
                                canonplaats->fire(shooterPosition);
                                
                            }
                            if (TshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatstwee->spritecanonleveleen, shooterPositiontwee, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*canonkogeltwee, shooterPositiontwee);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogeltwee->spriteCanonKogeltwee);
                                //canonkogeltwee->update(); //niet nuttig denk ik
                                canonkogeltwee->update(snel->spriteEnemyOne.getPosition(),shooterPosition);
                                canonkogeltwee->fire(snel->spriteEnemyOne.getPosition());
                                                            
                            }
                            if (VshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatsdrie->spritecanonleveleen, shooterPositiondrie, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*canonkogeldrie, shooterPositiondrie);
                                //drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogeldrie->spriteCanonKogeltwee);
                                //canonkogeldrie->update(); //niet nuttig denk ik
                                canonkogeldrie->update(snel->spriteEnemyOne.getPosition(), shooterPositiondrie);
                                canonkogeldrie->fire(snel->spriteEnemyOne.getPosition());
                            }
                            if (DshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatsvier->spritecanonleveleen, shooterPositionvier, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*canonkogelvier, shooterPositionvier);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogelvier->spriteCanonKogeltwee);
                                //canonkogelvier->update(); //niet nuttig denk ik
                                canonkogelvier->update(snel->spriteEnemyOne.getPosition(), shooterPositionvier);
                                canonkogelvier->fire(snel->spriteEnemyOne.getPosition());
                            }
                            if (WshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatsvijf->spritecanonleveleen, shooterPositionvijf, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*canonkogelvijf, shooterPositionvijf);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogelvijf->spriteCanonKogeltwee);
                                //canonkogelvijf->update(); //niet nuttig denk ik
                                canonkogelvijf->update(snel->spriteEnemyOne.getPosition(), shooterPositionvijf);
                                canonkogelvijf->fire(snel->spriteEnemyOne.getPosition());
                            }
                            if (ZshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, canonplaatszes->spritecanonleveleen, shooterPositionzes, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*canonkogelzes, shooterPositionzes);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, canonkogelzes->spriteCanonKogeltwee);
                                //canonkogelzes->update(); //niet nuttig denk ik
                                canonkogelzes->update(snel->spriteEnemyOne.getPosition(), shooterPositionzes);
                                canonkogelzes->fire(snel->spriteEnemyOne.getPosition());
                            }
                        }
                        if (spriteVisibleL || spriteVisibleLtwee || spriteVisibleLdrie || spriteVisibleLvier || spriteVisibleLvijf || spriteVisibleLzes)
                        {
                            if (ELshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, laserplaats->spritelaserleveleen, shooterPosition, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*laserkogel, shooterPosition);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogel->spriteLaserKogeltwee);
                                laserkogel->update(); //niet nuttig denk ik
                            }
                            if (TLshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, laserplaats->spritelaserleveleen, shooterPositiontwee, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*laserkogeltwee, shooterPositiontwee);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogeltwee->spriteLaserKogeltwee);
                                laserkogeltwee->update(); //niet nuttig denk ik
                            }
                            if (VLshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, laserplaats->spritelaserleveleen, shooterPositiondrie, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*laserkogeldrie, shooterPositiondrie);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogeldrie->spriteLaserKogeltwee);
                                laserkogeldrie->update(); //niet nuttig denk ik denk ik
                            }
                            if (DLshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, laserplaats->spritelaserleveleen, shooterPositionvier, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*laserkogelvier, shooterPositionvier);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogelvier->spriteLaserKogeltwee);
                                laserkogelvier->update(); //niet nuttig denk ik denk ik
                            }
                            if (WLshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, laserplaats->spritelaserleveleen, shooterPositionvijf, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*laserkogelvijf, shooterPositionvijf);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogelvijf->spriteLaserKogeltwee);
                                laserkogelvijf->update(); //niet nuttig denk ik denk ik
                            }
                            if (ZLshootPosition)
                            {
                                drawSpriteIfVisible::drawSpriteVisible(window, laserplaats->spritelaserleveleen, shooterPositionzes, sf::Vector2f(canonplaats->spritecanonleveleen.getLocalBounds().width / 2, canonplaats->spritecanonleveleen.getLocalBounds().height / 2));
                                useWeapon(*laserkogelzes, shooterPositionzes);
                                drawSpriteIfVisibleshoot::drawSpriteVisibleshoot(window, laserkogelzes->spriteLaserKogeltwee);
                                laserkogelzes->update(); //niet nuttig denk ik denk ik
                            }
                        }

                        updaterotation.updateShooterRotation(canonplaats, snel, 0);
                        updaterotation.updateShooterRotation(canonplaatstwee, snel, 0);
                        updaterotation.updateShooterRotation(canonplaatsdrie, snel, 0);
                        updaterotation.updateShooterRotation(canonplaatsvier, snel, 0);
                        updaterotation.updateShooterRotation(canonplaatsvijf, snel, 0);
                        updaterotation.updateShooterRotation(canonplaatszes, snel, 0);

                        if (spriteVisibleG)
                        {
                            updateEnemies();
                        }
                        // updateEnemiestwee();

                        updateHandleIntersectionAndDamage();

                        updatehealthBar();                
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

std::cout << "The health is " << redhealthBar_een_copy.getCurrentHealth() << endl; //String class
std::cout << "The health is " << redhealthBar_twee_copy.getCurrentHealth() << endl; //String class

Volgende Stap:

- laser zelfde doen als canon
- rotation weapon zie vorige code
- rotation fire
- inline float -> int //goldDouble.addMoney(0.1);

*/