#include "TextureManager.h"

#define M_PI 3.14159265358979323846

TextureManager::TextureManager()
{
    texture = new sf::Texture();
    sprite = new sf::Sprite();

    //OpeningScreen

    textureAchtergrond.loadFromFile("./cooltitlescreen.jpg");
    spriteAchtergrond.setTexture(textureAchtergrond);
    sf::Vector2f AchtergrondPosition(0, 0);
    spriteAchtergrond.setPosition(AchtergrondPosition);
    spriteAchtergrond.setScale(1.0f, 1.0f);

    //Title

    texturetitle.loadFromFile("./paperrolverticaal.png");
    spritetitle.setTexture(texturetitle);
    sf::Vector2f TitlePosition(10, 200);
    spritetitle.setPosition(TitlePosition);
    spritetitle.setScale(0.7f, 0.44f);

    //Playbutton

    textureplay.loadFromFile("./newplay.png");
    spriteplay.setTexture(textureplay);
    sf::Vector2f PlaybuttonPosition(150, 290);
    spriteplay.setPosition(PlaybuttonPosition);
    spriteplay.setScale(0.3f, 0.3f);

    //Optionbutton

    textureoption.loadFromFile("./Newoptions.png");
    spriteoption.setTexture(textureoption);
    sf::Vector2f optionPosition(140, 350);
    spriteoption.setPosition(optionPosition);
    spriteoption.setScale(0.25f, 0.25f);

    //Towerdefense Text

    texturetowerdefensetext.loadFromFile("./towertextonder.png");
    spritetowerdefensetext.setTexture(texturetowerdefensetext);
    sf::Vector2f towerdefensetextPosition(0, 20);
    spritetowerdefensetext.setPosition(towerdefensetextPosition);
    spritetowerdefensetext.setScale(0.7f, 0.5f);


    //Pad

    texture->loadFromFile("./plattegrond.png");
    sprite->setTexture(*texture);


    //Kasteel

    texturecastle.loadFromFile("./Castletwee.png");
    spritecastle.setTexture(texturecastle);
    sf::Vector2f castlePosition(1050, 80);
    spritecastle.setPosition(castlePosition);
    spritecastle.setRotation(30);
    spritecastle.setScale(1.8f, 1.8f);

    //Paper
    texturepaper.loadFromFile("./perkament.png");
    spritepaper.setTexture(texturepaper);
    sf::Vector2f paperPosition(100, 100);
    spritepaper.setPosition(paperPosition);
    spritepaper.setScale(2.0f, 2.0f);

    //Upgrades
    texturevbCannon.loadFromFile("./Cannon.png");
    spritevbCannon.setTexture(texturevbCannon);
    sf::Vector2f vbCannonPosition(210, 240);
    spritevbCannon.setPosition(vbCannonPosition);
    spritevbCannon.setRotation(270);
    spritevbCannon.setScale(0.3f, 0.3f);

    texturevbCannon2.loadFromFile("./Cannon2.png");
    spritevbCannon2.setTexture(texturevbCannon2);
    sf::Vector2f vbCannon2Position(310, 250);
    spritevbCannon2.setPosition(vbCannon2Position);
    spritevbCannon2.setRotation(270);
    spritevbCannon2.setScale(0.3f, 0.3f);

    texturevbCannon3.loadFromFile("./Cannon3.png");
    spritevbCannon3.setTexture(texturevbCannon3);
    sf::Vector2f vbCannon3Position(420, 250);
    spritevbCannon3.setPosition(vbCannon3Position);
    spritevbCannon3.setRotation(270);
    spritevbCannon3.setScale(0.3f, 0.3f);

    texturevbMG.loadFromFile("./MG.png");
    spritevbMG.setTexture(texturevbMG);
    sf::Vector2f vbMGPosition(210, 340);
    spritevbMG.setPosition(vbMGPosition);
    spritevbMG.setRotation(270);
    spritevbMG.setScale(0.3f, 0.3f);

    texturevbMG2.loadFromFile("./MG2.png");
    spritevbMG2.setTexture(texturevbMG2);
    sf::Vector2f vbMG2Position(310, 340);
    spritevbMG2.setPosition(vbMG2Position);
    spritevbMG2.setRotation(270);
    spritevbMG2.setScale(0.3f, 0.3f);

    texturevbMG3.loadFromFile("./MG3.png");
    spritevbMG3.setTexture(texturevbMG3);
    sf::Vector2f vbMG3Position(410, 340);
    spritevbMG3.setPosition(vbMG3Position);
    spritevbMG3.setRotation(270);
    spritevbMG3.setScale(0.3f, 0.3f);

    texturevbMissile_Launcher.loadFromFile("./Missile_Launcher.png");
    spritevbMissile_Launcher.setTexture(texturevbMissile_Launcher);
    sf::Vector2f vbMissile_LauncherPosition(210, 440);
    spritevbMissile_Launcher.setPosition(vbMissile_LauncherPosition);
    spritevbMissile_Launcher.setRotation(270);
    spritevbMissile_Launcher.setScale(0.3f, 0.3f);

    texturevbMissile_Launcher2.loadFromFile("./Missile_Launcher2.png");
    spritevbMissile_Launcher2.setTexture(texturevbMissile_Launcher2);
    sf::Vector2f vbMissile_Launcher2Position(335, 450);
    spritevbMissile_Launcher2.setPosition(vbMissile_Launcher2Position);
    spritevbMissile_Launcher2.setRotation(270);
    spritevbMissile_Launcher2.setScale(0.3f, 0.3f);

    texturevbMissile_Launcher3.loadFromFile("./Missile_Launcher3.png");
    spritevbMissile_Launcher3.setTexture(texturevbMissile_Launcher3);
    sf::Vector2f vbMissile_Launcher3Position(440, 455);
    spritevbMissile_Launcher3.setPosition(vbMissile_Launcher3Position);
    spritevbMissile_Launcher3.setRotation(270);
    spritevbMissile_Launcher3.setScale(0.3f, 0.3f);

    // GamemenuText



    //Moder plaatse, Plaats om op te bouwen(als er voldoende munten zijn)

    texturemudeen.loadFromFile("./mudtwee.png");
    spritemudeen.setTexture(texturemudeen); //anders laat die moddervlek niet zien
    sf::Vector2f mudeenPosition(225, 230);
    spritemudeen.setPosition(mudeenPosition);
    spritemudeen.setScale(0.3f, 0.3f);

    texturemudtwee.loadFromFile("./mudtwee.png");
    spritemudtwee.setTexture(texturemudtwee); //anders laat die moddervlek niet zien
    sf::Vector2f mudtweePosition(225, 400);
    spritemudtwee.setPosition(mudtweePosition);
    spritemudtwee.setScale(0.3f, 0.3f);

    texturemuddrie.loadFromFile("./mudtwee.png");
    spritemuddrie.setTexture(texturemuddrie); //anders laat die moddervlek niet zien
    sf::Vector2f muddriePosition(0, 250);
    spritemuddrie.setPosition(muddriePosition);
    spritemuddrie.setScale(0.25f, 0.25f);

    texturemudzes.loadFromFile("./mudtwee.png");
    spritemudzes.setTexture(texturemudzes); //anders laat die moddervlek niet zien
    sf::Vector2f mudzesPosition(0, 470);
    spritemudzes.setPosition(mudzesPosition);
    spritemudzes.setScale(0.25f, 0.25f);

    texturemudvier.loadFromFile("./mudtwee.png");
    spritemudvier.setTexture(texturemudvier); //anders laat die moddervlek niet zien
    sf::Vector2f mudvierPosition(505, 320);
    spritemudvier.setPosition(mudvierPosition);
    spritemudvier.setScale(0.3f, 0.3f);

    texturemudvijf.loadFromFile("./mudtwee.png");
    spritemudvijf.setTexture(texturemudvijf); //anders laat die moddervlek niet zien
    sf::Vector2f mudvijfPosition(800, 400);
    spritemudvijf.setPosition(mudvijfPosition);
    spritemudvijf.setScale(0.3f, 0.3f);

    //Weapons

    textureshootereen.loadFromFile("./canonzo.png"); // x = +70, y = +40
    spriteshootereen.setTexture(textureshootereen);
    sf::Vector2f shootereenPosition(320, 300);
    spriteshootereen.setPosition(shootereenPosition);
    spriteshootereen.setRotation(180);
    spriteshootereen.setScale(0.1f, 0.1f);

    textureshootertwee.loadFromFile("./canonzo.png");
    spriteshootertwee.setTexture(textureshootertwee);
    sf::Vector2f shootertweePosition(288, 440);
    spriteshootertwee.setPosition(shootertweePosition);
    spriteshootertwee.setScale(0.1f, 0.1f);

    textureshooterdrie.loadFromFile("./Missile_Launcher.png");
    spriteshooterdrie.setTexture(textureshooterdrie);
    sf::Vector2f shooterdriePosition(610, 400);
    spriteshooterdrie.setPosition(shooterdriePosition);
    spriteshooterdrie.setRotation(180);
    spriteshooterdrie.setScale(0.4f, 0.4f);

    textureshootervier.loadFromFile("./MG.png");
    spriteshootervier.setTexture(textureshootervier);
    sf::Vector2f shootervierPosition(100, 340);
    spriteshootervier.setPosition(shootervierPosition);
    spriteshootervier.setRotation(180);
    spriteshootervier.setScale(0.4f, 0.4f);

    //Weapon Upgrades

    //Enemy

    texturerobottwee.loadFromFile("./Robottwee.png");
    spriterobottwee.setTexture(texturerobottwee);
    spriterobottwee.setScale(0.3f, 0.3f);

    //Geld

    texturegold.loadFromFile("./munteindelijk.png"); //moet getal onderaan staan dat het aantal munten bijhoud met geld teken naast
    spritegold.setTexture(texturegold);
    spritegold.setScale(0.2f, 0.2f);
}

TextureManager::~TextureManager()
{
    // Cleanup
    delete texture;
    delete sprite;
}
