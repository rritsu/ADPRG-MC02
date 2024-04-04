#pragma once

#include "../../Config/Settings.hpp"
#include "../GameObject.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"
#include "../Enum/BorderType.hpp"

namespace entities {
    using namespace components;
    using namespace interfaces;
    using namespace managers;

    class Border : public GameObject, public CollisionListener{
        private:
            sf::FloatRect CBounds;
            BorderType EType;

        public:
            Border(BorderType EType, std::string strName, sf::FloatRect CBounds);

        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            sf::FloatRect getGlobalBounds();
            BorderType getType();

    };
}