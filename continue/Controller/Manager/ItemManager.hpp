
#pragma once

#include "unordered_map"

#include "GameObjectManager.hpp"
#include "ObjectPoolManager.hpp"
#include "../Utility/Utility.hpp"
#include "../../../Model/Pooling/Entity/Scrap.hpp"


namespace managers {
    using namespace models;
    using namespace utilities;
    using namespace poolables;

    class ItemManager {
        private:
            std::unordered_map<int, std::vector<sf::Vector2f>> vecUsedLocations;
            std::unordered_map<int, std::vector<ScrapTag>> vecItemTypes;
            std::vector<int> vecSpawnedIndices; 

        public:
            void initializeScrapPool();
            void clearMaps();
            std::vector<Scrap*> generateScrap(int nRoomIndex);
            PoolableObject* getItemAtLocation(int nTileRowIndex, int nTileColumnIndex);
            std::vector<PoolableObject*> getItemsAtLocation(int nAreaIndex);
            void setItemAtLocation(int nAreaIndex, int nTileRowIndex, int nTileColumnIndex);
            void removeSpecifiedScrap(Scrap* pScrap);

        private:
            static ItemManager* P_SHARED_INSTANCE;
        
        private:
            ItemManager();
            ItemManager(const  ItemManager&);
             ItemManager& operator = (const  ItemManager&);
        
        public:
            static  ItemManager* getInstance();
        
    };
}