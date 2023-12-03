#include <SFML/Graphics.hpp>

#include "Game.h"


using namespace Towerdefense;

int main() {
    sf::RenderWindow window(sf::VideoMode(1180, 720), "My Program");
    Game game;
    game.run(window);

    return 0;
}
