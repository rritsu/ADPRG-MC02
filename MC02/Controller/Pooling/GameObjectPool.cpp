#include "GameObjectPool.hpp"
using namespace poolables;

GameObjectPool::GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference) {
    this->ETag = ETag;
    this->nPoolSize = nPoolSize;
    this->pPoolableReference = pPoolableReference;
    this->vecAvailableObjects = {};
    this->vecUsedObjects = {};
}

void GameObjectPool::initialize() {
    for(int i = 0; i < this->nPoolSize; i++) {
        PoolableObject* pPoolableObject = this->pPoolableReference->clone();
        GameObjectManager::getInstance()->addObject(pPoolableObject);
        pPoolableObject->setEnabled(false);
        this->vecAvailableObjects.push_back(pPoolableObject);
    }
}

PoolableObject* GameObjectPool::requestPoolable() {
    PoolableObject* pPoolableObject;
    if(this->hasAvailable(1) == true) {
        pPoolableObject = this->vecAvailableObjects[0];
        this->vecUsedObjects.push_back(pPoolableObject);
        this->vecAvailableObjects.erase(this->vecAvailableObjects.begin());
        this->setEnabled(pPoolableObject, true);

        return pPoolableObject;
    }
    return NULL;
}

void GameObjectPool::releasePoolable(PoolableObject* pPoolableObject) {
    int nIndex = -1;
    for(int i = 0; i < this->vecUsedObjects.size() && nIndex == -1; i++) {
        if(this->vecUsedObjects[i] == pPoolableObject)
            nIndex = i;
    }

    if(nIndex = -1) {
        this->vecAvailableObjects.push_back(pPoolableObject);
        this->vecUsedObjects.erase(this->vecUsedObjects.begin() + nIndex);
        this->setEnabled(pPoolableObject, false);
    }

}

std::vector<PoolableObject*> GameObjectPool::requestPoolableBatch(int nRequestSize) {
    return {};
}

bool GameObjectPool::hasAvailable(int nRequestSize) {
    if(this->vecAvailableObjects.size() >= nRequestSize)
        return true;
    return false;
}

void GameObjectPool::setEnabled(PoolableObject* pPoolableObject, bool bEnabled) {
    pPoolableObject->setEnabled(bEnabled);
    if(bEnabled)
        pPoolableObject->onActivate();
    else
        pPoolableObject->onRelease();
}

PoolTag GameObjectPool::getTag() {
    return this->ETag;
}