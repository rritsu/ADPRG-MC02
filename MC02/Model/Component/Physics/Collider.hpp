#pragma once

#include "../Component.hpp"
#include "../../GameObject.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Interface/CollisionListener.hpp"

namespace components {
    using namespace models;
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
            void onColllisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);
            void assignListener(CollisionListener* pListener);
            sf::FloatRect getGlobalBounds();

            
    };
}