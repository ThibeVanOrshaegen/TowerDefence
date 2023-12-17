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

} // namespace Towerdefense

#endif

