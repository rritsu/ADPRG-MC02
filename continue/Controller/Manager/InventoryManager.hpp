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

    class InventoryManager {
        private:
            std::vector<Scrap*> vecPlayerScraps;
            //std::vector<Item*> boughtItems;
            int nPlayerInventorySize;

        public:


        public:
            void initializeScrapPool(int nLevelIndex);
            void clearScrapPool();
            std::vector<Scrap*> generateScrap();
            PoolableObject* getItemAtLocation(int nTileRowIndex, int nTileColumnIndex);
            std::vector<PoolableObject*> getItemsAtLocation(int nAreaIndex);
            void setItemAtLocation(int nAreaIndex, int nTileRowIndex, int nTileColumnIndex);

        private:
            static InventoryManager* P_SHARED_INSTANCE;
        
        private:
             InventoryManager();
             InventoryManager(const InventoryManager&);
             InventoryManager& operator = (const InventoryManager&);
        
        public:
            static InventoryManager* getInstance();
        
    };
}