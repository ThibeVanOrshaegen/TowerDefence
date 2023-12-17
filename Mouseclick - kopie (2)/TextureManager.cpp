#include "TextureManager.h"
#include <memory>


namespace Towerdefense
{
    TextureManager::TextureManager()
    {
        //OpeningScreen
        textureAchtergrond = new sf::Texture();
        spriteAchtergrond = new sf::Sprite();

        textureAchtergrond->loadFromFile("./Afbeelding/plattegrond.png");
        spriteAchtergrond->setTexture(*textureAchtergrond);
        sf::Vector2f AchtergrondPosition(0, 0);
        spriteAchtergrond->setPosition(AchtergrondPosition);
        spriteAchtergrond->setScale(1.0f, 1.0f);

        //PlayButton
        texturePlayButton = new sf::Texture();
        spritePlayButton = new sf::Sprite();

        texturePlayButton->loadFromFile("./Afbeelding/PlayRed.png");
        spritePlayButton->setTexture(*texturePlayButton);
        sf::Vector2f PlayButtonPosition(10, 10);
        spritePlayButton->setPosition(PlayButtonPosition);
        spritePlayButton->setScale(3.0f, 3.0f);

        //PauseButton
        texturePauseButton = new sf::Texture();
        spritePauseButton = new sf::Sprite();

        texturePauseButton->loadFromFile("./Afbeelding/PauseRed.png");
        spritePauseButton->setTexture(*texturePauseButton);
        sf::Vector2f PauseButtonPosition(60, 10);
        spritePauseButton->setPosition(PauseButtonPosition);
        spritePauseButton->setScale(3.0f, 3.0f);
        //-------------------------------------------------------- 37, 270
        //SelleenButton
        textureSelleenButton = new sf::Texture();
        spriteSelleenButton = new sf::Sprite();

        textureSelleenButton->loadFromFile("./Afbeelding/sell.png");
        spriteSelleenButton->setTexture(*textureSelleenButton);
        sf::Vector2f SelleenButtonPosition(20, 225);
        spriteSelleenButton->setPosition(SelleenButtonPosition);
        spriteSelleenButton->setScale(2.0f, 2.0f);

        //ShopeenBlueButton
        textureShopeenBlueButton = new sf::Texture();
        spriteShopeenBlueButton = new sf::Sprite();

        textureShopeenBlueButton->loadFromFile("./Afbeelding/BuyBlue.png");
        spriteShopeenBlueButton->setTexture(*textureShopeenBlueButton);
        sf::Vector2f ShopeenBlueButtonPosition(120, 225);
        spriteShopeenBlueButton->setPosition(ShopeenBlueButtonPosition);
        spriteShopeenBlueButton->setScale(2.0f, 2.0f);

        //ShopeenButton
        textureShopeenButton = new sf::Texture();
        spriteShopeenButton = new sf::Sprite();

        textureShopeenButton->loadFromFile("./Afbeelding/BuyRed.png");
        spriteShopeenButton->setTexture(*textureShopeenButton);
        sf::Vector2f ShopeenButtonPosition(70, 225);
        spriteShopeenButton->setPosition(ShopeenButtonPosition);
        spriteShopeenButton->setScale(2.0f, 2.0f);
        //-------------------------------------------------------- 37, 490 +17,+105
        //SelltweeButton
        textureSelltweeButton = new sf::Texture();
        spriteSelltweeButton = new sf::Sprite();

        textureSelltweeButton->loadFromFile("./Afbeelding/sell.png");
        spriteSelltweeButton->setTexture(*textureSelltweeButton);
        sf::Vector2f SelltweeButtonPosition(20, 595);
        spriteSelltweeButton->setPosition(SelltweeButtonPosition);
        spriteSelltweeButton->setScale(2.0f, 2.0f);

        //ShopeenBlueButton
        textureShoptweeBlueButton = new sf::Texture();
        spriteShoptweeBlueButton = new sf::Sprite();

        textureShoptweeBlueButton->loadFromFile("./Afbeelding/BuyBlue.png");
        spriteShoptweeBlueButton->setTexture(*textureShoptweeBlueButton);
        sf::Vector2f ShoptweeBlueButtonPosition(120, 595);
        spriteShoptweeBlueButton->setPosition(ShoptweeBlueButtonPosition);
        spriteShoptweeBlueButton->setScale(2.0f, 2.0f);

        //ShopeenButton
        textureShoptweeButton = new sf::Texture();
        spriteShoptweeButton = new sf::Sprite();

        textureShoptweeButton->loadFromFile("./Afbeelding/BuyRed.png");
        spriteShoptweeButton->setTexture(*textureShoptweeButton);
        sf::Vector2f ShoptweeButtonPosition(70, 595);
        spriteShoptweeButton->setPosition(ShoptweeButtonPosition);
        spriteShoptweeButton->setScale(2.0f, 2.0f);
        //-------------------------------------------------------- 275, 260 +17,+105
        //SelldrieButton
        textureSelldrieButton = new sf::Texture();
        spriteSelldrieButton = new sf::Sprite();

        textureSelldrieButton->loadFromFile("./Afbeelding/sell.png");
        spriteSelldrieButton->setTexture(*textureSelldrieButton);
        sf::Vector2f SelldrieButtonPosition(260, 370);
        spriteSelldrieButton->setPosition(SelldrieButtonPosition);
        spriteSelldrieButton->setScale(2.0f, 2.0f);

        //ShopdrieBlueButton
        textureShopdrieBlueButton = new sf::Texture();
        spriteShopdrieBlueButton = new sf::Sprite();

        textureShopdrieBlueButton->loadFromFile("./Afbeelding/BuyBlue.png");
        spriteShopdrieBlueButton->setTexture(*textureShopdrieBlueButton);
        sf::Vector2f ShopdrieBlueButtonPosition(360, 370);
        spriteShopdrieBlueButton->setPosition(ShopdrieBlueButtonPosition);
        spriteShopdrieBlueButton->setScale(2.0f, 2.0f);

        //ShopdrieButton
        textureShopdrieButton = new sf::Texture();
        spriteShopdrieButton = new sf::Sprite();

        textureShopdrieButton->loadFromFile("./Afbeelding/BuyRed.png");
        spriteShopdrieButton->setTexture(*textureShopdrieButton);
        sf::Vector2f ShopdrieButtonPosition(310, 370);
        spriteShopdrieButton->setPosition(ShopdrieButtonPosition);
        spriteShopdrieButton->setScale(2.0f, 2.0f);
        //--------------------------------------------------------
        //SellvierButton
        textureSellvierButton = new sf::Texture();
        spriteSellvierButton = new sf::Sprite();

        textureSellvierButton->loadFromFile("./Afbeelding/sell.png");
        spriteSellvierButton->setTexture(*textureSellvierButton);
        sf::Vector2f SellvierButtonPosition(260, 543);
        spriteSellvierButton->setPosition(SellvierButtonPosition);
        spriteSellvierButton->setScale(2.0f, 2.0f);

        //ShopeenBlueButton
        textureShopvierBlueButton = new sf::Texture();
        spriteShopvierBlueButton = new sf::Sprite();

        textureShopvierBlueButton->loadFromFile("./Afbeelding/BuyBlue.png");
        spriteShopvierBlueButton->setTexture(*textureShopvierBlueButton);
        sf::Vector2f ShopvierBlueButtonPosition(360, 543);
        spriteShopvierBlueButton->setPosition(ShopvierBlueButtonPosition);
        spriteShopvierBlueButton->setScale(2.0f, 2.0f);

        //ShopeenButton
        textureShopvierButton = new sf::Texture();
        spriteShopvierButton = new sf::Sprite();

        textureShopvierButton->loadFromFile("./Afbeelding/BuyRed.png");
        spriteShopvierButton->setTexture(*textureShopvierButton);
        sf::Vector2f ShopvierButtonPosition(310, 543);
        spriteShopvierButton->setPosition(ShopvierButtonPosition);
        spriteShopvierButton->setScale(2.0f, 2.0f);
        //--------------------------------------------------------
        //SellvijfButton
        textureSellvijfButton = new sf::Texture();
        spriteSellvijfButton = new sf::Sprite();

        textureSellvijfButton->loadFromFile("./Afbeelding/sell.png");
        spriteSellvijfButton->setTexture(*textureSellvijfButton);
        sf::Vector2f SellvijfButtonPosition(542, 280);
        spriteSellvijfButton->setPosition(SellvijfButtonPosition);
        spriteSellvijfButton->setScale(2.0f, 2.0f);

        //ShopeenBlueButton
        textureShopvijfBlueButton = new sf::Texture();
        spriteShopvijfBlueButton = new sf::Sprite();

        textureShopvijfBlueButton->loadFromFile("./Afbeelding/BuyBlue.png");
        spriteShopvijfBlueButton->setTexture(*textureShopvijfBlueButton);
        sf::Vector2f ShopvijfBlueButtonPosition(642, 280);
        spriteShopvijfBlueButton->setPosition(ShopvijfBlueButtonPosition);
        spriteShopvijfBlueButton->setScale(2.0f, 2.0f);

        //ShopeenButton
        textureShopvijfButton = new sf::Texture();
        spriteShopvijfButton = new sf::Sprite();

        textureShopvijfButton->loadFromFile("./Afbeelding/BuyRed.png");
        spriteShopvijfButton->setTexture(*textureShopvijfButton);
        sf::Vector2f ShopvijfButtonPosition(592, 280);
        spriteShopvijfButton->setPosition(ShopvijfButtonPosition);
        spriteShopvijfButton->setScale(2.0f, 2.0f);
        //--------------------------------------------------------
        //SellzesButton
        textureSellzesButton = new sf::Texture();
        spriteSellzesButton = new sf::Sprite();

        textureSellzesButton->loadFromFile("./Afbeelding/sell.png");
        spriteSellzesButton->setTexture(*textureSellzesButton);
        sf::Vector2f SellzesButtonPosition(840, 543);
        spriteSellzesButton->setPosition(SellzesButtonPosition);
        spriteSellzesButton->setScale(2.0f, 2.0f);

        //ShopzesBlueButton
        textureShopzesBlueButton = new sf::Texture();
        spriteShopzesBlueButton = new sf::Sprite();

        textureShopzesBlueButton->loadFromFile("./Afbeelding/BuyBlue.png");
        spriteShopzesBlueButton->setTexture(*textureShopzesBlueButton);
        sf::Vector2f ShopzesBlueButtonPosition(940, 543);
        spriteShopzesBlueButton->setPosition(ShopzesBlueButtonPosition);
        spriteShopzesBlueButton->setScale(2.0f, 2.0f);

        //ShopzesButton
        textureShopzesButton = new sf::Texture();
        spriteShopzesButton = new sf::Sprite();

        textureShopzesButton->loadFromFile("./Afbeelding/BuyRed.png");
        spriteShopzesButton->setTexture(*textureShopzesButton);
        sf::Vector2f ShopzesButtonPosition(890, 543);
        spriteShopzesButton->setPosition(ShopzesButtonPosition);
        spriteShopzesButton->setScale(2.0f, 2.0f);
        //--------------------------------------------------------
        
        //OptionButton
        textureOptionButton = new sf::Texture();
        spriteOptionButton = new sf::Sprite();

        textureOptionButton->loadFromFile("./Afbeelding/OptionButton.png");
        spriteOptionButton->setTexture(*textureOptionButton);
        sf::Vector2f OptionButtonPosition(110, 10);
        spriteOptionButton->setPosition(OptionButtonPosition);
        spriteOptionButton->setScale(3.0f, 3.0f);

        //Rol met wapens
        textureRolwapens = new sf::Texture();
        spriteRolwapens = new sf::Sprite();

        textureRolwapens->loadFromFile("./Afbeelding/Rolwapens.png");
        spriteRolwapens->setTexture(*textureRolwapens);
        sf::Vector2f RolwapensPosition(10, 10);
        spriteRolwapens->setPosition(RolwapensPosition);
        spriteRolwapens->setScale(2.4f, 2.4f);

        //Kasteel
        texturecastle = new sf::Texture();
        spritecastle = new sf::Sprite();

        texturecastle->loadFromFile("./Afbeelding/Castletwee.png");
        spritecastle->setTexture(*texturecastle);
        sf::Vector2f castlePosition(1050, 80);
        spritecastle->setPosition(castlePosition);
        spritecastle->setRotation(30);
        spritecastle->setScale(1.8f, 1.8f);
        
        //Tower_een
        texturetowereen = new sf::Texture();
        spritetowereen = new sf::Sprite();

        texturetowereen->loadFromFile("./Afbeelding/Tower.png");
        spritetowereen->setTexture(*texturetowereen); //anders laat die moddervlek niet zien
        sf::Vector2f towereenPosition(275, 260);
        spritetowereen->setPosition(towereenPosition);
        spritetowereen->setScale(0.44f, 0.44f);

        //Tower_twee
        texturetowertwee = new sf::Texture();
        spritetowertwee = new sf::Sprite();

        texturetowertwee->loadFromFile("./Afbeelding/Tower.png");
        spritetowertwee->setTexture(*texturetowertwee); //anders laat die moddervlek niet zien
        sf::Vector2f towertweePosition(275, 430);
        spritetowertwee->setPosition(towertweePosition);
        spritetowertwee->setScale(0.44f, 0.44f);

        //Tower_drie
        texturetowerdrie = new sf::Texture();
        spritetowerdrie = new sf::Sprite();

        texturetowerdrie->loadFromFile("./Afbeelding/Tower.png");
        spritetowerdrie->setTexture(*texturetowerdrie); //anders laat die moddervlek niet zien
        sf::Vector2f towerdriePosition(37, 270);
        spritetowerdrie->setPosition(towerdriePosition);
        spritetowerdrie->setScale(0.4f, 0.4f);

        //Tower_vier
        texturetowervier = new sf::Texture();
        spritetowervier = new sf::Sprite();

        texturetowervier->loadFromFile("./Afbeelding/Tower.png");
        spritetowervier->setTexture(*texturetowervier); //anders laat die moddervlek niet zien
        sf::Vector2f towervierPosition(37, 490);
        spritetowervier->setPosition(towervierPosition);
        spritetowervier->setScale(0.4f, 0.4f);

        //Tower_vijf
        texturetowervijf = new sf::Texture();
        spritetowervijf = new sf::Sprite();

        texturetowervijf->loadFromFile("./Afbeelding/Tower.png");
        spritetowervijf->setTexture(*texturetowervijf); //anders laat die moddervlek niet zien
        sf::Vector2f towervijfPosition(547, 320);
        spritetowervijf->setPosition(towervijfPosition);
        spritetowervijf->setScale(0.5, 0.5f);

        //Tower_zes
        texturetowerzes = new sf::Texture();
        spritetowerzes = new sf::Sprite();

        texturetowerzes->loadFromFile("./Afbeelding/Tower.png");
        spritetowerzes->setTexture(*texturetowerzes); //anders laat die moddervlek niet zien
        sf::Vector2f towerzesPosition(850, 430);
        spritetowerzes->setPosition(towerzesPosition);
        spritetowerzes->setScale(0.43f, 0.43f);
    }
    
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
}