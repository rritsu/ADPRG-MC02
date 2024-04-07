#include "LevelManager.hpp"

using namespace managers;

void LevelManager::continueToNextDay(){

    ItemManager::getInstance()->clearMaps();
    
    if(this->nCurrentDay < 3){
        this->nProfit += 1000000;
        this->nCurrentDay++;
        std::cout << "IT IS NOW: " << this->nCurrentDay << std::endl; 
    }

    else if(this->nCurrentDay >= 3){
        this->nCurrentDay = 1;
        std::cout << "IT IS NOW: " << this->nCurrentDay << std::endl; 
    }
}

void LevelManager::continueToNextLevel(){
    this->nCompletedLevels++;
    this->nCurrentLevel += 1;
    int nIncrease = QUOTA_MULTIPLIER * (1 + (this->nCompletedLevels * this->nCompletedLevels) / 16);
    std::cout << "QUOTA IS ADDED BY: " << nIncrease << std::endl; 
    this->nQuota += nIncrease;
    std::cout << "QUOTA IS NOW: " << nQuota << std::endl; 
}

void LevelManager::resetAllLevels(){
    this->nCompletedLevels = 0;
    this->nProfit = 0;
    this->nQuota = 130;
    this->nCurrentLevel = 1;
}

bool LevelManager::checkQuota(){
    if(this->nQuota <= this->nProfit){
        
        if(this->nProfit != this->nQuota){
            //InventoryManager::getInstance()->setPlayerCredits(this->nProfit - this->nQuota);
        }

        this->continueToNextLevel();
    }

    else
        resetAllLevels();
}

void LevelManager::calculateProfit(){

}


LevelManager* LevelManager::P_SHARED_INSTANCE = NULL;
LevelManager::LevelManager() {
    this->nQuota = 130;
    this->nProfit = 0;
    this->nCurrentDay = 1;
    std::cout << "IT IS NOW: " << this->nCurrentDay << std::endl; 
    this->nCurrentLevel = 1;
}

LevelManager::LevelManager(const LevelManager&) {}

LevelManager* LevelManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new LevelManager();
    }
    return P_SHARED_INSTANCE;
}
