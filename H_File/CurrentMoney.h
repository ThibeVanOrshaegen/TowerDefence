#ifndef CURRENT_MONEY_H
#define CURRENT_MONEY_H

#include "TextureManager.h"
#include "Gold.h"
#include "Game.h"

namespace Towerdefense
{
    // Forward declaration of the Game class
    class Game;

    // CurrentMoney class inherits from Gold class
    class CurrentMoney : public Gold
    {
    private:
        // TextureManager object for handling textures
        TextureManager textureManager;

        // Private constructor to initialize CurrentMoney with default values
        CurrentMoney() : currentmoney() {}

        // Constructor with an optional initial amount of gold
        CurrentMoney(int currentgold = 10);

        // Override functions for sum and subtract operations
        int sum(int getaleen, int getaltwee) override;
        int subtract(int getaleen, int getaltwee) override;

        // Granting friendship to the Game class to access private members
        friend class Game;

        // Private member variable to store the current amount of money
        int currentmoney;

    public:
        // Public method to get the current amount of money
        const int& getCurrentMoney() const { return currentmoney; }
    };
}
#endif
