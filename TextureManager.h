#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TextureManager
{
public:
    //Title

    sf::Texture texturetitle;
    sf::Sprite spritetitle;

    //OpeningScreen

    sf::Texture textureAchtergrond;
    sf::Sprite spriteAchtergrond;

    //Playbutton

    sf::Texture textureplay;
    sf::Sprite spriteplay;

    //Playbutton

    sf::Texture textureoption;
    sf::Sprite spriteoption;

    //Towerdefensetext

    sf::Texture texturetowerdefensetext;
    sf::Sprite spritetowerdefensetext;


    //Pad

    sf::Texture* texture;
    sf::Sprite* sprite;

    //Kasteel

    sf::Texture texturecastle;
    sf::Sprite spritecastle;


    //Perkament 

    sf::Texture texturepaper;
    sf::Sprite spritepaper;

    sf::Texture texturevbCannon;
    sf::Sprite spritevbCannon;

    sf::Texture texturevbCannon2;
    sf::Sprite spritevbCannon2;

    sf::Texture texturevbCannon3;
    sf::Sprite spritevbCannon3;

    sf::Texture texturevbMG;
    sf::Sprite spritevbMG;

    sf::Texture texturevbMG2;
    sf::Sprite spritevbMG2;

    sf::Texture texturevbMG3;
    sf::Sprite spritevbMG3;

    sf::Texture texturevbMissile_Launcher;
    sf::Sprite spritevbMissile_Launcher;

    sf::Texture texturevbMissile_Launcher2;
    sf::Sprite spritevbMissile_Launcher2;

    sf::Texture texturevbMissile_Launcher3;
    sf::Sprite spritevbMissile_Launcher3;

    sf::Texture texturegamemenutext;
    sf::Sprite spritegamemenutext;

    //Moder plaatse, Plaats om op te bouwen(als er voldoende munten zijn)

    sf::Texture texturemudeen;
    sf::Sprite spritemudeen;

    sf::Texture texturemudtwee;
    sf::Sprite spritemudtwee;

    sf::Texture texturemuddrie;
    sf::Sprite spritemuddrie;

    sf::Texture texturemudvier;
    sf::Sprite spritemudvier;

    sf::Texture texturemudvijf;
    sf::Sprite spritemudvijf;

    sf::Texture texturemudzes;
    sf::Sprite spritemudzes;

    //Tower

    sf::Texture texturetowereen;
    sf::Sprite spritetowereen;

    sf::Texture texturetowertwee;
    sf::Sprite spritetowertwee;

    sf::Texture texturetowerdrie;
    sf::Sprite spritetowerdrie;

    sf::Texture texturetowervier;
    sf::Sprite spritetowervier;

    sf::Texture texturetowervijf;
    sf::Sprite spritetowervijf;

    sf::Texture texturetowerzes;
    sf::Sprite spritetowerzes;

    //Canon

    sf::Texture textureshootereen;
    sf::Sprite spriteshootereen;

    sf::Texture textureshootertwee;
    sf::Sprite spriteshootertwee;

    sf::Texture textureshooterdrie;
    sf::Sprite spriteshooterdrie;

    sf::Texture textureshootervier;
    sf::Sprite spriteshootervier;

    //Enemy

    sf::Texture texturerobottwee;
    sf::Sprite spriterobottwee;

    sf::Texture texturerobotdrie;
    sf::Sprite spriterobotdrie;

    //Geld

    sf::Texture texturegold;
    sf::Sprite spritegold;

    //Laser
    sf::Texture texturelaser;
    sf::Sprite spritelaser;

    //Canonred
    sf::Texture texturecanonred;
    sf::Sprite spritecanonred;

    //MG
    sf::Texture textureMG;
    sf::Sprite spriteMG;


    TextureManager();
    ~TextureManager();
};

