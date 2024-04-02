#include "Room.hpp"

using namespace entities;

Room::Room(std::string strName, AnimatedTexture* pTexture, int nRoomIndex) : GameObject(strName, pTexture) {
    this->nRoomIndex = nRoomIndex;
}

void Room::initialize() {
    SceneManager::getInstance()->registerScene(new RoomScene(RoomManager::getInstance()->getRoomTag(this->nRoomIndex)));

}

int Room::getRoomIndex() {
    return this->nRoomIndex;
}