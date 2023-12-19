#include "MouseEventHandler.h"

namespace Towerdefense {

    MouseEventHandler::MouseEventHandler(TextureManager& textureManager) : textureManager(textureManager) {
    }

    // Static member variable definitions for button states
    bool Towerdefense::MouseEventHandler::Play = false;
    bool Towerdefense::MouseEventHandler::Stop = false;

    bool Towerdefense::MouseEventHandler::Selleen = false;
    bool Towerdefense::MouseEventHandler::BuyBlue = false;
    bool Towerdefense::MouseEventHandler::BuyRed = false;

    bool MouseEventHandler::Selltwee = false;
    bool MouseEventHandler::BuyBluetwee = false;
    bool MouseEventHandler::BuyRedtwee = false;

    bool MouseEventHandler::Selldrie = false;
    bool MouseEventHandler::BuyBluedrie = false;
    bool MouseEventHandler::BuyReddrie = false;

    bool MouseEventHandler::Sellvier = false;
    bool MouseEventHandler::BuyBluevier = false;
    bool MouseEventHandler::BuyRedvier = false;

    bool MouseEventHandler::Sellvijf = false;
    bool MouseEventHandler::BuyBluevijf = false;
    bool MouseEventHandler::BuyRedvijf = false;

    bool MouseEventHandler::Sellzes = false;
    bool MouseEventHandler::BuyBluezes = false;
    bool MouseEventHandler::BuyRedzes = false;


    bool MouseEventHandler::handleMouseClick(const sf::Event& event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                // Check if the Play button is clicked
                if (mousePosition.x >= textureManager.spritePlayButton->getPosition().x &&
                    mousePosition.x <= textureManager.spritePlayButton->getPosition().x + textureManager.spritePlayButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spritePlayButton->getPosition().y &&
                    mousePosition.y <= textureManager.spritePlayButton->getPosition().y + textureManager.spritePlayButton->getGlobalBounds().height) {
                    Play = true;
                    Stop = false;  // Reset stop flag
                }

                if (mousePosition.x >= textureManager.spritePauseButton->getPosition().x &&
                    mousePosition.x <= textureManager.spritePauseButton->getPosition().x + textureManager.spritePauseButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spritePauseButton->getPosition().y &&
                    mousePosition.y <= textureManager.spritePauseButton->getPosition().y + textureManager.spritePauseButton->getGlobalBounds().height) {
                    Stop = true;
                    Play = false;  // Reset play flag
                }

                if (mousePosition.x >= textureManager.spriteOptionButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteOptionButton->getPosition().x + textureManager.spriteOptionButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteOptionButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteOptionButton->getPosition().y + textureManager.spriteOptionButton->getGlobalBounds().height) {
                    return true;
                }
                //--------------------------------------------------------
                if (mousePosition.x >= textureManager.spriteSelleenButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteSelleenButton->getPosition().x + textureManager.spriteSelleenButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteSelleenButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteSelleenButton->getPosition().y + textureManager.spriteSelleenButton->getGlobalBounds().height) {
                    Selleen = true;
                    BuyBlue = false;
                    BuyRed = false;
                }

                if (mousePosition.x >= textureManager.spriteShopeenBlueButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopeenBlueButton->getPosition().x + textureManager.spriteShopeenBlueButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopeenBlueButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopeenBlueButton->getPosition().y + textureManager.spriteShopeenBlueButton->getGlobalBounds().height) {
                    BuyBlue = true;
                    
                }

                if (mousePosition.x >= textureManager.spriteShopeenButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopeenButton->getPosition().x + textureManager.spriteShopeenButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopeenButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopeenButton->getPosition().y + textureManager.spriteShopeenButton->getGlobalBounds().height) {
                    BuyRed = true;
                }
                //--------------------------------------------------------
                if (mousePosition.x >= textureManager.spriteSelltweeButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteSelltweeButton->getPosition().x + textureManager.spriteSelltweeButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteSelltweeButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteSelltweeButton->getPosition().y + textureManager.spriteSelltweeButton->getGlobalBounds().height) {
                    Selltwee = true;
                    BuyBluetwee = false;
                    BuyRedtwee = false;
                }

                if (mousePosition.x >= textureManager.spriteShoptweeBlueButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShoptweeBlueButton->getPosition().x + textureManager.spriteShoptweeBlueButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShoptweeBlueButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShoptweeBlueButton->getPosition().y + textureManager.spriteShoptweeBlueButton->getGlobalBounds().height) {
                    BuyBluetwee = true;

                }

                if (mousePosition.x >= textureManager.spriteShoptweeButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShoptweeButton->getPosition().x + textureManager.spriteShoptweeButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShoptweeButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShoptweeButton->getPosition().y + textureManager.spriteShoptweeButton->getGlobalBounds().height) {
                    BuyRedtwee = true;
                }
                //--------------------------------------------------------
                if (mousePosition.x >= textureManager.spriteSelldrieButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteSelldrieButton->getPosition().x + textureManager.spriteSelldrieButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteSelldrieButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteSelldrieButton->getPosition().y + textureManager.spriteSelldrieButton->getGlobalBounds().height) {
                    Selldrie = true;
                    BuyBluedrie = false;
                    BuyReddrie = false;
                }

                if (mousePosition.x >= textureManager.spriteShopdrieBlueButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopdrieBlueButton->getPosition().x + textureManager.spriteShopdrieBlueButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopdrieBlueButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopdrieBlueButton->getPosition().y + textureManager.spriteShopdrieBlueButton->getGlobalBounds().height) {
                    BuyBluedrie = true;

                }

                if (mousePosition.x >= textureManager.spriteShopdrieButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopdrieButton->getPosition().x + textureManager.spriteShopdrieButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopdrieButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopdrieButton->getPosition().y + textureManager.spriteShopdrieButton->getGlobalBounds().height) {
                    BuyReddrie = true;
                }
                //--------------------------------------------------------
                if (mousePosition.x >= textureManager.spriteSellvierButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteSellvierButton->getPosition().x + textureManager.spriteSellvierButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteSellvierButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteSellvierButton->getPosition().y + textureManager.spriteSellvierButton->getGlobalBounds().height) {
                    Sellvier = true;
                    BuyBluevier = false;
                    BuyRedvier = false;
                }

                if (mousePosition.x >= textureManager.spriteShopvierBlueButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopvierBlueButton->getPosition().x + textureManager.spriteShopvierBlueButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopvierBlueButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopvierBlueButton->getPosition().y + textureManager.spriteShopvierBlueButton->getGlobalBounds().height) {
                    BuyBluevier = true;

                }

                if (mousePosition.x >= textureManager.spriteShopvierButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopvierButton->getPosition().x + textureManager.spriteShopvierButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopvierButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopvierButton->getPosition().y + textureManager.spriteShopvierButton->getGlobalBounds().height) {
                    BuyRedvier = true;
                }
                //--------------------------------------------------------
                if (mousePosition.x >= textureManager.spriteSellvijfButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteSellvijfButton->getPosition().x + textureManager.spriteSellvijfButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteSellvijfButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteSellvijfButton->getPosition().y + textureManager.spriteSellvijfButton->getGlobalBounds().height) {
                    Sellvijf = true;
                    BuyBluevijf = false;
                    BuyRedvijf = false;
                }

                if (mousePosition.x >= textureManager.spriteShopvijfBlueButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopvijfBlueButton->getPosition().x + textureManager.spriteShopvijfBlueButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopvijfBlueButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopvijfBlueButton->getPosition().y + textureManager.spriteShopvijfBlueButton->getGlobalBounds().height) {
                    BuyBluevijf = true;

                }

                if (mousePosition.x >= textureManager.spriteShopvijfButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopvijfButton->getPosition().x + textureManager.spriteShopvijfButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopvijfButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopvijfButton->getPosition().y + textureManager.spriteShopvijfButton->getGlobalBounds().height) {
                    BuyRedvijf = true;
                }
                //--------------------------------------------------------
                if (mousePosition.x >= textureManager.spriteSellzesButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteSellzesButton->getPosition().x + textureManager.spriteSellzesButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteSellzesButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteSellzesButton->getPosition().y + textureManager.spriteSellzesButton->getGlobalBounds().height) {
                    Sellzes = true;
                    BuyBluezes = false;
                    BuyRedzes = false;
                }

                if (mousePosition.x >= textureManager.spriteShopzesBlueButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopzesBlueButton->getPosition().x + textureManager.spriteShopzesBlueButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopzesBlueButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopzesBlueButton->getPosition().y + textureManager.spriteShopzesBlueButton->getGlobalBounds().height) {
                    BuyBluezes = true;

                }

                if (mousePosition.x >= textureManager.spriteShopzesButton->getPosition().x &&
                    mousePosition.x <= textureManager.spriteShopzesButton->getPosition().x + textureManager.spriteShopzesButton->getGlobalBounds().width &&
                    mousePosition.y >= textureManager.spriteShopzesButton->getPosition().y &&
                    mousePosition.y <= textureManager.spriteShopzesButton->getPosition().y + textureManager.spriteShopzesButton->getGlobalBounds().height) {
                    BuyRedzes = true;
                }
                //--------------------------------------------------------
            }
        }
        return false; // No button clicked
    }

}
