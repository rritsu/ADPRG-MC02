#pragma once

#include "../GameObject.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Input/PlayerInput.hpp"
#include "../Component/Script/PlayerControls.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"

namespace entities {
    using namespace models;
    using namespace components;
    using namespace interfaces;

    class Player : public GameObject, public CollisionListener {
        private:
            sf::Color CNormalColor;

        public:
            Player(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);
    };
}