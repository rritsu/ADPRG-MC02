#pragma once

#include "unordered_map"
#include "../Pooling/GameObjectPool.hpp"
#include "../../Model/Enum/PoolTag.hpp"

namespace managers {
    using namespace poolables;
    
    class ObjectPoolManager {
        private:
            std::unordered_map<PoolTag, GameObjectPool*> mapObjectPool;

        public:
            void registerObjectPool(GameObjectPool* pPool);
            void unregisterObjectPool(GameObjectPool* pPool);

        private:
            static ObjectPoolManager* P_SHARED_INSTANCE;

        private:
            ObjectPoolManager();
            ObjectPoolManager(const ObjectPoolManager&);
            ObjectPoolManager& operator = (const ObjectPoolManager&);
        
        public:
            static ObjectPoolManager* getInstance();
    };
}