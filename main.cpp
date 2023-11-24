#include "Beweging.h"
#include "Enemy.h"
#include "Gold.h"

#include "Canon.h"
#include "Laser.h"
#include "MG.h"
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cmath>
#include <random>
#include <iostream>

using namespace Towerdefense;

int main() {
    sf::RenderWindow window(sf::VideoMode(1180, 720), "My Program");
    Game game;
    game.run(window);

    return 0;
}


