#include "EvaluationAction.hpp"

using namespace components;

EvaluationAction::EvaluationAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void EvaluationAction::perform() {
    EvaluationInput* pInput = (EvaluationInput*)this->getOwner()->findComponentByName(this->getOwner()->getName() + " Input");

    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->getSpace()) {
            pInput->resetSpace();

            if(LevelManager::getInstance()->getHasFailed()) {
                LevelManager::getInstance()->setHasFailed(false);
                SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU_SCENE);

            }
        
            else {
                //LevelManager::getInstance()->continueToNextDay();
               // LevelManager::getInstance()->continueToNextLevel();
                SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);
            }

        }
        //if at evluation screen and get levvelmanager has failed == true, go back to title
        //else ship

        //if quota reach, proceed to next level //if bHasfailed == true

        //else if not set bhasfailed to false
    }   
}
