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
            if(LevelManager::getInstance()->getCurrentDay() >= 3) {
                LevelManager::getInstance()->continueToNextDay();
                LevelManager::getInstance()->setCurrentDay(1);
                SceneManager::getInstance()->loadScene(SceneTag::EVALUATION_SCENE);
            }
            else {
                LevelManager::getInstance()->continueToNextDay();
                SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);
            }

            /*
            LevelManager::getInstance()->continueToNextDay();


        //go back to ship if ncurrent day is less than 1
            if(LevelManager::getInstance()->getCurrentDay() <= 3)
                SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);

            else
                SceneManager::getInstance()->loadScene(SceneTag::EVALUATION_SCENE);
                */

            //SceneManager::getInstance()->loadScene(SceneTag::EVALUATION_SCENE);


             //if quota reach, proceed to next level //if bHasfailed == true
           // if(LevelManager::getInstance()->hasFailed()) {
            //    SceneManager::getInstance()->loadScene(SceneTag::EVALUATION_SCENE);
          //  }
           // else {
                ///SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);
           // }
        }
    }   
}
