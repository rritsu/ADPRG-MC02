#include "ShipScene.hpp"
using namespace scenes;

ShipScene::ShipScene() : Scene(SceneTag::SHIP_SCENE) {

}

void ShipScene::onLoadResources() {
    TextureManager::getInstance()->loadShip();
}

void ShipScene::onLoadObjects() {
    this->createNullObjects();
    this->createBorders();
    this->createShip();
    this->createGrid();
    this->createShipObjects();
    this->createPlayer();
}

void ShipScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void ShipScene::createNullObjects() {
    EmptyGameObject* pHolder = new EmptyGameObject("Physics Manager Holder");
    PhysicsManager::initialize("Physics Manager", pHolder);
    GameObjectManager::getInstance()->addObject(pHolder);
   // std::cout << "created null objects - shipscene" << std::endl;
}   

void ShipScene::createBorders() {
    sf::FloatRect CRect = sf::FloatRect(0.0f, 0.0f, SCREEN_WIDTH, 0.1f);
    GameObjectManager::getInstance()->addObject(new Border(BorderType::TOP, "Top Border", CRect));

    CRect = sf::FloatRect(0.0f, 0.0f, 0.1f, SCREEN_HEIGHT);
    GameObjectManager::getInstance()->addObject(new Border(BorderType::LEFT, "Left Border", CRect));

    CRect = sf::FloatRect(0.0f, SCREEN_HEIGHT, SCREEN_WIDTH, 0.1f);
    GameObjectManager::getInstance()->addObject(new Border(BorderType::BOTTOM, "Bottom Border", CRect));

    CRect = sf::FloatRect(SCREEN_WIDTH - DISTANCE, 0.0f, 0.1f, SCREEN_HEIGHT);
    GameObjectManager::getInstance()->addObject(new Border(BorderType::RIGHT, "Right Border", CRect));
}

void ShipScene::createGrid() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHIP_TILE));
    for(int nRow = 0; nRow < GRID_WIDTH; nRow++) {
        for(int nCol = 0; nCol < GRID_HEIGHT; nCol++) {
            Tile* pShipTile = new Tile("Ship Tile" + std::to_string(nRow) + std::to_string(nCol), pTexture, sf::Vector2f(nRow * 100.0f, nCol * 100.0f));
            this->registerObject(pShipTile);
        }
    }
}


void ShipScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER)); //texture for player
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
}

void ShipScene::createShip() {
  //  AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHIP_BACKGROUND));
    Ship* pShip = new Ship("Ship");
    this->registerObject(pShip);
}

void ShipScene::createShipObjects() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LAPTOP));
    ShipObject* pLaptopShade = new ShipObject("Laptop Shade", pTexture, sf::Vector2f(200.0f - 5.0f, 100.0f));
    pLaptopShade->setShadeSetting(sf::Vector2f(1.05f, 1.05f), COLOR_BLACK);
    this->registerObject(pLaptopShade);

    ShipObject* pLaptop = new ShipObject("Laptop", pTexture, sf::Vector2f(200.0f, 100.0f));
    pLaptop->assignShade(pLaptopShade);
    this->registerObject(pLaptop);


    //portal
    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PORTAL));
    ShipObject* pPortalShade = new ShipObject("Portal Shade", pTexture, sf::Vector2f(500.0f - 5.0f, 400.0f));
    pPortalShade->setShadeSetting(sf::Vector2f(1.05f, 1.05f), COLOR_BLACK);
    this->registerObject(pPortalShade);

    ShipObject* pPortal = new ShipObject("Portal", pTexture, sf::Vector2f(500.0f, 400.0f));
    pPortal->assignShade(pPortalShade);
    this->registerObject(pPortal);
}

