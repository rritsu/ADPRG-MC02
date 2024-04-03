#include "MainMenuScene.hpp"
using namespace scenes;

MainMenuScene::MainMenuScene() : Scene(SceneTag::MAIN_MENU_SCENE) {}

void MainMenuScene::onLoadResources() {
   TextureManager::getInstance()->loadMainMenu();
}

void MainMenuScene::onLoadObjects() {
  // this->createBackground();
  this->createBackground();
}

void MainMenuScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

/*
void MainMenuScene::onUnloadObjects() {
   // TextureManager::getInstance()->clearAll();
   Scene::onUnloadObjects();  //calling parent's implementation
}
*/

void MainMenuScene::createBackground() {
  // AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MAIN_MENU_BACKGROUND));
   Background* pBackground = new Background("Background", NULL);
   this->registerObject(pBackground);
}