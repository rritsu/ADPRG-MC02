#include "RoomScript.hpp"

using namespace components;

RoomScript::RoomScript(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void RoomScript::perform() {
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    PlayerInput* pPlayerInput = (PlayerInput*)pPlayer->findComponentByName(pPlayer->getName() + " Input");
    RoomInput* pRoomInput = (RoomInput*)this->getOwner()->findComponentByName(this->getOwner()->getName() + " Input");
    Door* pTopDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Top Door");
    Door* pLeftDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Left Door");
    Door* pBottomDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Bottom Door");
    Door* pRightDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Right Door");

    int nCurrentRoom = RoomManager::getInstance()->getCurrentRoom();
   // std::cout << "CURRENT ROOM: " << nCurrentRoom << std::endl;
   // std::cout << this->getOwner()->getName() << std::endl;

    if(pRoomInput != NULL) {

       if(pRoomInput->getDoorInteract()) {
            if(pTopDoor != NULL && pTopDoor->getPlayerCollision()) {
                std::cout << "top room" << std::endl;
                int nNextRoom = nCurrentRoom - 3;
                SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
                RoomManager::getInstance()->setCurrentRoom(nNextRoom);
                std::cout << "next room: " << nNextRoom << std::endl << std::endl;
                SceneManager::getInstance()->loadScene(ETag);
                pRoomInput->resetDoorInteract();
            }

            else if(pLeftDoor != NULL && pLeftDoor->getPlayerCollision()) {
                std::cout << "left room" << std::endl;
                int nNextRoom = nCurrentRoom - 1;
                SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
                RoomManager::getInstance()->setCurrentRoom(nNextRoom);
                std::cout << "next room: " << nNextRoom << std::endl << std::endl;
                SceneManager::getInstance()->loadScene(ETag);
                pRoomInput->resetDoorInteract();
            }

            else if(pBottomDoor != NULL && pBottomDoor->getPlayerCollision()) {
                std::cout << "bottom room" << std::endl;
                int nNextRoom = nCurrentRoom + 3;
                SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
                RoomManager::getInstance()->setCurrentRoom(nNextRoom);
                std::cout << "next room: " << nNextRoom << std::endl << std::endl;
                SceneManager::getInstance()->loadScene(ETag);
                pRoomInput->resetDoorInteract();
            }

            else if(pRightDoor != NULL && pRightDoor->getPlayerCollision()) {
                std::cout << "right room" << std::endl;
                int nNextRoom = nCurrentRoom + 1;
                SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
                RoomManager::getInstance()->setCurrentRoom(nNextRoom);
                std::cout << "next room: " << nNextRoom << std::endl << std::endl;
                SceneManager::getInstance()->loadScene(ETag);
                pRoomInput->resetDoorInteract();
            }
        }
    }
    else {
        std::cout << "input doko" << std::endl;
    }
}
//doors colliders
//scene change