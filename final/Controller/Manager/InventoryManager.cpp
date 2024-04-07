#include "InventoryManager.hpp"

using namespace managers;

void InventoryManager::registerScrapToInventory(Scrap* pScrap){

    if(this->vecPlayerScraps.size() < MAXIMUM_INVENTORY_SPACE){
        this->vecPlayerScraps.push_back(pScrap);
        ItemManager::getInstance()->removeSpecifiedScrap(pScrap);
    }

    std::cout << "Current size of vecPlayerScraps is" <<  this->vecPlayerScraps.size() << std::endl;
}


void InventoryManager::clearInventory(){

    this->vecPlayerScraps.clear();
}

void InventoryManager::registerScrapToStorage(){

    if(!this->vecPlayerScraps.empty()){

        for(Scrap* pScrap : this->vecPlayerScraps){
        this->vecStorage.push_back(pScrap);
        }

        this->clearInventory();
    }

}

void InventoryManager::clearStorage(){
    this->vecStorage.clear();
}

void InventoryManager::sellAllScrap(){

    std::cout << "Beginning to sell all scraps" << std::endl;

    int nTotal = 0;

    for(Scrap* pScrap : this->vecStorage){
        switch(pScrap->getTag()){
            case ScrapTag::AIRHORN:
                nTotal += 62;
                std::cout << "SCRAP SOLD! Amount is currently: " << nTotal << std::endl;
                break;

            case ScrapTag::LARGE_AXLE:
                nTotal += 48;
                std::cout << "SCRAP SOLD! Amount is currently: " << nTotal << std::endl;
                break;

            case ScrapTag::METAL_SHEET:
                nTotal += 16;
                std::cout << "SCRAP SOLD! Amount is currently: " << nTotal << std::endl;
                break;

            case ScrapTag::STOP_SIGN:
                nTotal += 36;
                std::cout << "SCRAP SOLD! Amount is currently: " << nTotal << std::endl;
                break;

            case ScrapTag::TOY_CUBE:
                nTotal += 34;
                std::cout << "SCRAP SOLD! Amount is currently: " << nTotal << std::endl;
                break;
        }
    }

    LevelManager::getInstance()->calculateProfit(nTotal);
    this->clearStorage();
}

int InventoryManager::getPlayerCredits(){
    return this->nPlayerCredits;
}

void InventoryManager:: setPlayerCredits(int nPlayerCredits){
    this->nPlayerCredits = nPlayerCredits;
}

InventoryManager* InventoryManager::P_SHARED_INSTANCE = NULL;
InventoryManager::InventoryManager() {
    this->vecPlayerScraps = {};
    this->vecStorage = {};
    this->nPlayerCredits = 0;
}

InventoryManager::InventoryManager(const InventoryManager&) {}

InventoryManager* InventoryManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new InventoryManager();
    }
    return P_SHARED_INSTANCE;
}
