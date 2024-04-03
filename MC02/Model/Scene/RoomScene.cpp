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
    this->createPlayer();
    this->createBorders();

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
            Tile* pAreaTile = new Tile("Area Tile" + std::to_string(nRow) + std::to_string(nCol), pTexture, sf::Vector2f(nRow * 100.0f, nCol * 100.0f));
            this->registerObject(pAreaTile);
        }
    }
}

void RoomScene::createBorders() {
    sf::FloatRect CRect = sf::FloatRect(0.0f, 0.0f, SCREEN_WIDTH, 0.1f);
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
    
 
    for(int i = 0; i < vecAdjacent.size(); i++) {
        pRoom->assignDoors(vecAdjacent[i]);

        if(pRoom->getTopDoor()) {
            sf::Vector2f vecPosition = sf::Vector2f(600.0f, 0.0f);
            Door* pDoor = new Door(DoorType::TOP, "Room" + std::to_string(pRoom->getRoomIndex()) + "Top Door", pTexture, vecPosition);
            this->registerObject(pDoor);
            std::cout << "top door" << std::endl;
        }

        if(pRoom->getLeftDoor()) {
            sf::Vector2f vecPosition = sf::Vector2f(0.0f, 300.0f);
            Door* pDoor = new Door(DoorType::LEFT, "Room" + std::to_string(pRoom->getRoomIndex()) + "Left Door", pTexture, vecPosition);
            this->registerObject(pDoor);
            std::cout << "left door" << std::endl;
        }

        if(pRoom->getBottomDoor()) {
            sf::Vector2f vecPosition = sf::Vector2f(600.0f, 600.0f);
            Door* pDoor = new Door(DoorType::BOTTOM, "Room" + std::to_string(pRoom->getRoomIndex()) + "Bottom Door", pTexture, vecPosition);
            this->registerObject(pDoor);
            std::cout << "bottom door" << std::endl;
        }

        if(pRoom->getRightDoor()) {
            sf::Vector2f vecPosition = sf::Vector2f(1100.0f, 300.0f);
            Door* pDoor = new Door(DoorType::RIGHT, "Room" + std::to_string(pRoom->getRoomIndex()) + "Right Door", pTexture, vecPosition);
            this->registerObject(pDoor);
            std::cout << "right door" << std::endl;
        }

    }

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