#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace Towerdefense
{
    class TextureManager
    {
    public:
        //OpeningScreen
        sf::Texture* textureAchtergrond;
        sf::Sprite* spriteAchtergrond;

        //PlayButton
        sf::Texture* texturePlayButton;
        sf::Sprite* spritePlayButton;

        //PauseButton
        sf::Texture* texturePauseButton;
        sf::Sprite* spritePauseButton;

        //PauseButton
        sf::Texture* textureOptionButton;
        sf::Sprite* spriteOptionButton;

        //--------------------------------------------------------
        //ShopeenButton
        sf::Texture* textureShopeenButton;
        sf::Sprite* spriteShopeenButton;

        //ShopeenButton
        sf::Texture* textureShopeenBlueButton;
        sf::Sprite* spriteShopeenBlueButton;

        //SelleenButton
        sf::Texture* textureSelleenButton;
        sf::Sprite* spriteSelleenButton;
        //--------------------------------------------------------
        //ShoptweeButton
        sf::Texture* textureShoptweeButton;
        sf::Sprite* spriteShoptweeButton;

        //ShoptweeButton
        sf::Texture* textureShoptweeBlueButton;
        sf::Sprite* spriteShoptweeBlueButton;

        //SelltweeButton
        sf::Texture* textureSelltweeButton;
        sf::Sprite* spriteSelltweeButton;
        //--------------------------------------------------------
        //ShopdrieButton
        sf::Texture* textureShopdrieButton;
        sf::Sprite* spriteShopdrieButton;

        //ShopdrieButton
        sf::Texture* textureShopdrieBlueButton;
        sf::Sprite* spriteShopdrieBlueButton;

        //SelldrieButton
        sf::Texture* textureSelldrieButton;
        sf::Sprite* spriteSelldrieButton;
        //--------------------------------------------------------
        //ShopvierButton
        sf::Texture* textureShopvierButton;
        sf::Sprite* spriteShopvierButton;

        //ShopeenButton
        sf::Texture* textureShopvierBlueButton;
        sf::Sprite* spriteShopvierBlueButton;

        //SelleenButton
        sf::Texture* textureSellvierButton;
        sf::Sprite* spriteSellvierButton;
        //--------------------------------------------------------
        //ShopvijfButton
        sf::Texture* textureShopvijfButton;
        sf::Sprite* spriteShopvijfButton;

        //ShopvijfButton
        sf::Texture* textureShopvijfBlueButton;
        sf::Sprite* spriteShopvijfBlueButton;

        //SellvijfButton
        sf::Texture* textureSellvijfButton;
        sf::Sprite* spriteSellvijfButton;
        //--------------------------------------------------------
        //ShopzesButton
        sf::Texture* textureShopzesButton;
        sf::Sprite* spriteShopzesButton;

        //ShopzesButton
        sf::Texture* textureShopzesBlueButton;
        sf::Sprite* spriteShopzesBlueButton;

        //SellzesButton
        sf::Texture* textureSellzesButton;
        sf::Sprite* spriteSellzesButton;
        //--------------------------------------------------------

        //EnemyOne
        sf::Texture textureEnemy;
        sf::Sprite spriteEnemy;

        //Rol met wapens
        sf::Texture* textureRolwapens;
        sf::Sprite* spriteRolwapens;

        //Kasteel
        sf::Texture* texturecastle;
        sf::Sprite* spritecastle;

        //Canon level 1
        sf::Texture texturecanonleveleen;
        sf::Sprite spritecanonleveleen;

        sf::Texture textureKogelCanon;
        sf::Sprite spriteKogelCanon;

        //Tower_een
        sf::Texture* texturetowereen;
        sf::Sprite* spritetowereen;

        //Tower_twee
        sf::Texture* texturetowertwee;
        sf::Sprite* spritetowertwee;

        //Tower_drie
        sf::Texture* texturetowerdrie;
        sf::Sprite* spritetowerdrie;

        //Tower_vier
        sf::Texture* texturetowervier;
        sf::Sprite* spritetowervier;

        //Tower_vijf
        sf::Texture* texturetowervijf;
        sf::Sprite* spritetowervijf;

        //Tower_zes
        sf::Texture* texturetowerzes;
        sf::Sprite* spritetowerzes;

        sf::Texture textureKogelLaser;
        sf::Sprite spriteKogelLaser;

        //Laser level 1
        sf::Texture texturelaserleveleen;
        sf::Sprite spritelaserleveleen;

        //Title
        sf::Texture* texturepaperopenmenu;
        sf::Sprite* spritepaperopenmenu;

        //OpeningScreen
        sf::Texture* textureGameopenmenu;
        sf::Sprite* spriteGameopenmenu;

        //Playbutton
        sf::Texture* textureplaybuttonmenu;
        sf::Sprite* spriteplaybuttonmenu;

        //Option
        sf::Texture* textureoptionbuttonmenu;
        sf::Sprite* spriteoptionbuttonmenu;

        //Towerdefensetext
        sf::Texture* texturetowerdefensetextmenu;
        sf::Sprite* spritetowerdefensetextmenu;

        //Towerdefensetextmenueen
        sf::Texture* texturetowerdefensetextmenueen;
        sf::Sprite* spritetowerdefensetextmenueen;

        //Towerdefensetextmenutwee
        sf::Texture* texturetowerdefensetextmenutwee;
        sf::Sprite* spritetowerdefensetextmenutwee;

        //Towerdefensetextmenudrie
        sf::Texture* texturetowerdefensetextmenudrie;
        sf::Sprite* spritetowerdefensetextmenudrie;

        //Towerdefensetextmenuvier
        sf::Texture* texturetowerdefensetextmenuvier;
        sf::Sprite* spritetowerdefensetextmenuvier;

        //Towerdefensetextmenuvijf
        sf::Texture* texturetowerdefensetextmenuvijf;
        sf::Sprite* spritetowerdefensetextmenuvijf;

        TextureManager();//constructor
        ~TextureManager(); //destructor

    };
}
#endif 
