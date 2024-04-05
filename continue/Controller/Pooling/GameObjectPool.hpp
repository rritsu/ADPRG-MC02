#pragma once


#include "../../Model/Enum/PoolTag.hpp"
#include "../../Model/Pooling/PoolableObject.hpp"
#include "../Manager/GameObjectManager.hpp"

namespace poolables {
    using namespace managers;

    class GameObjectPool {
        private:
            PoolTag ETag;
            int nPoolSize;
            PoolableObject* pPoolableReference;
            std::vector<PoolableObject*> vecAvailableObject;
            std::vector<PoolableObject*> vecUsedObject;

        public:
            GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference);

        public:
            void initialize();
            PoolableObject* requestPoolable();
            void releasePoolable(PoolableObject* pPoolableObject);
            std::vector<PoolableObject*> requestPoolableBatch(int nRequestSize);

        private:
            bool hasAvailable(int nRequestSize);
            void setEnabled(PoolableObject* pPoolableObject, bool bEnabled);
        
        public:
            PoolTag getTag();
            
    };
}