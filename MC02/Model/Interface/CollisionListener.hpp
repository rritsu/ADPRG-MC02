#pragma once

#include "../GameObject.hpp"

namespace interfaces {
    using namespace models;

    class CollisionListener {
        public:
            virtual void onCollisionEnter(GameObject *pGameObject) = 0;
            virtual void onCollisionExit(GameObject *pGameObject) = 0;
    };
}