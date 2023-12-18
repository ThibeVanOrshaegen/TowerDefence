# Algemeen

- [X] clean main (i.e. nothing in the main that should be in a class)
```cpp
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace Towerdefense;
int main() {
    sf::RenderWindow window(sf::VideoMode(1180, 720), "My Program");
    Game game;
    game.run(window);
    return 0;
}

```
- [X] no globals, but statics if needed
```cpp
#ifndef MOUSE_EVENT_HANDLER_H
#define MOUSE_EVENT_HANDLER_H

#include <SFML/Graphics.hpp>
#include "TextureManager.h"

namespace Towerdefense {

    class MouseEventHandler {
    public:
        MouseEventHandler(TextureManager& textureManager);

        bool handleMouseClick(const sf::Event& event, sf::RenderWindow& window);

        bool getPlay() const { return Play; }
        bool getStop() const { return Stop; }
        bool getSelleen() const { return Selleen; }
        bool getBuyBlue() const { return BuyBlue; }
        bool getBuyRed() const { return BuyRed; }

        bool getSelltwee() const { return Selltwee; }
        bool getBuyBluetwee() const { return BuyBluetwee; }
        bool getBuyRedtwee() const { return BuyRedtwee; }

        bool getSelldrie() const { return Selldrie; }
        bool getBuyBluedrie() const { return BuyBluedrie; }
        bool getBuyReddrie() const { return BuyReddrie; }

        bool getSellvier() const { return Sellvier; }
        bool getBuyBluevier() const { return BuyBluevier; }
        bool getBuyRedvier() const { return BuyRedvier; }

        bool getSellvijf() const { return Sellvijf; }
        bool getBuyBluevijf() const { return BuyBluevijf; }
        bool getBuyRedvijf() const { return BuyRedvijf; }

        bool getSellzes() const { return Sellzes; }
        bool getBuyBluezes() const { return BuyBluezes; }
        bool getBuyRedzes() const { return BuyRedzes; }

        //all the member functions listed are const member functions, and they return values that are not modifiable


    private:

        TextureManager& textureManager;

        static bool Play;
        static bool Stop;
        static bool Selleen;
        static bool BuyBlue;
        static bool BuyRed;

        static bool Selltwee;
        static bool BuyBluetwee;
        static bool BuyRedtwee;

        static bool Selldrie;
        static bool BuyBluedrie;
        static bool BuyReddrie;

        static bool Sellvier;
        static bool BuyBluevier;
        static bool BuyRedvier;

        static bool Sellvijf;
        static bool BuyBluevijf;
        static bool BuyRedvijf;

        static bool Sellzes;
        static bool BuyBluezes;
        static bool BuyRedzes;  
    };
} 
#endif
```
- [ ] correct protections
- [ ] maintainability by clean uniform code style and good function naming and/or comments everywhere
- [X] separate header files

![image](https://github.com/ThibeVanOrshaegen/OOPFiles/assets/114075982/43263220-b49d-4729-85e8-da905d2316b6)

- [X] one complete project that compiles and does not crash
- [ ] fully working project
- [ ] sufficient git commits (+/- weekly)
- [ ] correct files on git
- [ ] working build manual as readme on GitHub (project must be possible to build from scratch on a clean PC)
# OOP
- [X] at least 2 default constructors
```cpp

Canon::Canon() : spritecanonleveleen(), Canonposition(sf::Vector2f(0, 0)) {...}

Beweging::Beweging() : xVelocity(0.0f), yVelocity(0.0f), originalYVelocity(0.0f) {...}

```
- [X] at least 2 parameterized constructors
```cpp
Beweging::Beweging(float xVel, float yVel) : xVelocity(xVel), yVelocity(yVel), originalYVelocity(yVel) {}

Canon::Canon(sf::Vector2f initialPosition) : spritecanonleveleen(), Canonposition(initialPosition) {..}
```
- [X] at least 2 copy constructors
```cpp
Enemy::Enemy(const Enemy& other)
    : HealthBar(other),  // Call base class copy constructor
      textureManager(other.textureManager),
      beweging(other.beweging),
      spriteEnemy(other.spriteEnemy) {...}

HealthBar::HealthBar(const HealthBar& other)
    : maxHealth(other.maxHealth), currentHealth(other.currentHealth){...}
```
- [X] at least 2 destructors
```cpp
~Game();
 Game::~Game()
 {
     delete snel;
     delete traag;
     delete currentmoneyklein;
 }

~TextureManager();
 TextureManager::~TextureManager()
 {
     // Cleanup
     delete textureAchtergrond;
     delete spriteAchtergrond;

     delete texturePlayButton;
     delete spritePlayButton;

     delete texturePauseButton;
     delete spritePauseButton;

     delete textureOptionButton;
     delete spriteOptionButton;

     delete texturecastle;
     delete spritecastle;

     delete texturetowereen;
     delete spritetowereen;

     delete texturetowertwee;
     delete spritetowertwee;

     delete texturetowerdrie;
     delete spritetowerdrie;

     delete texturetowervier;
     delete spritetowervier;

     delete texturetowervijf;
     delete spritetowervijf;

     delete texturetowerzes;
     delete spritetowerzes;
 }

```
- [X] member initialization in constructors (the stuff behind a colon)
```cpp
Canonshooting::Canonshooting() : spriteCanonKogeltwee(), arrowPosition(sf::Vector2f(0, 0)), direction(sf::Vector2f(-1, -1)) {...}
//spriteCanonKogeltwee: This member is default-constructed using its default constructor.
//arrowPosition: This member is initialized with sf::Vector2f(0, 0).
//direction: This member is initialized with sf::Vector2f(-1, -1).
```
- [X] constructor forwarding
```cpp
 HealthBar::HealthBar(sf::Vector2f enemyPosition, sf::Vector2f size, unsigned char maxHealth) // primary constructor, Takes parameters enemyPosition, size, and maxHealth, a parameterized constructor.
     : currentHealth(maxHealth)
     //currentHealth member variable with the value of maxHealth that is passed as a parameter to the constructor
 {
     bar.setPosition(enemyPosition.x, enemyPosition.y - 20);
     bar.setSize(size);
     bar.setFillColor(sf::Color::Red);
 }
```
- [X] useful proven (dynamic) polymorphism
```cpp
#ifndef WEAPONS_H
#define WEAPONS_H

#include <SFML/Graphics.hpp>
namespace Towerdefense
{
    class Weapon {
    public:
        virtual ~Weapon() = default;
        virtual void fire(sf::Vector2f& shooterPosition,float limit_one, float limit_two, float limit_three, float limit_four) = 0; //polymorfisme
        virtual void update(float directionX, float directionY) = 0;
    };
}
#endif

#ifndef CANON_POSITION_H
#define CANON_POSITION_H

#include "Weapon.h"
#include "TextureManager.h"
#include "Enemy.h"

namespace Towerdefense
{
    class Canonshooting : public Weapon {
    private:
        sf::Vector2f arrowPosition;
        TextureManager textureManager;
        sf::Vector2f direction;
        const unsigned char arrowSpeed = 20;

    public:
        sf::Sprite spriteCanonKogeltwee;

        Canonshooting();
        Canonshooting(const sf::Vector2f& initialPosition);
        void fire(sf::Vector2f& shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four) override;
        void update(float directionX, float directionY) override;
        void updateprobeer();
    };
}
#endif

#ifndef CANON_H
#define CANON_H

#include "Weapon.h"
#include "TextureManager.h"
#include "Canonshooting.h"
#include "Enemy.h"

namespace Towerdefense
{
    class Canon : public Canonshooting {
    private:
        sf::Vector2f Canonposition;
        TextureManager textureManager;

    public:

        sf::Sprite spritecanonleveleen;

        Canon(sf::Vector2f initialPosition);

        // Default constructor
        Canon();
    };
}
#endif

//Canon
 if (snel->spriteEnemy.getPosition().x < canonplaatstwee->spritecanonleveleen.getPosition().x && snel->spriteEnemy.getPosition().y < canonplaatstwee->spritecanonleveleen.getPosition().y)
 {
     sf::Vector2f direction(-1.0f, -1.0f);  // move right
     canonkogeltwee->update(direction.x, direction.y);
     canonkogeltwee->fire(shooterPositiontwee,1080,600,0,0);
 }

//Laser
if (traag->spriteEnemy.getPosition().x < laserplaatstwee->spritelaserleveleen.getPosition().x && traag->spriteEnemy.getPosition().y < laserplaatstwee->spritelaserleveleen.getPosition().y)
{
    sf::Vector2f direction(-1.0f, -1.0f);  // move right
    laserkogeltwee->update(direction.x, direction.y);
    laserkogeltwee->fire(shooterPositiontwee, 1080, 600, 0, 0);
}

```
- [ ] useful usage of "this" (if the code does not work without it)
```cpp

```
- [X] useful member function
```cpp
#ifndef CANON_POSITION_H
#define CANON_POSITION_H

#include "Weapon.h"
#include "TextureManager.h"
#include "Enemy.h"

namespace Towerdefense
{
    class Canonshooting : public Weapon {
    private:
        sf::Vector2f arrowPosition;
        TextureManager textureManager;
        sf::Vector2f direction;
        const unsigned char arrowSpeed = 20;

    public:
        sf::Sprite spriteCanonKogeltwee;

        Canonshooting();
        Canonshooting(const sf::Vector2f& initialPosition);
        void fire(sf::Vector2f& shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four) override;
        void update(float directionX, float directionY) override;
        void updateprobeer();
    };
}
#endif

void Canonshooting::update(float directionX, float directionY)
{   direction.x = directionX;
    direction.y = directionY;
    spriteCanonKogeltwee.move(direction.x * arrowSpeed, direction.y * arrowSpeed);
}

 if (spriteBuybluedrie)
 {
     
  drawSpriteIfVisible::drawSpriteVisible(window, canonplaats->spritecanonleveleen, shooterPosition, sf::Vector2f(canon.spritecanonleveleen.getLocalBounds().width / 2, 
  canon.spritecanonleveleen.getLocalBounds().height / 2));
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
}

```
- [X] default values in function definition ~
```cpp
    Beweging::Beweging() : xVelocity(0.0f), yVelocity(0.0f), originalYVelocity(0.0f) {}

    Beweging::Beweging(float xVel, float yVel) : xVelocity(xVel), yVelocity(yVel), originalYVelocity(yVel) {} 

    //Here, 0.0f is used as the default value for xVelocity, yVelocity, and originalYVelocity in the default constructor

```
- [X] useful member variabel
```cpp
healthBar_een
redhealthBar_een_copy
healthBar_twee
redhealthBar_twee_copy
currentmoneyklein
snel
traag
canonkogel
canonkogeltwee
canonkogeldrie
canonkogelvier
canonkogelvijf
canonkogelzes
canonplaats
canonplaatstwee
canonplaatsdrie
canonplaatsvier
canonplaatsvijf
canonplaatszes
laserkogel
laserkogeltwee
laserkogeldrie
laserkogelvier
laserkogelvijf
laserkogelzes
laserplaats
laserplaatstwee
laserplaatsdrie
laserplaatsvier
laserplaatsvijf
laserplaatszes
```
- [X] useful getters and setters for member variables
```cpp
#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SFML/Graphics.hpp>

namespace Towerdefense
{
    class HealthBar
    {
    public:
        sf::RectangleShape bar; 
        sf::Vector2f position;
        int maxHealth = 100; //usefull member variabel
        int currentHealth = 10; //usefull member variabel

        HealthBar(sf::Vector2f enemyPosition, sf::Vector2f size, int maxHealth);
        HealthBar(const HealthBar& other);// const refernces for function

        sf::RectangleShape getBar() const;
        sf::Vector2f getPosition() const;

        int getMaxHealth() const;
        int getCurrentHealth() const;

        void setBar(const sf::RectangleShape& newBar);
        void setPosition(const sf::Vector2f& newPosition);
        void setMaxHealth(int newMaxHealth);
        void setCurrentHealth(int newCurrentHealth);

        void applyDamage();
        void subtractHealth(int amountofdamage);

        void updatePositionHealth(const sf::Vector2f& newPosition);
    };
}
#endif

    int HealthBar::getMaxHealth() const 
    {
        return maxHealth;
    }

    int HealthBar::getCurrentHealth() const 
    {
        return currentHealth;
    }

    // Setter implementations
    void HealthBar::setBar(const sf::RectangleShape& newBar)
    {
        bar = newBar;
    }

    void HealthBar::setPosition(const sf::Vector2f& newPosition)
    {
        position = newPosition;
    }

    void HealthBar::setMaxHealth(int newMaxHealth)
    {
        maxHealth = newMaxHealth;
    }

    void HealthBar::setCurrentHealth(int newCurrentHealth)
    {
        currentHealth = newCurrentHealth;
    }


```
- [X] correct usage of inline function
```cpp

    inline int CurrentMoney::sum(int getaleen, int getaltwee)
    {
        try
        {
            currentmoney = getaleen + getaltwee;
            if (currentmoney < 0)  
            {
                
                throw std::out_of_range("Result is negative");
            }
            return currentmoney;
        }
        catch (const std::exception& e)
        {
            std::ofstream errorFile("error_log.txt", std::ios_base::app);
            if (errorFile.is_open())
            {
                errorFile << "Exception caught while initializing the game: " << e.what() << std::endl;
                
                errorFile.close();
            }
            else
            {
                std::cerr << "Failed to open the error log file!" << std::endl;
            }
            throw;
        }
    }
    inline int CurrentMoney::subtract(int getaleen, int getaltwee)
    {
        currentmoney = getaleen - getaltwee;
        return currentmoney;
    }
``` 
- [X] useful template function or class
```cpp  
template <typename T>
void swap(T& x, T& y) {
    T temp;
    temp = x;
    x = y;
    y = temp;

    return;
}
``` 
- [X] useful friend function or class
```cpp  
#ifndef CURRENT_MONEY_H
#define CURRENT_MONEY_H

#include "TextureManager.h"
#include "Gold.h"
#include "Game.h"

namespace Towerdefense
{
    class Game;
    class CurrentMoney : public Gold
    {
    private:
        TextureManager textureManager;
        CurrentMoney(int currentgold = 10);
        CurrentMoney() : currentmoney(), add() {}
        int sum(int getaleen, int getaltwee) override;
        int subtract(int getaleen, int getaltwee) override;
        int add;

        friend class Game;

        int currentmoney;
    public:
        
        const int& getCurrentMoney() const { return currentmoney; }
    };
}
#endif
```     
# C++
- [X] everything in one or more self-made namespace(s)
```cpp
namespace Towerdefense
{...}
```
- [X] 2 useful unsigned chars or other better usage of memory efficient type
```cpp
 unsigned char moneyIncrement = 1;
 unsigned char moneyDecrement = 2;
 unsigned char nextmoneyIncrement;
```
- [ ] at least 4 useful const references for variables
```cpp
const int& getCurrentMoney() const { return currentmoney; }

```
- [X] at least 4 useful const references for functions
```cpp
bool getPlay() const { return Play; }
bool getStop() const { return Stop; }
bool getSelleen() const { return Selleen; }
bool getBuyBlue() const { return BuyBlue; }
bool getBuyRed() const { return BuyRed; }

bool getSelltwee() const { return Selltwee; }
bool getBuyBluetwee() const { return BuyBluetwee; }
bool getBuyRedtwee() const { return BuyRedtwee; }

bool getSelldrie() const { return Selldrie; }
bool getBuyBluedrie() const { return BuyBluedrie; }
bool getBuyReddrie() const { return BuyReddrie; }

bool getSellvier() const { return Sellvier; }
bool getBuyBluevier() const { return BuyBluevier; }
bool getBuyRedvier() const { return BuyRedvier; }

bool getSellvijf() const { return Sellvijf; }
bool getBuyBluevijf() const { return BuyBluevijf; }
bool getBuyRedvijf() const { return BuyRedvijf; }

bool getSellzes() const { return Sellzes; }
bool getBuyBluezes() const { return BuyBluezes; }
bool getBuyRedzes() const { return BuyRedzes; }

//all the member functions listed are const member functions, and they return values that are not modifiable
```
- [X] at least 4 useful bool
```cpp  
      bool Towerdefense::Game::isPKeyPressed = false;
      bool Towerdefense::Game::spriteVisibleP = false;
      bool Towerdefense::Game::spriteTruePlay = false;
      bool Towerdefense::Game::spriteTruePause = false;

      if (mouseEventHandler.getPlay())
      spriteTruePlay = true;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
      {
        isPKeyPressed = true;
        spriteVisibleP = true;
      }
      else
      {
        isPKeyPressed = false;
      }

      if (spriteVisibleP)
      {
        //if (redhealthBar_een_copy.currentHealth > 40)
        //{
            window.draw(snel->spriteEnemy);

            window.draw(healthBar_een.bar);
            window.draw(redhealthBar_een_copy.bar);
        //}
        //if (redhealthBar_twee_copy.currentHealth > 40)
        //{
            window.draw(traag->spriteEnemy);

            window.draw(healthBar_twee.bar);
            window.draw(redhealthBar_twee_copy.bar);
        //}

        if (spriteTruePlay)
        {
            nextmoneyIncrement = 1;
            swap(moneyIncrement, nextmoneyIncrement);
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
```
- [X] dynamic memory allocation (new)
```cpp
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
```
- [X] dynamic memory removing (delete)
```cpp
Game::~Game()
{
    delete snel;
    delete traag;
    delete currentmoneyklein;
}
```
- [ ] 2 useful (modern) call-by-references
```cpp
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

auto incrementMoney = [this, moneyIncrement]() {
    if (currentmoneyklein != nullptr)
    {
        currentmoneyklein->sum(currentmoneyklein->currentmoney, moneyIncrement);
    }
    };
incrementMoney();

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

```
- [X] useful string class usage
```cpp
if (moneyUpdateTimer.getElapsedTime().asSeconds() >= 3)
{
    std::cout << "Current Money: " << currentmoneyklein->currentmoney << std::endl;
    std::cout << "Level 1" << std::endl;
    std::cout << std::endl;
    moneyUpdateTimer.restart(); // Herstart de timer voor de uitvoer
}
```
- [ ] useful container class
```cpp

```
- [X] useful usage of nullptr
```cpp
auto decrementMoney = [this, moneyDecrement]() {
    if (currentmoneyklein != nullptr)
    {
        currentmoneyklein->subtract(currentmoneyklein->currentmoney, moneyDecrement);
    }
    };
```
      
- [X] useful usage of (modern) file-I/O
- [ ] 
![image](https://github.com/ThibeVanOrshaegen/OOPFiles/assets/114075982/43d846ef-fe29-475b-aa58-6662e73a7359)

- [X] useful exception handling
```cpp
  #include <fstream>
  
    inline int CurrentMoney::sum(int getaleen, int getaltwee)
    {
        try
        {
            currentmoney = getaleen + getaltwee;
            if (currentmoney < 0)  
            {
                
                throw std::out_of_range("Result is negative");
            }
            return currentmoney;
        }
        catch (const std::exception& e)
        {
            std::ofstream errorFile("error_log.txt", std::ios_base::app);
            if (errorFile.is_open())
            {
                errorFile << "Exception caught while initializing the game: " << e.what() << std::endl;
                errorFile.close();
            }
            else
            {
                std::cerr << "Failed to open the error log file!" << std::endl;
            }
            throw;
        }
    }
    inline int CurrentMoney::subtract(int getaleen, int getaltwee)
    {
        currentmoney = getaleen - getaltwee;
        return currentmoney;
    }
```
- [X] useful usage of lambda function
```cpp
 auto incrementMoney = [this, moneyIncrement]() {
     if (currentmoneyklein != nullptr)
     {
         currentmoneyklein->sum(currentmoneyklein->currentmoney, moneyIncrement);
     }
     };
 incrementMoney();
```
- [X] useful usage of threads
```cpp
 std::thread backgroundThread([&]() { backgroundTask(*this); });

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
....
     window.display();
 }
 running = false;
 backgroundThread.join();
void Game::updateEnemies() {

    std::thread snelUpdateThread(&Enemy::updateMoveHealth, snel);
    std::thread traagUpdateThread(&Enemy::updateMoveHealth, traag);

    snelUpdateThread.join();
    traagUpdateThread.join();
}


```

# Uitbreiding
- [ ] useful Qt class
- [ ] useful usage of signals/slots
- [ ] test-driven development (= written test plan or unit tests)
- [ ] solve bug ticket (with pull request or commit message issue link and issue branch)
- [ ] report a bug ticket on another project
- [X] usage of a GUI
```cpp
#include <SFML/Graphics.hpp>
```
- [ ] usage of OpenGL or other 3D engine
- [ ] useful usage of an external library (not Qt)
- [ ] project that communicates (e.g. UART, BT) with hardware
a nice extra that you think that should deserve grading (stuff you put time in and is not rewarded by an item above)
