#include "Canon.h"

Canon::Canon(sf::Vector2f initialPosition) : arrow(), arrowPosition(initialPosition), initialPosition(initialPosition) {
    arrow.setFillColor(sf::Color::Black);
    arrow.setRadius(15.f); //Scale gedaan in plaats van Radius dan gaat het niks weer
    arrow.setPosition(initialPosition);
}

void Canon::fire(sf::Vector2f shooterPosition) {
    float arrowSpeed = 5;
    arrowPosition.y += arrowSpeed;
    arrowPosition.x -= arrowSpeed;

    arrow.setPosition(arrowPosition);
    if (arrowPosition.y < 0 || arrowPosition.x < 0)
    {
        arrowPosition.y = 240;
        arrowPosition.x = 240;


    }
}

void Canon::update() {
    float arrowSpeed = 10;
    arrow.move(0, -arrowSpeed);
}
