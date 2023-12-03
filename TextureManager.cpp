#include "TextureManager.h"
#include <memory>

#define M_PI 3.14159265358979323846

namespace Towerdefense
{
    TextureManager::TextureManager()
    {
        //OpeningScreen
        textureAchtergrond = new sf::Texture();
        spriteAchtergrond = new sf::Sprite();

        textureAchtergrond->loadFromFile("./cooltitlescreen.jpg");
        spriteAchtergrond->setTexture(*textureAchtergrond);
        sf::Vector2f AchtergrondPosition(0, 0);
        spriteAchtergrond->setPosition(AchtergrondPosition);
        spriteAchtergrond->setScale(1.0f, 1.0f);

        //Title
        texturepaper = new sf::Texture();
        spritepaper = new sf::Sprite();

        texturepaper->loadFromFile("./paperrolverticaal.png");
        spritepaper->setTexture(*texturepaper);
        sf::Vector2f TitlePosition(10, 200);
        spritepaper->setPosition(TitlePosition);
        spritepaper->setScale(0.7f, 0.44f);

        //Playbutton
        textureplay = new sf::Texture();
        spriteplay = new sf::Sprite();

        textureplay->loadFromFile("./newplay.png");
        spriteplay->setTexture(*textureplay);
        sf::Vector2f PlaybuttonPosition(150, 290);
        spriteplay->setPosition(PlaybuttonPosition);
        spriteplay->setScale(0.3f, 0.3f);

        //Optionbutton
        textureoption = new sf::Texture();
        spriteoption = new sf::Sprite();

        textureoption->loadFromFile("./Newoptions.png");
        spriteoption->setTexture(*textureoption);
        sf::Vector2f optionPosition(140, 350);
        spriteoption->setPosition(optionPosition);
        spriteoption->setScale(0.25f, 0.25f);

        //Towerdefense Text
        texturetowerdefensetext = new sf::Texture();
        spritetowerdefensetext = new sf::Sprite();

        texturetowerdefensetext->loadFromFile("./towertextonder.png");
        spritetowerdefensetext->setTexture(*texturetowerdefensetext);
        sf::Vector2f towerdefensetextPosition(0, 20);
        spritetowerdefensetext->setPosition(towerdefensetextPosition);
        spritetowerdefensetext->setScale(0.7f, 0.5f);

        //Pad
        texturepad = new sf::Texture();
        spritepad = new sf::Sprite();

        texturepad->loadFromFile("./plattegrond.png");
        spritepad->setTexture(*texturepad);

        //Kasteel
        texturecastle = new sf::Texture();
        spritecastle = new sf::Sprite();

        texturecastle->loadFromFile("./Castletwee.png");
        spritecastle->setTexture(*texturecastle);
        sf::Vector2f castlePosition(1050, 80);
        spritecastle->setPosition(castlePosition);
        spritecastle->setRotation(30);
        spritecastle->setScale(1.8f, 1.8f);

        //Tower_een
        texturetowereen = new sf::Texture();
        spritetowereen = new sf::Sprite();

        texturetowereen->loadFromFile("./Tower.png");
        spritetowereen->setTexture(*texturetowereen); //anders laat die moddervlek niet zien
        sf::Vector2f towereenPosition(275, 260);
        spritetowereen->setPosition(towereenPosition);
        spritetowereen->setScale(0.44f, 0.44f);

        //Tower_twee
        texturetowertwee = new sf::Texture();
        spritetowertwee = new sf::Sprite();

        texturetowertwee->loadFromFile("./Tower.png");
        spritetowertwee->setTexture(*texturetowertwee); //anders laat die moddervlek niet zien
        sf::Vector2f towertweePosition(275, 430);
        spritetowertwee->setPosition(towertweePosition);
        spritetowertwee->setScale(0.44f, 0.44f);

        //Tower_drie
        texturetowerdrie = new sf::Texture();
        spritetowerdrie = new sf::Sprite();

        texturetowerdrie->loadFromFile("./Tower.png");
        spritetowerdrie->setTexture(*texturetowerdrie); //anders laat die moddervlek niet zien
        sf::Vector2f towerdriePosition(37, 270);
        spritetowerdrie->setPosition(towerdriePosition);
        spritetowerdrie->setScale(0.4f, 0.4f);

        //Tower_vier
        texturetowervier = new sf::Texture();
        spritetowervier = new sf::Sprite();

        texturetowervier->loadFromFile("./Tower.png");
        spritetowervier->setTexture(*texturetowervier); //anders laat die moddervlek niet zien
        sf::Vector2f towervierPosition(37, 490);
        spritetowervier->setPosition(towervierPosition);
        spritetowervier->setScale(0.4f, 0.4f);

        //Tower_vijf
        texturetowervijf = new sf::Texture();
        spritetowervijf = new sf::Sprite();

        texturetowervijf->loadFromFile("./Tower.png");
        spritetowervijf->setTexture(*texturetowervijf); //anders laat die moddervlek niet zien
        sf::Vector2f towervijfPosition(547, 320);
        spritetowervijf->setPosition(towervijfPosition);
        spritetowervijf->setScale(0.5, 0.5f);

        //Tower_zes
        texturetowerzes = new sf::Texture();
        spritetowerzes = new sf::Sprite();

        texturetowerzes->loadFromFile("./Tower.png");
        spritetowerzes->setTexture(*texturetowerzes); //anders laat die moddervlek niet zien
        sf::Vector2f towerzesPosition(850, 430);
        spritetowerzes->setPosition(towerzesPosition);
        spritetowerzes->setScale(0.43f, 0.43f);

        //Money Rectangle
        textureMoneyrec = new sf::Texture();
        spriteMoneyrec = new sf::Sprite();

        textureMoneyrec->loadFromFile("./Money_rec.png");
        spriteMoneyrec->setTexture(*textureMoneyrec); //anders laat die moddervlek niet zien
        sf::Vector2f MoneyrecPosition(0, 20);
        spriteMoneyrec->setPosition(MoneyrecPosition);
        spriteMoneyrec->setScale(0.13f, 0.13f);

        //Inside Money Rectangle
        textureinsideMoneyrec = new sf::Texture();
        spriteinsideMoneyrec = new sf::Sprite();

        textureinsideMoneyrec->loadFromFile("./Donkerbruin.jpg");
        spriteinsideMoneyrec->setTexture(*textureinsideMoneyrec); //anders laat die moddervlek niet zien
        sf::Vector2f insideMoneyrecPosition(19, 40);
        spriteinsideMoneyrec->setPosition(insideMoneyrecPosition);
        spriteinsideMoneyrec->setScale(0.29f, 0.2f);

        //E
        textureE = new sf::Texture();
        spriteE = new sf::Sprite();

        textureE->loadFromFile("./E.png");
        spriteE->setTexture(*textureE);
        sf::Vector2f EPosition(62, 370);
        spriteE->setPosition(EPosition);
        spriteE->setScale(0.3f, 0.3f);

        //Rol met wapens
        textureRolwapens = new sf::Texture();
        spriteRolwapens = new sf::Sprite();

        textureRolwapens->loadFromFile("./Rolwapens.png");
        spriteRolwapens->setTexture(*textureRolwapens);
        sf::Vector2f RolwapensPosition(400, 550);
        spriteRolwapens->setPosition(RolwapensPosition);
        spriteRolwapens->setScale(1.0f, 0.6f);

        //Canon level 1
        texturecanonleveleen = new sf::Texture();
        spritecanonleveleen = new sf::Sprite();

        texturecanonleveleen->loadFromFile("./Cannon.png");
        spritecanonleveleen->setTexture(*texturecanonleveleen);
        sf::Vector2f TowerdrieCanonPosition(300, 260);
        spritecanonleveleen->setPosition(TowerdrieCanonPosition);
        spritecanonleveleen->setRotation(0);
        spritecanonleveleen->setScale(0.35f, 0.35f);

        //Laser level 1
        texturelaserleveleen = new sf::Texture();
        spritelaserleveleen = new sf::Sprite();

        texturelaserleveleen->loadFromFile("./Missile_Launcher.png");
        spritelaserleveleen->setTexture(*texturelaserleveleen);
        sf::Vector2f TowerdrieLaserPosition(300, 260);
        spritelaserleveleen->setPosition(TowerdrieLaserPosition);
        spritelaserleveleen->setRotation(0);
        spritelaserleveleen->setScale(0.35f, 0.35f);

        //als er al iets op die positie staat gaat het niet tenzij je het verkoopt

        textureEnemyOne.loadFromFile("./Robottwee.png");
        spriteEnemyOne.setTexture(textureEnemyOne);
        spriteEnemyOne.setScale(0.35f, 0.35f);

        //Goldname
        textureGoldname = new sf::Texture();
        spriteGoldname = new sf::Sprite();

        textureGoldname->loadFromFile("./Goldname.png");
        spriteGoldname->setTexture(*textureGoldname);
        sf::Vector2f GoldnamePosition(23, 57);
        spriteGoldname->setPosition(GoldnamePosition);
        spriteGoldname->setRotation(0);
        spriteGoldname->setScale(0.28f, 0.28f);


    }

    TextureManager::~TextureManager()
    {
        // Cleanup
        delete textureAchtergrond;
        delete spriteAchtergrond;

        delete texturepaper;
        delete spritepaper;

        delete textureplay;
        delete spriteplay;

        delete textureoption;
        delete spriteoption;

        delete texturetowerdefensetext;
        delete spritetowerdefensetext;

        delete texturepad;
        delete spritepad;

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

        delete textureMoneyrec;
        delete spriteMoneyrec;

        delete textureinsideMoneyrec;
        delete spriteinsideMoneyrec;

        delete textureE;
        delete spriteE;

        delete textureRolwapens;
        delete spriteRolwapens;

        delete texturecanonleveleen;
        delete spritecanonleveleen;

        delete textureGoldname;
        delete spriteGoldname;

    }
}