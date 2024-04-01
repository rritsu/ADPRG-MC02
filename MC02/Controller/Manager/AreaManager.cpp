#include "AreaManager.hpp"

using namespace managers;




AreaManager* AreaManager::P_SHARED_INSTANCE = NULL;
AreaManager::AreaManager() {}
AreaManager::AreaManager(const AreaManager&) {}

AreaManager* AreaManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new AreaManager();

    return P_SHARED_INSTANCE;
}