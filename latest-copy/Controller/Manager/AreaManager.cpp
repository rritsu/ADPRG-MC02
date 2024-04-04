#include "AreaManager.hpp"
using namespace managers;

void AreaManager::generateArea() { 
    //generate how many scraps
    //generate how many rooms
    //connection of rooms
    //doors smth smth
    //enemies
    std::vector<Room*> vecRooms = RoomManager::getInstance()->getVecRooms();

    RoomManager::getInstance()->generateRoomIndeces();
    std::cout << "create" << std::endl;
        //this->createScraps(0);
        std::cout << "created" << std::endl;
  //  for(int i = 0; i < vecRooms.size(); i++) {
      //  int nRoomIndex = vecRooms[i]->getRoomIndex();
      //  Room* pRoom = RoomManager::getInstance()->findRoomByIndex(nRoomIndex);

       //ItemManager::getInstance()->generateScrap(0);
  //  }

    RoomManager::getInstance()->generateRooms();

    std::cout << "tapos" << std::endl;
}

void AreaManager::createScraps(int nRoomIndex) {
    TextureManager::getInstance()->loadScraps();
    Scrap* pScrap = new Scrap("Scrap", NULL);
    GameObjectPool* pScrapPool = new GameObjectPool(PoolTag::SCRAP_POOL, 27, pScrap);
    pScrapPool->initialize();
    ObjectPoolManager::getInstance()->registerObjectPool(pScrapPool);
    //ItemManager::getInstance()->generateScrap();
}

AreaManager* AreaManager::P_SHARED_INSTANCE = NULL;
AreaManager::AreaManager() {
    this->nNumRooms = 0;
    this->nStartRoom = 5;
}

AreaManager::AreaManager(const AreaManager&) {}

AreaManager* AreaManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new AreaManager();
    }
    return P_SHARED_INSTANCE;
}
