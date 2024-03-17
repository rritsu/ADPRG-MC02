#pragma once

#include "../PoolableObject.hpp"
#include "../../Entity/Ship.hpp"
#include "../../Component/Script/BulletMovement.hpp"
//#include "../"

namespace poolables {
    using namespace entities;
    using namespace components;

    class PlayerBullet : public PoolableObject {
        private:
            Ship* pShip;

        public:
            PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip);
        
        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();
    };
}