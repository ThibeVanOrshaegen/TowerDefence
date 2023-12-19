#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1180, 720), "My Program");
    Towerdefense::Game game;
    game.run(window);

    return 0;
}
