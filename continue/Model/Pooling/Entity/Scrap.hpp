#pragma once

#include "../Enum/ScrapTag.hpp"
#include "../../../Controller/Manager/TextureManager.hpp" 
#include "../../../Controller/Utility/Utility.hpp" 
#include "../PoolableObject.hpp"
#include "../../Component/Physics/Collider.hpp"
#include "../../Interface/CollisionListener.hpp"
#include "../../Interface/IPickupable.hpp"
#include "../../../Controller/Manager/PhysicsManager.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp"

namespace poolables {
    using namespace models;
    using namespace managers;
    using namespace utilities;
    using namespace components;
    using namespace interfaces;

    class Scrap : public PoolableObject, public IPickupable,  CollisionListener {
        protected:
            ScrapTag ETag;
            int nValue;
            bool bInRange;
            bool bPickedup;
            sf::Vector2f* vecPosition;
            int nRoomIndex;

        public:
            Scrap(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
            void onActivate();  //initial setup
            void onRelease();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);
            void onPickup(GameObject* pGameObject);
            void onDrop(GameObject* pGameObject);
            PoolableObject* clone();

        public:
            int getValue();
            bool IsInRange();
            ScrapTag getTag();
            void setRoomIndex(int nRoomIndex);
            
    };
}