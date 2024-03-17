#pragma once

#include "../GameObject.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"

namespace entities {
    using namespace components;
    using namespace interfaces;

    class Border : public GameObject, public CollisionListener{
        public:
            Border(std::string strName);

        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

    };
}