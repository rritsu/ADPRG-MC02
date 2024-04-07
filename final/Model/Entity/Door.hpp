#pragma once

#include "../GameObject.hpp"
#include "../Enum/DoorType.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"

namespace entities {
    using namespace models;
    using namespace interfaces;
    using namespace components;
    using namespace managers;

    class Door : public GameObject, public CollisionListener {
        private:
            sf::Vector2f vecPosition;
            DoorType EType;
            bool bPlayerCollision;
            bool bEntryDoor;
           // std::unordered_map<DoorType, sf::Vector2f> mapDoors; 

        public:
            Door(DoorType EType, std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
            void initializePosition();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);
            
        public:
            sf::Vector2f getPostition();
            bool getPlayerCollision();
            DoorType getType();
            bool getEntryDoor();

    };
}