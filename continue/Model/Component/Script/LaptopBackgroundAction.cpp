#include "LaptopBackgroundAction.hpp"

using namespace components;

LaptopBackgroundAction::LaptopBackgroundAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void LaptopBackgroundAction::perform() {
    LaptopBackgroundInput* pInput = (LaptopBackgroundInput*)this->getOwner()->findComponentByName(this->getOwner()->getName() + " Input");

    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }

    else {
        if(pInput->getMenuScene() && !SceneManager::getInstance()->getLoaded(SceneTag::SHIP_SCENE)) {
            SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);
        }

        if(pInput->isNextDay()){
            LevelManager::getInstance()->continueToNextDay();
            SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);
        }
    }   
}
