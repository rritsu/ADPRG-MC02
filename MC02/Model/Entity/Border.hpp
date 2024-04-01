#pragma once

#include "../../Config/Settings.hpp"
#include "../GameObject.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"

namespace entities {
    using namespace components;
    using namespace interfaces;

    class Border : public GameObject, public CollisionListener{
        private:
            sf::FloatRect CBounds;

        public:
            Border(std::string strName, sf::FloatRect CBounds);

        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            sf::FloatRect getGlobalBounds();

    };
}