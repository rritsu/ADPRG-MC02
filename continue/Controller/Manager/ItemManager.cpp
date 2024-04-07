#include "ItemManager.hpp"

using namespace managers;

//initialize the scrap pool, make sure to call this every start of a new DAY
void ItemManager::initializeScrapPool(){ //(the level index is there to determine the number of items that will spawn in a map PER DAY, this is to ensure the higher you go, the more likely there is loot in an area to meet the quota)

    std::cout << "Pool initialized " << std::endl;
    TextureManager::getInstance()->loadScraps();
    Scrap* pScrap = new Scrap("Scrap", new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TOY_CUBE)), ScrapTag::NONE);
    GameObjectPool* pScrapPool = new GameObjectPool(PoolTag::SCRAP_POOL, 27, pScrap);
    pScrapPool->initialize();
    ObjectPoolManager::getInstance()->registerObjectPool(pScrapPool);

}

void ItemManager::clearMaps(){

    this->vecSpawnedIndices.clear();
    this->vecItemTypes.clear();
    this->vecUsedLocations.clear();
    
}

//uses the pool of SCRAP to dump in the area for the DAY, this is NOT done each time a room is entered, this is done on area INITIALIZATION
std::vector<Scrap*> ItemManager::generateScrap(int nRoomIndex){

    GameObjectPool* pScrapPool = ObjectPoolManager::getInstance()->getPool(PoolTag::SCRAP_POOL);
    std::vector<Scrap*> vecScrap = {};
    bool bAlreadySpawned = false;

    if(pScrapPool != NULL) {

        std::cout << "Pool recieved " << std::endl;

    }

    for(int nIndice : vecSpawnedIndices){
            if(nIndice == nRoomIndex){
            bAlreadySpawned = true;
        }
    }

    if(this->vecUsedLocations[nRoomIndex].empty() && bAlreadySpawned == false){

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
                for(sf::Vector2f vecPosition : this->vecUsedLocations[nRoomIndex]){
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
                        std::cout << "Scrap generated is " << pScrap->getTag() << std::endl;
                        this->vecUsedLocations[nRoomIndex].push_back(pScrap->getSprite()->getPosition());
                        this->vecItemTypes[nRoomIndex].push_back(pScrap->getTag());
                        vecScrap.push_back(pScrap);
                        nScraptoSpawn--;
                        
                    }
                }
                
            }

            this->vecSpawnedIndices.push_back(nRoomIndex);
            return vecScrap;
        }

        else{
            this->vecSpawnedIndices.push_back(nRoomIndex);
            return {};
        }
    }

    else if(this->vecUsedLocations[nRoomIndex].empty() && bAlreadySpawned == true){
        return {};
    }

    if(!this->vecUsedLocations[nRoomIndex].empty()){

        int maxScrapToSpawn = this->vecUsedLocations[nRoomIndex].size();
        int i = 0;

        while(maxScrapToSpawn > 0){

            Scrap* pScrap = (Scrap*)pScrapPool->requestPoolable();
            pScrap->getSprite()->setPosition(this->vecUsedLocations[nRoomIndex].at(i));
            pScrap->setTag(this->vecItemTypes[nRoomIndex].at(i));
            std::cout << "Scrap generated at " << this->vecUsedLocations[nRoomIndex].at(i).x << std::endl;
            std::cout << "Scrap generated is " << this->vecItemTypes[nRoomIndex].at(i) << std::endl;
            i++;
            maxScrapToSpawn--;
            vecScrap.push_back(pScrap);
        }

        if(!vecScrap.empty()){
            return vecScrap;
        }

        else{
            return {};
        }

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

ItemManager::ItemManager() {
    this->vecUsedLocations = {};
    this->vecItemTypes = {};
    this->vecSpawnedIndices = {};
}

ItemManager::ItemManager(const ItemManager&) {}

ItemManager* ItemManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ItemManager();

    return P_SHARED_INSTANCE;
}