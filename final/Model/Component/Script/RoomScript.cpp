#include "RoomScript.hpp"

using namespace components;

RoomScript::RoomScript(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void RoomScript::perform() {
    RoomInput* pRoomInput = (RoomInput*)this->getOwner()->findComponentByName(this->getOwner()->getName() + " Input");

    Door* pTopDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Top Door");
    Door* pLeftDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Left Door");
    Door* pBottomDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Bottom Door");
    Door* pRightDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Right Door");
    Door* pEntryDoor = (Door*)GameObjectManager::getInstance()->findObjectByName("Entry Door");

    int nCurrentRoom = RoomManager::getInstance()->getCurrentRoom();

    if(pRoomInput != NULL) {

       if(pRoomInput->getDoorInteract()) {
            pRoomInput->resetDoorInteract();

            if(pTopDoor != NULL && pTopDoor->getPlayerCollision()) {
                int nNextRoom = nCurrentRoom - 3;
                SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
                RoomManager::getInstance()->setCurrentRoom(nNextRoom);
                std::cout << "next room: " << nNextRoom << std::endl << std::endl;
                SceneManager::getInstance()->loadScene(ETag);
                AreaManager::getInstance()->setDoorType(pTopDoor->getType());
            }

            else if(pLeftDoor != NULL && pLeftDoor->getPlayerCollision()) {
                int nNextRoom = nCurrentRoom - 1;
                SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
                RoomManager::getInstance()->setCurrentRoom(nNextRoom);
                std::cout << "next room: " << nNextRoom << std::endl << std::endl;
                SceneManager::getInstance()->loadScene(ETag);
                AreaManager::getInstance()->setDoorType(pLeftDoor->getType());
            }

            else if(pBottomDoor != NULL && pBottomDoor->getPlayerCollision()) {
                int nNextRoom = nCurrentRoom + 3;
                SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
                RoomManager::getInstance()->setCurrentRoom(nNextRoom);
                std::cout << "next room: " << nNextRoom << std::endl << std::endl;
                SceneManager::getInstance()->loadScene(ETag);
                AreaManager::getInstance()->setDoorType(pBottomDoor->getType());
            }

            else if(pRightDoor != NULL && pRightDoor->getPlayerCollision()) {
                int nNextRoom = nCurrentRoom + 1;
                SceneTag ETag = RoomManager::getInstance()->getRoomTag(nNextRoom);
                RoomManager::getInstance()->setCurrentRoom(nNextRoom);
                std::cout << "next room: " << nNextRoom << std::endl << std::endl;
                SceneManager::getInstance()->loadScene(ETag);
                AreaManager::getInstance()->setDoorType(pRightDoor->getType());
            }

            else if(pEntryDoor != NULL && pEntryDoor->getPlayerCollision()) {
                RoomManager::getInstance()->deleteAllRooms();
                SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);
                AreaManager::getInstance()->setDoorType(pEntryDoor->getType());
            }
        }
    }
}