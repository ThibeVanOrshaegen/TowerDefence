#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "EnemyOne.h"
#include "HealthBar.h"
#include "Wave.h"
#include "Weapon.h"
#include "Canon.h"
#include "Laser.h"
#include "Gold.h"

namespace Towerdefense
{
	class Game {
	private:
		int currentWaveIndex; // Index of the current wave

		TextureManager textureManager;

		HealthBar healthBar_een;
		HealthBar redhealthBar_een_copy;

		HealthBar healthBar_twee;
		HealthBar redhealthBar_twee_copy;

		//EnemyOne snel;
		//EnemyOne traag;
		//EnemyOne snel_copy;

		EnemyOne* snel;
		EnemyOne* traag;
		Canon* canon;
		Laser* laser;

		//Canon canon;
		//Laser laser;

		//Wave wave;

		Gold<int> gold;


	public:
		Game();
		~Game();
		void run(sf::RenderWindow& window);
		void useWeapon(Weapon& weapon, sf::Vector2f shooterPosition);
	};
}
#endif
