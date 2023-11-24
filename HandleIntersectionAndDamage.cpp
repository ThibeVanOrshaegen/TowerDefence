#include "HandleIntersectionAndDamage.h"
#include "Data.h"
namespace Towerdefense
{
    const std::string filename = "DataTower.txt";
    void HandleIntersectionAndDamage::handleIntersectionsAndDamage(sf::Sprite& weaponSprite, sf::Sprite& robotSprite, HealthBar& healthBar) {
        if (weaponSprite.getGlobalBounds().intersects(robotSprite.getGlobalBounds())) {
            healthBar.applyDamage();


            std::vector<std::string> linesToWrite = { "Enemy has been hit" };
            Data::writeToFile(filename, linesToWrite);
            std::vector<std::string> linesRead = Data::readFromFile(filename);

            // Displaying the content read from the file
            //std::cout << "Content read from " << filename << ":\n";
            for (const auto& line : linesRead) {
                std::cout << line << '\n';
            }
        }
    }
}
