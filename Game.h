#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "EnemyOne.h"
#include "HealthBar.h"
#include "Wave.h"
#include "Weapon.h"
#include "Canonshooting.h"
#include "Canon.h"
#include "Laser.h"
#include "Gold.h"
#include "Updaterotation.h"

namespace Towerdefense
{
	class Game {
	private:
		int currentWaveIndex; // Index of the current wave

		TextureManager textureManager;

		Updaterotation updaterotation;

		HealthBar healthBar_een;
		HealthBar redhealthBar_een_copy;

		HealthBar healthBar_twee;
		HealthBar redhealthBar_twee_copy;

		EnemyOne* snel;
		EnemyOne* traag;

		Canonshooting* canonkogel;
		Canonshooting* canonkogeltwee;
		Canonshooting* canonkogeldrie;
		Canonshooting* canonkogelvier;
		Canonshooting* canonkogelvijf;
		Canonshooting* canonkogelzes;

		Lasershooting* laserkogel;
		Lasershooting* laserkogeltwee;
		Lasershooting* laserkogeldrie;
		Lasershooting* laserkogelvier;
		Lasershooting* laserkogelvijf;
		Lasershooting* laserkogelzes;

		Canon* canonplaats;
		Canon* canonplaatstwee;
		Canon* canonplaatsdrie;
		Canon* canonplaatsvier;
		Canon* canonplaatsvijf;
		Canon* canonplaatszes;

		Laser* laserplaats;

		Wave wave;


		Gold<int> gold;

		static bool isPKeyPressed;
		static bool isGKeyPressed;

		static bool isKKeyPressed; //Continue
		static bool isLkeyPressed;
		static bool isQKeyPressed;
		static bool isCKeyPressed;
		static bool isSKeyPressed;
		static bool isMKeyPressed;

		static bool isEKeyPressed;
		static bool isTKeyPressed;
		static bool isDKeyPressed;
		static bool isVKeyPressed;
		static bool isWKeyPressed;
		static bool isZKeyPressed;

		static bool spriteVisibleP;
		static bool spriteVisibleG;
		static bool spriteVisibleO;

		static bool spriteVisibleC;
		static bool spriteVisibleCtwee;
		static bool spriteVisibleCdrie;
		static bool spriteVisibleCvier;
		static bool spriteVisibleCvijf;
		static bool spriteVisibleCzes;

		static bool spriteVisibleRotation;

		static bool spriteVisibleL;
		static bool spriteVisibleLtwee;
		static bool spriteVisibleLdrie;
		static bool spriteVisibleLvier;
		static bool spriteVisibleLvijf;
		static bool spriteVisibleLzes;

		static bool spriteVisibleQ;

		static bool spriteVisibleE;
		static bool spriteVisibleT;
		static bool spriteVisibleD;
		static bool spriteVisibleV;
		static bool spriteVisibleW;
		static bool spriteVisibleZ;


		static bool PlaceEIsEmty;
		static bool PlaceTIsEmty;
		static bool PlaceDIsEmty;
		static bool PlaceVIsEmty;
		static bool PlaceWIsEmty;
		static bool PlaceZIsEmty;

		static bool shooterposition;
		static bool shooterpositiontwee;
		static bool shooterpositiondrie;
		static bool shooterpositionvier;
		static bool shooterpositionvijf;
		static bool shooterpositionzes;

		static bool EshootPosition;
		static bool TshootPosition;
		static bool DshootPosition;
		static bool VshootPosition;
		static bool WshootPosition;
		static bool ZshootPosition;

		static bool ELshootPosition;
		static bool TLshootPosition;
		static bool DLshootPosition;
		static bool VLshootPosition;
		static bool WLshootPosition;
		static bool ZLshootPosition;

		static bool WaveOneCompleet;


	public:
		Game();
		~Game();
		void run(sf::RenderWindow& window);
		void useWeapon(Weapon& weapon, sf::Vector2f shooterPosition);
		void updateEnemies();
		void updateEnemiestwee();
		void updateHandleIntersectionAndDamage();
		void updatehealthBar();
		//void updateShooterRotation();
	};

}
#endif

