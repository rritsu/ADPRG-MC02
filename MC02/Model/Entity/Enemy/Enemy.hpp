#pragma once

#include "../PoolableObject.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../Enum/EnemyTag.hpp"

namespace poolables{
    
    using namespace interfaces;

    class Enemy : public PoolableObject, public CollisionListener {

        protected:
            bool bPlayerFound;
            bool bFightable;
            EnemyTag EType;
            
        public:
            Enemy(std::string strName, AnimatedTexture* pTexture, EnemyTag EType);

        public:
            virtual void initialize() = 0;
            virtual void onCollisionEnter(GameObject* pGameObject);
            virtual void onCollisionExit(GameObject* pGameObject);
        


    };

}