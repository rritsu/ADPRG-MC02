#include "Room.hpp"

using namespace entities;

Room::Room(std::string strName, AnimatedTexture* pTexture, int nRoomIndex) : GameObject(strName, pTexture) {
    this->nRoomIndex = nRoomIndex;
    this->bTopDoor = false;
    this->bLeftDoor = false;
    this->bBottomDoor = false;
    this->bRightDoor = false;
}

void Room::initialize() {
    SceneManager::getInstance()->registerScene(new RoomScene(RoomManager::getInstance()->getRoomTag(this->nRoomIndex), this->nRoomIndex));
  //  std::cout << "room index " << this->nRoomIndex << std::endl;
}

int Room::getRoomIndex() {
    return this->nRoomIndex;
}

SceneTag Room::getTag() {
    return this->ETag;
}

void Room::assignDoors(int nAdjacentIndex) {

    //std::cout << "ASSIGN DOOR " << this->nRoomIndex << std::endl;
//for(int x : vecAdjacent)
    //   std::cout << "adj" << x << " ";


 //   for(int i = 0; i < vecAdjacent.size(); i++) {
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
  //  }
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
