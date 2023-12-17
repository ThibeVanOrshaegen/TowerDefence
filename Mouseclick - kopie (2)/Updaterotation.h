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
        void updateShooterRotationCanon(Canon* canonplaats, Enemy* snel, int Graden);
        void updateShooterRotationLaser(Laser* laserplaats, Enemy* traag, int Graden);
        void updateShooterRotationCanonkogel(Canonshooting* canonplaats, Enemy* snel, int Graden);

        bool getAmmo() const { return TurnAmmoOn; }

    private:

        static bool TurnAmmoOn;
    };

} // namespace Towerdefense

#endif // UPDATEROTATION_H