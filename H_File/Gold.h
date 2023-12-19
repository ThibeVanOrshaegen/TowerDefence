#ifndef GOLD_H
#define GOLD_H

#include <SFML/Graphics.hpp>

namespace Towerdefense
{
    class Gold
    {
    public:
        virtual ~Gold() = default;

        // Provide concrete implementations for pure virtual functions
        virtual int sum(int getaleen, int getaltwee) = 0;
        virtual int subtract(int getaleen, int getaltwee) = 0;
        
    };
}
#endif
