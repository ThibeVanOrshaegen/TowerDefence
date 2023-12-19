#ifndef UPDATEROTATION_H
#define UPDATEROTATION_H

#include <SFML/Graphics.hpp>
#include "Canon.h"
#include "Canonshooting.h"
#include "Lasershooting.h"
#include "Laser.h"
#include "TextureManager.h"

namespace Towerdefense {

    class Updaterotation {
        TextureManager textureManager;

    public:

        // Method to update the rotation of a cannon shooter based on an enemy's position
        void updateShooterRotationCanon(Canon* canonplaats, Enemy* snel, int Graden);
        
        // Method to update the rotation of a laser shooter based on an enemy's position
        void updateShooterRotationLaser(Laser* laserplaats, Enemy* traag, int Graden);
        
        // Method to update the rotation of a cannon bullet based on an enemy's position
        void updateShooterRotationCanonkogel(Canonshooting* canonplaats, Enemy* snel, int Graden);
        
        // Method to update the rotation of a laser bullet based on an enemy's position
        void updateShooterRotationLaserkogel(Lasershooting* laserplaats, Enemy* traag, int Graden);

        // Getter method to check if ammo is turned on
        bool getAmmo() const { return TurnAmmoOn; }

    private:

        static bool TurnAmmoOn;
    };
}
#endif
