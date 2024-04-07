#include "RoomScene.hpp"
using namespace scenes;

RoomScene::RoomScene(SceneTag ETag, int nRoomIndex) : Scene(ETag) {
    this->nRoomIndex = nRoomIndex;
}

void RoomScene::onLoadResources() {
   TextureManager::getInstance()->loadArea();
}

void RoomScene::onLoadObjects() {
    this->createNullObjects();

    this->createGrid();
    this->createDoors();
    this->createEntryDoor();
    this->createPlayer();
    this->createBorders();
    this->createScraps();
    this->createRoom(); 
}

void RoomScene::createNullObjects() {
    EmptyGameObject* pHolder = new EmptyGameObject("Physics Manager Holder");
    PhysicsManager::initialize("Physics Manager", pHolder);
    GameObjectManager::getInstance()->addObject(pHolder);
} 

void RoomScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
    ObjectPoolManager::getInstance()->unregisterObjectPool(ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL));
    this->vecScraps.clear();
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

void RoomScene::createRoom() {
    Room* pRoom = new Room("Room", NULL, this->nRoomIndex);
//  pRoom = RoomManager::getInstance()->findRoomByIndex(this->nRoomIndex);
    this->registerObject(pRoom);
}

void RoomScene::createBorders() {
    sf::FloatRect CRect = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);

    CRect = sf::FloatRect(0.0f, 0.0f, SCREEN_WIDTH, 0.1f);
    GameObjectManager::getInstance()->addObject(new Border("Top Border", CRect));

    CRect = sf::FloatRect(0.0f, 0.0f, 0.1f, SCREEN_HEIGHT);
    GameObjectManager::getInstance()->addObject(new Border("Left Border", CRect));

    CRect = sf::FloatRect(0.0f, SCREEN_HEIGHT, SCREEN_WIDTH, 0.1f);
    GameObjectManager::getInstance()->addObject(new Border("Bottom Border", CRect));

    CRect = sf::FloatRect(SCREEN_WIDTH - DISTANCE, 0.0f, 0.1f, SCREEN_HEIGHT);
    GameObjectManager::getInstance()->addObject(new Border("Right Border", CRect));

    
}

void RoomScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
    
  //  this->registerObject( AreaManager::getInstance()->getPlayer());

}

void RoomScene::createEntryDoor() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ENTRY_DOOR));
    Room* pRoom = RoomManager::getInstance()->findRoomByIndex(this->nRoomIndex);
    DoorType EType = DoorType::NONE;

    if(pRoom->getHasEntryDoor()) {
        std::string sDoor = RoomManager::getInstance()->determineEntryDoor(this->nRoomIndex);

        if(sDoor == "Top Entry Door") {
            EType = DoorType::ENTRY_TOP;
        }
        
        else if(sDoor == "Left Entry Door") {
            EType = DoorType::ENTRY_LEFT;
        }

        else if(sDoor == "Bottom Entry Door") {
            EType = DoorType::ENTRY_BOTTOM;
        }

        else if(sDoor == "Right Entry Door") {
            EType = DoorType::ENTRY_RIGHT;
        }

        Door* pDoor = new Door(EType, "Entry Door", pTexture);
//        AreaManager::getInstance()->setDoorType(EType);
     //   std::cout << " SET ENTRY DOOR " << std::endl;
        this->registerObject(pDoor);
    }
}

void RoomScene::createDoors() {
    Room* pRoom = RoomManager::getInstance()->findRoomByIndex(this->nRoomIndex);
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::DOOR));

    std::vector<int> vecAdjacent = RoomManager::getInstance()->getAdjacentRooms(this->nRoomIndex);

    std::cout << "CURRENT ROOM: " << this->nRoomIndex << std::endl;

    this->checkAdjacentRooms(vecAdjacent);

    
    std::cout << "size: " << vecAdjacent.size() << std::endl;
    bool bSpawned[4] = {false, false, false, false};
 
    for(int i = 0; i < vecAdjacent.size(); i++) {
        pRoom->assignDoors(vecAdjacent[i]);

        if(pRoom->getTopDoor() && bSpawned[0] == false) {
            Door* pDoor = new Door(DoorType::TOP, "Top Door", pTexture);
            this->registerObject(pDoor);
            bSpawned[0] = true;
        }

        if(pRoom->getLeftDoor() && bSpawned[1] == false) {
            Door* pDoor = new Door(DoorType::LEFT, "Left Door", pTexture);
            this->registerObject(pDoor);
            bSpawned[1] = true;
        }

        if(pRoom->getBottomDoor() && bSpawned[2] == false) {
            Door* pDoor = new Door(DoorType::BOTTOM, "Bottom Door", pTexture);
            this->registerObject(pDoor);
            bSpawned[2] = true;
        }

        if(pRoom->getRightDoor() && bSpawned[3] == false) {
            Door* pDoor = new Door(DoorType::RIGHT, "Right Door", pTexture);
            this->registerObject(pDoor);
            bSpawned[3] = true;
        }
    }

}

//just tested smth w this
void RoomScene::createScraps() {
    
    ItemManager::getInstance()->initializeScrapPool();

    this->vecScraps = ItemManager::getInstance()->generateScrap(this->getRoomIndex());
    
}

void RoomScene::checkAdjacentRooms(std::vector<int>& vecAdjacent) {
    std::vector<Room*> vecRooms = RoomManager::getInstance()->getVecRooms();
    bool bFound = false;
    int size = vecAdjacent.size();
    std::vector<int> vecCopy = vecAdjacent;

    for(int i = 0; i < vecCopy.size(); i++) {
        for(int j = 0; j < vecRooms.size(); j++) {
            if(vecRooms[j]->getRoomIndex() == vecCopy[i] && bFound != true) {
                bFound = true;
            }
        }
        if(bFound != true) {
            for(int k = 0; k < vecAdjacent.size(); k++) {
                if(vecCopy[i] == vecAdjacent[k])
                    vecAdjacent.erase(vecAdjacent.begin() + k);
            }
        }
        bFound = false;
    }
}

int RoomScene::getRoomIndex() {
    return this->nRoomIndex;
}