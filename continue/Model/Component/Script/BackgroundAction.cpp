#include "BackgroundAction.hpp"

using namespace components;

BackgroundAction::BackgroundAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void BackgroundAction::perform() {
    BackgroundInput* pInput = (BackgroundInput*)this->getOwner()->findComponentByName(this->getOwner()->getName() + " Input");

    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->getMainMenuScene() && !SceneManager::getInstance()->getLoaded(SceneTag::SHIP_SCENE)) {
            SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);
        }
    }   
}
