#pragma once

#include "../GameObject.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"
#include "../../Config/Theme.hpp"

namespace entities {
    using namespace models;
    using namespace components;
    using namespace interfaces;
    using namespace managers;

    class ShipObject : public GameObject, public CollisionListener{
        private:
            sf::Vector2f vecPosition;
            bool bPlayerCollision;

        public: 
            ShipObject(std::string strName, AnimatedTexture* pTexture, sf::Vector2f vecPosition);
    
        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            bool getPlayerCollision();

    
    };

}