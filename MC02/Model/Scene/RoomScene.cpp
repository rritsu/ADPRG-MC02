#include "RoomScene.hpp"
using namespace scenes;

RoomScene::RoomScene(SceneTag ETag) : Scene(ETag) {
    this->nAreaIndex = nAreaIndex;
    //randomize
    
    //randomize index
    //int nRandIndex = Utility::getInstance()->getRandomNumber(nAreaIndex, vecArea.size());
    //this->nConnectedIndex = nRandInde 
}

void RoomScene::onLoadResources() {
   TextureManager::getInstance()->loadArea();
}

void RoomScene::onLoadObjects() {
  // this->createBackground();
    this->createGrid();
    this->createPlayer();
    this->createDoors();
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


void RoomScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
}

void RoomScene::createDoors() {
    std::vector<Room*> vecRooms = RoomManager::getInstance()->getVecRooms();
    std::vector<int> vecAdjacent = {};

    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::DOOR));

    for(Room* pRoom : vecRooms)
        std::cout << pRoom->getRoomIndex() << " ";

    for(int i = 0; i < vecRooms.size(); i++) {
        //vecAdjacent = RoomManager::getInstance()->getAdjacentRooms(vecRooms[i]);
    }
    //look for adjace

    /*
    get the vec area
    iterate
    */
}

int RoomScene::getAreaIndex() {
    return this->nAreaIndex;
}