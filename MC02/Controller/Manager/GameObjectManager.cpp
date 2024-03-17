#include "GameObjectManager.hpp"
using namespace managers;

void GameObjectManager::processEvents(sf::Event CEvent){
    for(GameObject* pGameObject : this->vecGameObjects) {
        if(pGameObject->getEnabled())
            pGameObject->processEvents(CEvent);
    }
}

void GameObjectManager::update(sf::Time tDeltaTime) {
    for(GameObject* pGameObject : this->vecGameObjects) {
        if(pGameObject->getEnabled())
            pGameObject->update(tDeltaTime);
    }
}

void GameObjectManager::draw(sf::RenderWindow* pWindow) {
    for(GameObject* pGameObject : this->vecGameObjects) {
        if(pGameObject->getEnabled())
            pGameObject->draw(pWindow);
    }
}

void GameObjectManager::addObject(GameObject* pGameObject) {
    this->mapGameObjects[pGameObject->getName()] = pGameObject;
    this->vecGameObjects.push_back(pGameObject);
    pGameObject->initialize();
    std::cout << "addObject method in GameObjectManager" << std::endl;
}

GameObject* GameObjectManager::findGameObjectByName(std::string strName) {
    return 0;
}

void GameObjectManager::deleteObject(GameObject* pGameObject) {}

void GameObjectManager::deleteObjectByName(std::string strName) {}

void GameObjectManager::deleteAllObjects() {
    std::vector<GameObject*> vecGameObjects = this->vecGameObjects;
    for(int i = 0; i < vecGameObjects.size(); i++) {
        delete this->vecGameObjects[i];
    }

    this->vecGameObjects.clear();
    this->mapGameObjects.clear();
}


GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;

GameObjectManager::GameObjectManager() {}

GameObjectManager::GameObjectManager(const GameObjectManager&) {}

GameObjectManager* GameObjectManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new GameObjectManager();
    return P_SHARED_INSTANCE;
}