#include "RoomScene.hpp"
using namespace scenes;

RoomScene::RoomScene(SceneTag ETag, int nRoomIndex) : Scene(ETag) {
    this->nRoomIndex = nRoomIndex;
}

void RoomScene::onLoadResources() {
   TextureManager::getInstance()->loadArea();
}

void RoomScene::onLoadObjects() {
     std::cout << "resources loaded now objects" << std::endl;
    this->createNullObjects();
    this->createGrid();
    this->createDoors();
    this->createPlayer();
    this->createBorders();
    this->createScraps();
   // this->referScraps();

}

void RoomScene::createNullObjects() {
    EmptyGameObject* pHolder = new EmptyGameObject("Physics Manager Holder");
    PhysicsManager::initialize("Physics Manager", pHolder);
    GameObjectManager::getInstance()->addObject(pHolder);
} 

void RoomScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void RoomScene::createGrid() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::AREA_TILE));

    for(int nRow = 0; nRow < GRID_WIDTH; nRow++) {
        for(int nCol = 0; nCol < GRID_HEIGHT; nCol++) {
            Tile* pRoomTile = new Tile("Room Tile" + std::to_string(nRow) + std::to_string(nCol), pTexture, sf::Vector2f(nRow * 100.0f, nCol * 100.0f));
            this->registerObject(pRoomTile);
        }
    }
}

void RoomScene::createBorders() {
    Room* pRoom = RoomManager::getInstance()->findRoomByIndex(this->nRoomIndex);
    sf::FloatRect CRect = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);

    CRect = sf::FloatRect(0.0f, 0.0f, SCREEN_WIDTH, 0.1f);
    GameObjectManager::getInstance()->addObject(new Border(BorderType::TOP, "Top Border", CRect));

    CRect = sf::FloatRect(0.0f, 0.0f, 0.1f, SCREEN_HEIGHT);
    GameObjectManager::getInstance()->addObject(new Border(BorderType::LEFT, "Left Border", CRect));

    CRect = sf::FloatRect(0.0f, SCREEN_HEIGHT, SCREEN_WIDTH, 0.1f);
    GameObjectManager::getInstance()->addObject(new Border(BorderType::BOTTOM, "Bottom Border", CRect));

    CRect = sf::FloatRect(SCREEN_WIDTH - DISTANCE, 0.0f, 0.1f, SCREEN_HEIGHT);
    GameObjectManager::getInstance()->addObject(new Border(BorderType::RIGHT, "Right Border", CRect));

    
}

void RoomScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
}

void RoomScene::createDoors() {
    Room* pRoom = RoomManager::getInstance()->findRoomByIndex(this->nRoomIndex);
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::DOOR));
    std::vector<Room*> vecRooms = RoomManager::getInstance()->getVecRooms();
    std::vector<int> vecAdjacent = RoomManager::getInstance()->getAdjacentRooms(pRoom->getRoomIndex());


   for(int x : vecAdjacent) 
        std::cout << "adj " << x << " "; 
    

    this->checkAdjacentRooms(vecRooms, vecAdjacent);

    for(int x : vecAdjacent) 
        std::cout << "after " << x << " ";
    
    std::cout << "size: " << vecAdjacent.size() << std::endl;
    bool bSpawned[4] = {false, false, false, false};
 
    for(int i = 0; i < vecAdjacent.size(); i++) {
        pRoom->assignDoors(vecAdjacent[i]);

        if(pRoom->getTopDoor() && !bSpawned[0]) {
            sf::Vector2f vecPosition = sf::Vector2f(600.0f, 0.0f);
          //  Door* pDoor = new Door(DoorType::TOP, "Room" + std::to_string(pRoom->getRoomIndex()) + " Top Door", pTexture, vecPosition);
            Door* pDoor = new Door(DoorType::TOP, "Top Door", pTexture, vecPosition);
            this->registerObject(pDoor);
            std::cout << "top door" << std::endl;
            bSpawned[0] = true;
        }

        if(pRoom->getLeftDoor() && !bSpawned[1]) {
            sf::Vector2f vecPosition = sf::Vector2f(0.0f, 300.0f);
           // Door* pDoor = new Door(DoorType::LEFT, "Room" + std::to_string(pRoom->getRoomIndex()) + " Left Door", pTexture, vecPosition);
            Door* pDoor = new Door(DoorType::LEFT, "Left Door", pTexture, vecPosition);
            this->registerObject(pDoor);
            std::cout << "left door" << std::endl;
            bSpawned[1] = true;
        }

        if(pRoom->getBottomDoor() && !bSpawned[2]) {
            sf::Vector2f vecPosition = sf::Vector2f(600.0f, 600.0f);
           // Door* pDoor = new Door(DoorType::BOTTOM, "Room" + std::to_string(pRoom->getRoomIndex()) + " Bottom Door", pTexture, vecPosition);
            Door* pDoor = new Door(DoorType::BOTTOM, "Bottom Door", pTexture, vecPosition);
            this->registerObject(pDoor);
            std::cout << "bottom door" << std::endl;
            bSpawned[2] = true;
        }

        if(pRoom->getRightDoor() && !bSpawned[3]) {
            sf::Vector2f vecPosition = sf::Vector2f(1100.0f, 300.0f);
           // Door* pDoor = new Door(DoorType::RIGHT, "Room" + std::to_string(pRoom->getRoomIndex()) + " Right Door", pTexture, vecPosition);
            Door* pDoor = new Door(DoorType::RIGHT, "Right Door", pTexture, vecPosition);
            this->registerObject(pDoor);
            std::cout << "right door" << std::endl;
            bSpawned[3] = true;
        }

    }

}

//just tested smth w this
void RoomScene::createScraps() {

    ItemManager::getInstance()->initializeScrapPool(5);
    std::vector<Scrap*> vecScraps = ItemManager::getInstance()->generateScrap();

    for(Scrap* pScrap : vecScraps){
        this->registerObject(pScrap);
    }
    //AreaManager::getInstance()->loadScraps();

}

void RoomScene::referScraps() {
   // std::cout << "scrap" << std::endl;
  //  GameObjectPool* pScrapPool = ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL);
      //      std::cout << "scrap" << std::endl;

    // ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL)->requestPoolableBatch(3);
   // ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL)->requestPoolable();
      //          std::cout << "scrap" << std::endl;
    
    
    //paused here, need to figure out how to render the scraps and properly instantiating them
}

void RoomScene::checkAdjacentRooms(std::vector<Room*> vecRooms, std::vector<int>& vecAdjacent) {
    bool bCheck = false;
    int nIndex = -1;
    int nSize = vecAdjacent.size();

    for(int i = 0; i < nSize; i++) {
        for(int j = 0; j < vecRooms.size(); j++ ) {
            if(vecRooms[j]->getRoomIndex() == vecAdjacent[i]) {
                bCheck = true;
                break;
            }
            else 
                bCheck = false;
        }

        nIndex = i;
        if(bCheck == false) {
            vecAdjacent.erase(vecAdjacent.begin() + nIndex);
        }
    }
}

int RoomScene::getRoomIndex() {
    return this->nRoomIndex;
}