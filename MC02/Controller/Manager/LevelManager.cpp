#include "LevelManager.hpp"
using namespace managers;

void LevelManager::startDay() { 
    //generate how many scraps
    //generate how many rooms
    //connection of rooms
    //doors smth smth
    //enemies
    this->nNumRooms = Utility::getInstance()->getRandomNumber(4, 9);
    while(this->nStartRoom == 5) {
        this->nStartRoom = Utility::getInstance()->getRandomNumber(1, 9);
    }
    
    for(int i = 1; i <= nNumRooms; i++) {

    }

}

LevelManager* LevelManager::P_SHARED_INSTANCE = NULL;
LevelManager::LevelManager() {
    this->nNumRooms = 0;
    this->nStartRoom = 5;
}

LevelManager::LevelManager(const LevelManager&) {}

LevelManager* LevelManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new LevelManager();
    }
    return P_SHARED_INSTANCE;
}
