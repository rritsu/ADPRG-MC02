#include "LevelManager.hpp"

using namespace managers;

void LevelManager::continueToNextDay(){

    InventoryManager::getInstance()->sellAllScrap();
    ItemManager::getInstance()->clearMaps();
    
    if(this->nCurrentDay < 3){
        this->nCurrentDay++;
        std::cout << "IT IS NOW: " << this->nCurrentDay << std::endl; 
    }

    else if(this->nCurrentDay >= 3){
       // this->nCurrentDay = 1;
        this->checkQuota();
        std::cout << "IT IS NOW: " << this->nCurrentDay << std::endl; 
    }

}

void LevelManager::continueToNextLevel(){
    this->nCompletedLevels++;
    this->nCurrentLevel += 1;
    int nIncrease = 0;
    nIncrease = QUOTA_MULTIPLIER * (1 + ((this->nCompletedLevels * this->nCompletedLevels) / 16));
    std::cout << "QUOTA IS ADDED BY: " << nIncrease << std::endl; 
    this->nQuota += nIncrease;
    std::cout << "QUOTA IS NOW: " << nQuota << std::endl; 
}

void LevelManager::resetAllLevels(){
    this->nCompletedLevels = 0;
    this->nProfit = 0;
    this->nQuota = 130;
    this->nCurrentLevel = 1;
    InventoryManager::getInstance()->clearInventory();
    InventoryManager::getInstance()->clearStorage();
}

void LevelManager::checkQuota(){
    if(this->nQuota <= this->nProfit){
        
        if(this->nProfit != this->nQuota){
            InventoryManager::getInstance()->setPlayerCredits(InventoryManager::getInstance()->getPlayerCredits() + (this->nProfit - this->nQuota));
        }

        this->continueToNextLevel();
    }

    else{
        std::cout << "YOU HAVE FAILED TO REACH THE QUOTA" << std::endl; 
        this->bHasFailed = true;
        resetAllLevels();
    }
}

void LevelManager::calculateProfit(int nProfit){

    this->nProfit += nProfit;

}

bool LevelManager::getHasFailed(){
    
   return this->bHasFailed;

}

void LevelManager::setHasFailed(bool bHasFailed){

    this->bHasFailed = bHasFailed;

}

int LevelManager::getCurrentDay(){
    return this->nCurrentDay;
}

void LevelManager::setCurrentDay(int nCurrentDay) {
    this->nCurrentDay = nCurrentDay;
}


LevelManager* LevelManager::P_SHARED_INSTANCE = NULL;
LevelManager::LevelManager() {
    this->nQuota = 130;
    this->nProfit = 0;
    this->nCurrentDay = 1;
    std::cout << "IT IS NOW: " << this->nCurrentDay << std::endl; 
    this->nCurrentLevel = 1;
    this->nCompletedLevels = 0;
    this->bHasFailed = false;
}

LevelManager::LevelManager(const LevelManager&) {}

LevelManager* LevelManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new LevelManager();
    }
    return P_SHARED_INSTANCE;
}
