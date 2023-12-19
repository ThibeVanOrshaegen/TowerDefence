#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "CurrentMoney.h"
#include "HealthBar.h"
#include "Enemy.h"
#include "Canonshooting.h"
#include "Lasershooting.h"
#include "Canon.h"
#include "Updaterotation.h"
#include <cmath>
#include "MouseEventHandler.h"
#include "Laser.h"

#define M_PI 3.14159265358979323846

namespace Towerdefense
{
	// Forward declaration of CurrentMoney class
	class CurrentMoney;

	// Declaration of the Game class
	class Game {

	public:
		Game();
		~Game();

		// Method to check if the game is running
		bool isRunning() const { return running; }

		void run(sf::RenderWindow& window);

		void updatehealthBarGame();
		void updateEnemies();
		void updateHandleIntersectionAndDamage();
		void useWeapon(Weapon& weapon, sf::Vector2f shooterPosition, float limit_one, float limit_two, float limit_three, float limit_four);
		void updateRotationGame();
		void backgroundTask(Game& game);

		// Method to swap two values
		void swap(unsigned char & x, unsigned char & y) {
			int temp = x;
			x = y;
			y = temp;
		}
		sf::Vector2f direction;

		// Static variables used for various game state and control flags
		static bool isPKeyPressed;
		static bool isGKeyPressed;
		static bool spriteVisibleP;
		static bool spriteVisibleG;
		static bool spriteTruePlay;
		static bool spriteTruePause;
		static bool spriteTrueOpenOption;

		static bool spriteSelleen;
		static bool spriteBuyblue;
		static bool spriteBuyRed;

		static bool spriteSelltwee;
		static bool spriteBuybluetwee;
		static bool spriteBuyRedtwee;

		static bool spriteSelldrie;
		static bool spriteBuybluedrie;
		static bool spriteBuyReddrie;

		static bool spriteSellvier;
		static bool spriteBuybluevier;
		static bool spriteBuyRedvier;

		static bool spriteSellvijf;
		static bool spriteBuybluevijf;
		static bool spriteBuyRedvijf;

		static bool spriteSellzes;
		static bool spriteBuybluezes;
		static bool spriteBuyRedzes;

		static bool PlaceOneEmpty;
		static bool PlaceTwoEmpty;
		static bool PlaceThreeEmpty;
		static bool PlaceFourEmpty;
		static bool PlaceFiveEmpty;
		static bool PlaceSixEmpty;

		static bool spriteAmmorotation;

		static bool outOfRangenew;

		static bool running;

		TextureManager textureManager;
		CurrentMoney* currentmoneyklein;

		HealthBar healthBar_een;
		HealthBar redhealthBar_een_copy;
		HealthBar healthBar_twee;
		HealthBar redhealthBar_twee_copy;

		Laser* laserplaats;
		Laser* laserplaatstwee;
		Laser* laserplaatsdrie;
		Laser* laserplaatsvier;
		Laser* laserplaatsvijf;
		Laser* laserplaatszes;

		Lasershooting* laserkogel = new Lasershooting(sf::Vector2f(direction.x, direction.y));
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

		Canonshooting* canonkogel;
		Canonshooting* canonkogeltwee;
		Canonshooting* canonkogeldrie;
		Canonshooting* canonkogelvier;
		Canonshooting* canonkogelvijf;
		Canonshooting* canonkogelzes;

		Enemy* snel;
		Enemy* traag;

		// Updaterotation and MouseEventHandler objects
		Updaterotation updaterotation;
		MouseEventHandler mouseEventHandler;


		void init();

		// Unique pointer for the currentWeapon
		std::unique_ptr<Weapon> currentWeapon;

	private:

	};

}
#endif
#endif
