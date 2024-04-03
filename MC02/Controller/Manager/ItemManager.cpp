#include "ItemManager.hpp"

using namespace managers;

//initialize the scrap pool, make sure to call this every start of a new DAY
void ItemManager::initializeScrapPool(int nLevelIndex){ //(the level index is there to determine the number of items that will spawn in a map PER DAY, this is to ensure the higher you go, the more likely there is loot in an area to meet the quota)

    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::METAL_SHEET));
    PoolableObject* scrap = new Scrap("Scrap", pTexture);
    GameObjectPool* scrapPool = new GameObjectPool(PoolTag::SCRAP_POOL, 5 + nLevelIndex, scrap);
    ObjectPoolManager::getInstance()->registerObjectPool(scrapPool);

}

void ItemManager::clearScrapPool(){
    ObjectPoolManager::getInstance()->unregisterObjectPool(ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL));
}

//uses the pool of SCRAP to dump in the area for the DAY, this is NOT done each time a room is entered, this is done on area INITIALIZATION
void ItemManager::generateScrap(int nAreaIndex){
    GameObjectPool* scrapPool = ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL);
    Scrap* pScrap = (Scrap*)scrapPool->requestPoolable();
    
    if(pScrap != NULL) {

        int nScraptoSpawn = Utility::getInstance()->getRandomNumber(0, 3);
        bool bIdentical = true;

        if(nScraptoSpawn != 0){

            while(nScraptoSpawn > 0){

                int nRandomX = Utility::getInstance()->getRandomNumber(0, GRID_WIDTH);
                int nRandomY = Utility::getInstance()->getRandomNumber(0, GRID_HEIGHT);
                pScrap->getSprite()->setPosition(nRandomX, nRandomY);

                for(sf::Vector2f vecPosition : this->vecUsedPositions){
                    if(pScrap->getSprite()->getPosition() != vecPosition){
                        bIdentical = false;
                    }
                }

                if(bIdentical == false){
                    this->vecUsedPositions.push_back(pScrap->getSprite()->getPosition());
                    nScraptoSpawn--;
                }
            }
        }
    }
       
}

//gets an item in a specific area
PoolableObject* ItemManager::getItemAtLocation(int nTileRowIndex, int nTileColumnIndex){
    

}

//gets ALL items in a location to be loaded in
std::vector<PoolableObject*> ItemManager::getItemsAtLocation(int nAreaIndex){

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