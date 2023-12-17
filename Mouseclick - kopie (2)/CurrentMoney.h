// CurrentMoney.h
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
