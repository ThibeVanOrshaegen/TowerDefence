#include "Canon.h"
#include "EnemyOne.h"
namespace Towerdefense
{
    Canon::Canon(sf::Vector2f initialPosition) : spritecanonleveleen(), Canonposition(initialPosition) {//constrcutor,  member initialization in contructor
        textureManager.texturecanonleveleen.loadFromFile("./Cannon.png");
        spritecanonleveleen.setTexture(textureManager.texturecanonleveleen);
        spritecanonleveleen.setPosition(initialPosition);
        spritecanonleveleen.setScale(0.35f, 0.35f);
    }
}

//2 useful unsigned chars or other better usage of memory efficient type?

/*
        texturecanonleveleen = new sf::Texture();
        spritecanonleveleen = new sf::Sprite();

        texturecanonleveleen->loadFromFile("./Cannon.png");
        spritecanonleveleen->setTexture(*texturecanonleveleen);
        sf::Vector2f TowerdrieCanonPosition(300, 260);
        spritecanonleveleen->setPosition(TowerdrieCanonPosition);
        spritecanonleveleen->setRotation(0);
        spritecanonleveleen->setScale(0.35f, 0.35f);

        */