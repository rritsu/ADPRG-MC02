#include "AreaScene.hpp"
using namespace scenes;

AreaScene::AreaScene(std::vector<int> vecArea, int nAreaIndex, int nBackIndex) : Scene(SceneTag::AREA_SCENE) {
    this->nAreaIndex = nAreaIndex;
    //randomize
    
    //randomize index
    int nRandIndex = Utility::getInstance()->getRandomNumber(nAreaIndex, vecArea.size());
    this->nConnectedIndex = nRandIndex;
}

void AreaScene::onLoadResources() {
   TextureManager::getInstance()->loadArea();
}

void AreaScene::onLoadObjects() {
  // this->createBackground();
    this->createGrid();
    this->createPlayer();
}

void AreaScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void AreaScene::createGrid() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::AREA_TILE));

    for(int nRow = 0; nRow < GRID_WIDTH; nRow++) {
        for(int nCol = 0; nCol < GRID_HEIGHT; nCol++) {
            Tile* pAreaTile = new Tile("Area Tile" + std::to_string(nRow) + std::to_string(nCol), pTexture, sf::Vector2f(nRow * 100.0f, nCol * 100.0f));
            this->registerObject(pAreaTile);
        }
    }
}


void AreaScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
}

int AreaScene::getAreaIndex() {
    return this->nAreaIndex;
}