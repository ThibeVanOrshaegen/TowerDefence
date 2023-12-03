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
#include "Weapon.h"
#include "Waves.h"

#include <vector>
namespace Towerdefense
{
class Game{
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

    std::vector<Wave> waves; // Vector to store different waves
    int currentWaveIndex;
    TextureManager textureManager;


    bool spriteVisibleP = false;
    bool spriteVisibleC = false;

    bool spriteVisiblecanon = false;
    bool spriteVisiblelaser = false;
    bool spriteVisiblelasereen = false;
    bool spriteVisiblelasertwee = false;
    bool spriteVisiblelaserdrie = false;
    bool spriteVisiblemg = false;

    std::vector<std::unique_ptr<Weapon>> weapons; //class composition, kan niet werken zonder, is dit een container class?


public:
    Game();

    void updateShooterRotation();
    void run(sf::RenderWindow& window);
    void useWeapon(Weapon& weapon, sf::Vector2f shooterPosition,int depth);
    void updateGameLogic();
    void startNextWave();

    // Function to update the current wave
    void updateCurrentWave();
};
}
#endif

