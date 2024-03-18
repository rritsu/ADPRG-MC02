#include "ShipScene.hpp"
using namespace scenes;

ShipScene::ShipScene() : Scene(SceneTag::SHIP_SCENE) {

}

void ShipScene::onLoadResources() {
    TextureManager::getInstance()->loadShip();
}

void ShipScene::onLoadObjects() {
    this->createBackGround();
    this->createPlayer();
  //  this->createObjectPools();
}

void ShipScene::onUnloadResources() {

}

void ShipScene::createBackGround() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::GAME_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    pBackground->getSprite()->setPosition(100,0);
    this->registerObject(pBackground);
}


void ShipScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER)); //texture for player
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
}


void ShipScene::createObjectPools() { 
 //   AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET));
 ///   Ship* pShip = (Ship*)GameObjectManager::getInstance()->findObjectByName("Ship");
  //  GameObjectPool* pBulletPool = new GameObjectPool(PoolTag::PLAYER_BULLET, 3, new PlayerBullet("Bullet", pTexture, pShip));  //make
 //   pBulletPool->initialize();      //initialize
  //  ObjectPoolManager::getInstance()->registerObjectPool(pBulletPool);      //register
}


