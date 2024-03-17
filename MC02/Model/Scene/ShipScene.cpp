#include "ShipScene.hpp"

using namespace scenes;

ShipScene::ShipScene() : Scene(SceneTag::SHIP_SCENE) {}

void ShipScene::onLoadResources() {
    TextureManager::getInstance()->loadShip();
}

void ShipScene::onLoadObjects() {
    this->createPlayer();
}   

void ShipScene::onUnloadResources() {

}

void ShipScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
     std::cout << "create Player" << std::endl;
}