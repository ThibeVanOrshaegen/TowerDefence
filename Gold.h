#ifndef GOLD_H
#define GOLD_H

#include <SFML/Graphics.hpp>
namespace Towerdefense
{

    template <typename T>

    class Gold
    {
    public:
        T currentGold = 10;

        Gold(T maxGold);

        void addMoney(T amount);
        void subtractMoney(T amount);

        inline T add(T a, T b);
        inline T subtract(T a, T b);

        T getCurrentGold() const;

    private:
        
        void setCurrentGold(T gold);
        
        friend class EnemyOne; //friend class
        friend class Wave; //friend class
        friend class Gold;
    };
}
#endif

