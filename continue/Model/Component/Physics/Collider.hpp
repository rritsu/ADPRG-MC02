#pragma once

#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Interface/CollisionListener.hpp"

namespace components {
    using namespace interfaces;

    class Collider : public Component {
        private:
            CollisionListener* pListener;
            sf::FloatRect COffset;
            std::vector<Collider*> vecCollided;
            bool bCleanUp;

        public:
            Collider(std::string strName);
        
        public:
            void perform();
            bool isColliding(Collider* pCollider);
            bool hasCollided(Collider* pCollider);
            void setCollided(Collider* pCollider, bool bCollided);
            int findCollider(Collider* pCollider);
            void cleanCollisions();

            void onCollisionEnter(Collider* pCollider);
            void onCollisionExit(Collider* pCollider);
            void assignListener(CollisionListener* pListener);

        public:
            void setOffset(sf::FloatRect COffset);
            bool getCleanUp();
            void setCleanUp(bool bCleanUp);       
            sf::FloatRect getGlobalBounds();
    };
}