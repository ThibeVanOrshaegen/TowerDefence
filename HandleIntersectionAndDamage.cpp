#include "HandleIntersectionAndDamage.h"
#include "Data.h"
namespace Towerdefense
{
    const std::string filename = "DataTower.txt";
    void HandleIntersectionAndDamage::handleIntersectionsAndDamage(sf::Sprite& weaponSprite, sf::Sprite& robotSprite, HealthBar& healthBar) {
        if (weaponSprite.getGlobalBounds().intersects(robotSprite.getGlobalBounds())) {
            healthBar.applyDamage();
            healthBar.subtractHealth(4);


            std::vector<std::string> linesToWrite = { "Enemy has been hit" };
            Data::writeToFile(filename, linesToWrite);
            std::vector<std::string> linesRead = Data::readFromFile(filename);

            for (const auto& line : linesRead) {
                std::cout << line << '\n';
            }
        }
    }
}
