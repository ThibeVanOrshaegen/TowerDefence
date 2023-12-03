#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace Towerdefense
{
    class TextureManager
    {
    public:
        //Title
        sf::Texture* texturepaper;
        sf::Sprite* spritepaper;

        //OpeningScreen
        sf::Texture* textureAchtergrond;
        sf::Sprite* spriteAchtergrond;

        //Playbutton
        sf::Texture* textureplay;
        sf::Sprite* spriteplay;

        //Option
        sf::Texture* textureoption;
        sf::Sprite* spriteoption;

        //Towerdefensetext
        sf::Texture* texturetowerdefensetext;
        sf::Sprite* spritetowerdefensetext;

        //Pad
        sf::Texture* texturepad;
        sf::Sprite* spritepad;

        //Kasteel
        sf::Texture* texturecastle;
        sf::Sprite* spritecastle;

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

        //Money Rectangle
        sf::Texture* textureMoneyrec;
        sf::Sprite* spriteMoneyrec;

        //Binnekant Money Rectangle
        sf::Texture* textureinsideMoneyrec;
        sf::Sprite* spriteinsideMoneyrec;

        //E
        sf::Texture* textureE;
        sf::Sprite* spriteE;

        //T
        sf::Texture* textureT;
        sf::Sprite* spriteT;

        //D
        sf::Texture* textureD;
        sf::Sprite* spriteD;

        //V
        sf::Texture* textureV;
        sf::Sprite* spriteV;

        //W
        sf::Texture* textureW;
        sf::Sprite* spriteW;

        //Z
        sf::Texture* textureZ;
        sf::Sprite* spritez;

        //Rol met wapens
        sf::Texture* textureRolwapens;
        sf::Sprite* spriteRolwapens;

        //Canon level 1
        sf::Texture* texturecanonleveleen;
        sf::Sprite* spritecanonleveleen;

        //Laser level 1
        sf::Texture* texturelaserleveleen;
        sf::Sprite* spritelaserleveleen;

        //EnemyOne
        sf::Texture textureEnemyOne;
        sf::Sprite spriteEnemyOne;

        sf::Texture* textureGoldname;
        sf::Sprite* spriteGoldname;

        sf::Texture textureKogelCanon;
        sf::Sprite spriteKogelCanon;

        sf::Texture textureKogelLaser;
        sf::Sprite spriteKogelLaser;


        TextureManager();//constructor
        ~TextureManager(); //destructor

    };
}
#endif 
