#include "AreaManager.hpp"
using namespace managers;

void AreaManager::generateArea() { 
    //generate how many scraps
    //generate how many rooms
    //connection of rooms
    //doors smth smth
    //enemies

    std::cout << "generate rooms" << std::endl;
    RoomManager::getInstance()->generateRooms();
    int nEntryRoom = RoomManager::getInstance()->getEntryRoom();
    SceneManager::getInstance()->loadScene(RoomManager::getInstance()->getRoomTag(nEntryRoom));

}

DoorType AreaManager::getDoorType() {
    return this->EDoorType;
}

void AreaManager::setDoorType(DoorType EDoorType) {
    this->EDoorType = EDoorType;
}

AreaManager* AreaManager::P_SHARED_INSTANCE = NULL;
AreaManager::AreaManager() {
    this->pPlayerHolder = NULL;
    this->EDoorType = DoorType::NONE;
}

AreaManager::AreaManager(const AreaManager&) {}

AreaManager* AreaManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new AreaManager();
    }
    return P_SHARED_INSTANCE;
}
