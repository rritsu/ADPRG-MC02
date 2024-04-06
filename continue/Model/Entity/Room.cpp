#include "Room.hpp"

using namespace entities;

Room::Room(std::string strName, AnimatedTexture* pTexture, int nRoomIndex) : GameObject(strName, pTexture) {
    this->nRoomIndex = nRoomIndex;
    this->bTopDoor = false;
    this->bLeftDoor = false;
    this->bBottomDoor = false;
    this->bRightDoor = false;
    this->bHasEntryDoor = false;
}

void Room::initialize() {
  //  SceneManager::getInstance()->registerScene(new RoomScene(RoomManager::getInstance()->getRoomTag(this->nRoomIndex), this->nRoomIndex));

//    std::cout << "room index " << this->nRoomIndex << std::endl;

    RoomInput* pRoomInput = new RoomInput(this->strName + " Input");
    this->attachComponent(pRoomInput);

    RoomScript* pRoomScript = new RoomScript(this->strName + " Script");
    this->attachComponent(pRoomScript);
}

int Room::getRoomIndex() {
    return this->nRoomIndex;
}

SceneTag Room::getTag() {
    return this->ETag;
}

void Room::assignDoors(int nAdjacentIndex) {
    if(this->nRoomIndex == nAdjacentIndex + 3)
        this->bTopDoor = true;
    else
        this->bTopDoor = false;
    
    if(this->nRoomIndex == nAdjacentIndex + 1)
        this->bLeftDoor = true;
    else
        this->bLeftDoor = false;
    
    if(this->nRoomIndex == nAdjacentIndex - 3)
        this->bBottomDoor = true;
    else
        this->bBottomDoor = false;

    if(this->nRoomIndex == nAdjacentIndex - 1)
        this->bRightDoor = true;
    else
        this->bRightDoor = false;
}

bool Room::getTopDoor() {
    return this->bTopDoor;
}

bool Room::getLeftDoor() {
    return this->bLeftDoor;
}

bool Room::getBottomDoor() {
    return this->bBottomDoor;
}

bool Room::getRightDoor() {
    return this->bRightDoor;
}

bool Room::getHasEntryDoor() {
    return this->bHasEntryDoor;
}

void Room::setHasEntryDoor(bool bHasEntryDoor) {
    this->bHasEntryDoor = bHasEntryDoor;
}
