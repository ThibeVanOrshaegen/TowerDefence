#pragma once

#include <SFML/Graphics.hpp>
#include "HealthBar.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Canon.h"
#include "Laser.h"
#include "MG.h"

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
    bool spriteVisiblemg = false;

public:
    Game();

    void updateShooterRotation();
    void useWeapon(Weapon& weapon, sf::Vector2f shooterPosition);
    void run(sf::RenderWindow& window);
};

