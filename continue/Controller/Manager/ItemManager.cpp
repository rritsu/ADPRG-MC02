#include "ItemManager.hpp"

using namespace managers;

//initialize the scrap pool, make sure to call this every start of a new DAY
void ItemManager::initializeScrapPool(int nLevelIndex){ //(the level index is there to determine the number of items that will spawn in a map PER DAY, this is to ensure the higher you go, the more likely there is loot in an area to meet the quota)

    std::cout << "Pool initialized " << std::endl;
    TextureManager::getInstance()->loadScraps();
    int nRandom = Utility::getInstance()->getRandomNumber(1, 3);

    AnimatedTexture* pTexture;
     switch(nRandom){
        case 0:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::METAL_SHEET));
            break;

        case 1:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::AIRHORN)); 
            break;

        case 2:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::STOP_SIGN));
            break;

        case 3:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LARGE_AXLE));  
            break;

        case 4:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TOY_CUBE));
            break;
    };

    Scrap* pScrap = new Scrap("Scrap", new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TOY_CUBE)));
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
    std::vector<Scrap*> vecScrap = {};

    if(pScrapPool != NULL) {

        std::cout << "Pool recieved " << std::endl;

    }

    int nScraptoSpawn = Utility::getInstance()->getRandomNumber(1, 3);
    std::cout << "Number of Spawn randomized " << std::endl;
    bool bIdentical = false;

    if(nScraptoSpawn != 0){

        while(nScraptoSpawn > 0){

            std::cout << "Scrap spawned" << std::endl;
            bIdentical = false;
            int nRandomX = Utility::getInstance()->getRandomNumber(2, GRID_WIDTH - 2);
            int nRandomY = Utility::getInstance()->getRandomNumber(2, GRID_HEIGHT - 2);
            sf::Vector2f vecNewPosition = sf::Vector2f(nRandomX, nRandomY);
            for(sf::Vector2f vecPosition : this->vecUsedPositions){
                    if(vecNewPosition == vecPosition){
                            bIdentical = true;
                    }
            }

            if(bIdentical == false)
            {
                Scrap* pScrap = (Scrap*)pScrapPool->requestPoolable();

                if(pScrap != NULL) {
                
                pScrap->getSprite()->setPosition(nRandomX * 100, nRandomY * 100);
                 std::cout << "Scrap generated at " << nRandomX << std::endl;

                    if(bIdentical == false){
                        this->vecUsedPositions.push_back(pScrap->getSprite()->getPosition());
                        vecScrap.push_back(pScrap);
                        nScraptoSpawn--;
                    }
                }
            }
            
        }

        return vecScrap;
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