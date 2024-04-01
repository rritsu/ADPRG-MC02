#include "LevelManager.hpp"
using namespace managers;

LevelManager* LevelManager::P_SHARED_INSTANCE = NULL;
LevelManager::LevelManager() {}
LevelManager::LevelManager(const LevelManager&) {}

LevelManager* LevelManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new LevelManager();
    }
    return P_SHARED_INSTANCE;
}
