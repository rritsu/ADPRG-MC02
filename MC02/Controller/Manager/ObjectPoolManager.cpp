#include "ObjectPoolManager.hpp"
using namespace managers;

void ObjectPoolManager::registerObjectPool(GameObjectPool* pPool) {
    this->mapObjectPool[pPool->getTag()] = pPool;
}

ObjectPoolManager* ObjectPoolManager::P_SHARED_INSTANCE = NULL;

ObjectPoolManager::ObjectPoolManager() {}
ObjectPoolManager::ObjectPoolManager(const ObjectPoolManager&) {}

ObjectPoolManager* ObjectPoolManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ObjectPoolManager();
    return P_SHARED_INSTANCE;
}