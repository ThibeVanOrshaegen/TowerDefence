#ifndef UPDATEROTATION_H
#define UPDATEROTATION_H

#include <SFML/Graphics.hpp>
#include "Canon.h"
#include "TextureManager.h"

namespace Towerdefense {

    class Updaterotation {
        TextureManager textureManager;

    public:
        void updateShooterRotation(Canon* canonplaats, EnemyOne* snel, int Graden);
    };

} // namespace Towerdefense

#endif // UPDATEROTATION_H
