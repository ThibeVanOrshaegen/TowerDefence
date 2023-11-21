#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "HealthBar.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Canon.h"
#include "Laser.h"
#include "MG.h"
#include "EnemyManager.h"
#include "ShooterPositionCalculator.h"
#include <vector>

class Game {
private:
    HealthBar healthBar_een;
    HealthBar healthBar_twee;
    HealthBar healthBar_drie;
    HealthBar healthBar_vier;

    HealthBar redhealthBar_een;
    HealthBar redhealthBar_twee;
    HealthBar redhealthBar_drie;
    HealthBar redhealthBar_vier;

    Enemy snel;
    Enemy traag;
    Enemy snelxtraagy;
    Enemy traagxsnely;

    Canon canon;
    Laser laser;
    MG mg;


    TextureManager textureManager;


    bool spriteVisibleP = false;
    bool spriteVisibleC = false;

    bool spriteVisiblecanon = false;
    bool spriteVisiblelaser = false;
    bool spriteVisiblelasereen = false;
    bool spriteVisiblelasertwee = false;
    bool spriteVisiblelaserdrie = false;
    bool spriteVisiblemg = false;

    std::vector<std::unique_ptr<Weapon>> weapons;


public:
    Game();

    void updateShooterRotation();
    void run(sf::RenderWindow& window);
    void useWeapon(Weapon& weapon, sf::Vector2f shooterPosition);
    void updateGameLogic();
};
#endif

