# Algemeen

- [ ] clean main (i.e. nothing in the main that should be in a class)
- [ ] no globals, but statics if needed
- [ ] correct protections
- [ ] maintainability by clean uniform code style and good function naming and/or comments everywhere
- [ ] separate header files
- [ ] one complete project that compiles and does not crash
- [ ] fully working project
- [ ] sufficient git commits (+/- weekly)
- [ ] correct files on git
- [ ] working build manual as readme on GitHub (project must be possible to build from scratch on a clean PC)
# OOP
- [ ] at least 2 default constructors
- [ ] at least 2 parameterized constructors
- [ ] at least 2 copy constructors
- [ ] at least 2 destructors
- [ ] member initialization in constructors (the stuff behind a colon)
- [ ] constructor forwarding
- [ ] useful proven (dynamic) polymorphism
- [ ] useful usage of "this" (if the code does not work without it)
- [ ] useful member function
- [ ] default values in function definition
- [ ] useful member variabel
- [ ] useful getters and setters for member variables
- [ ] correct usage of inline function
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
- [ ] useful template function or class
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
- [ ] useful friend function or class
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
- [ ] 2 useful unsigned chars or other better usage of memory efficient type
- [ ] at least 4 useful const references for variables
- [ ] at least 4 useful const references for functions
- [ ] at least 4 useful bool
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
- [ ] dynamic memory removing (delete)
- [ ] 2 useful (modern) call-by-references
- [ ] useful string class usage
- [ ] useful container class
- [ ] useful usage of nullptr

      
- [ ] useful usage of (modern) file-I/O
- [ ] useful exception handling

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
- [ ] useful usage of lambda function
- [ ] useful usage of threads
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
