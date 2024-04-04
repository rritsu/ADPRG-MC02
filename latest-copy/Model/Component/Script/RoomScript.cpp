#include "RoomScript.hpp"

using namespace components;

RoomScript::RoomScript(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void RoomScript::perform() {
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    PlayerInput* pPlayerInput = (PlayerInput*)pPlayer->findComponentByName(pPlayer->getName() + " Input");

    Door* pTopDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Top Door");
    Door* pLeftDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Left Door");
    Door* pBottomDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Bottom Door");
    Door* pRightDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Right Door");

    int nCurrentRoom = RoomManager::getInstance()->getCurrentRoom();

    if(pPlayerInput != NULL) {
        if(pTopDoor->getPlayerCollision()) {
            int nNextRoom = nCurrentRoom - 3;
            SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
            SceneManager::getInstance()->loadScene(ETag);
        }

       // else if(pLeftD)
    }
}
//doors colliders
//scene change