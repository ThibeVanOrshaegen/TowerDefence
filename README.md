# Algemeen

- [ ] clean main (i.e. nothing in the main that should be in a class)
- [ ] no globals, but statics if needed
- [ ] correct protections
- [ ] maintainability by clean uniform code style and good function naming and/or comments everywhere
- [X] separate header files

![image](https://github.com/ThibeVanOrshaegen/OOPFiles/assets/114075982/43263220-b49d-4729-85e8-da905d2316b6)

- [ ] one complete project that compiles and does not crash
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
- [ ] member initialization in constructors (the stuff behind a colon)
```cpp

```
- [ ] constructor forwarding
```cpp

```
- [ ] useful proven (dynamic) polymorphism
```cpp

```
- [ ] useful usage of "this" (if the code does not work without it)
```cpp

```
- [ ] useful member function
```cpp

```
- [ ] default values in function definition
```cpp

```
- [ ] useful member variabel
```cpp

```
- [ ] useful getters and setters for member variables
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
- [ ] everything in one or more self-made namespace(s)
```cpp

```
- [ ] 2 useful unsigned chars or other better usage of memory efficient type
```cpp

```
- [ ] at least 4 useful const references for variables
```cpp

```
- [ ] at least 4 useful const references for functions
```cpp

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
- [ ] dynamic memory allocation (new)
```cpp

```
- [ ] dynamic memory removing (delete)
```cpp

```
- [ ] 2 useful (modern) call-by-references
```cpp

```
- [ ] useful string class usage
```cpp

```
- [ ] useful container class
```cpp

```
- [ ] useful usage of nullptr

      
- [ ] useful usage of (modern) file-I/O
```cpp

```
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
- [ ] usage of a GUI
- [ ] usage of OpenGL or other 3D engine
- [ ] useful usage of an external library (not Qt)
- [ ] project that communicates (e.g. UART, BT) with hardware
a nice extra that you think that should deserve grading (stuff you put time in and is not rewarded by an item above)
