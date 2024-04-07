#include "LaptopScene.hpp"
using namespace scenes;

LaptopScene::LaptopScene() : Scene(SceneTag::LAPTOP_SCENE) {}

void LaptopScene::onLoadResources() {
   TextureManager::getInstance()->loadLaptopMenu();
}

void LaptopScene::onLoadObjects() {
  this->createBackground();
}

void LaptopScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void LaptopScene::createBackground() {
   AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LAPTOP_BACKGROUND));
   LaptopBackground* pLaptopBackground = new LaptopBackground("Laptop Background", pTexture);
   this->registerObject(pLaptopBackground);
}