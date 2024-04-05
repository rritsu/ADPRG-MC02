#include "ItemManager.hpp"

using namespace managers;

//initialize the scrap pool, make sure to call this every start of a new DAY
void ItemManager::initializeScrapPool(int nLevelIndex){ //(the level index is there to determine the number of items that will spawn in a map PER DAY, this is to ensure the higher you go, the more likely there is loot in an area to meet the quota)

    std::cout << "Pool initialized " << std::endl;
    TextureManager::getInstance()->loadScraps();
    Scrap* pScrap = new Scrap("Scrap", NULL);
    GameObjectPool* pScrapPool = new GameObjectPool(PoolTag::SCRAP_POOL, 10, pScrap);
    pScrapPool->initialize();
    ObjectPoolManager::getInstance()->registerObjectPool(pScrapPool);

}

void ItemManager::clearScrapPool(){
    ObjectPoolManager::getInstance()->unregisterObjectPool(ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL));
}

//uses the pool of SCRAP to dump in the area for the DAY, this is NOT done each time a room is entered, this is done on area INITIALIZATION
std::vector<Scrap*> ItemManager::generateScrap(){

    GameObjectPool* pScrapPool = ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL);
    std::vector<Scrap*> scrap = {};

    if(pScrapPool != NULL) {

        std::cout << "Pool recieved " << std::endl;

    }

    int nScraptoSpawn = Utility::getInstance()->getRandomNumber(1, 3);
    std::cout << "Number of Spawn randomized " << std::endl;
    bool bIdentical = false;

    if(nScraptoSpawn != 0){

        while(nScraptoSpawn > 0){

            Scrap* pScrap = (Scrap*)pScrapPool->requestPoolable();
            std::cout << "Scrap spawned" << std::endl;
            bIdentical = false;
            if(pScrap != NULL) {

                int nRandomX = Utility::getInstance()->getRandomNumber(2, GRID_WIDTH - 2);
                int nRandomY = Utility::getInstance()->getRandomNumber(2, GRID_HEIGHT - 2);
                pScrap->getSprite()->setPosition(nRandomX * 100, nRandomY * 100);
                 std::cout << "Scrap generated at " << nRandomX << std::endl;
                for(sf::Vector2f vecPosition : this->vecUsedPositions){
                    if(pScrap->getSprite()->getPosition() == vecPosition){
                            bIdentical = true;
                    }
                }

                if(bIdentical == false){
                    this->vecUsedPositions.push_back(pScrap->getSprite()->getPosition());
                    scrap.push_back(pScrap);
                    nScraptoSpawn--;
                }
            }
            
        }

        return scrap;
    }

    else {
         return {};
    }
}
       

//gets an item in a specific area
PoolableObject* ItemManager::getItemAtLocation(int nTileRowIndex, int nTileColumnIndex){
    return NULL;    

}

//gets ALL items in a location to be loaded in
std::vector<PoolableObject*> ItemManager::getItemsAtLocation(int nAreaIndex){
    return {};
}

//room index to denote which room, tile index to denote what tile it will be placed on
void ItemManager::setItemAtLocation(int nAreaIndex, int nTileRowIndex, int nTileColumnIndex) {

}


ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;
ItemManager::ItemManager() {}
ItemManager::ItemManager(const ItemManager&) {}

ItemManager* ItemManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ItemManager();

    return P_SHARED_INSTANCE;
}