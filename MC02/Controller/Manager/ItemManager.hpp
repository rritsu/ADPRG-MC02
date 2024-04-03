
#pragma once

#include "unordered_map"

#include "GameObjectManager.hpp"
#include "ObjectPoolManager.hpp"
#include "Utility/Utility.hpp"
#include "../../Pooling/Entity/Scrap.hpp"


namespace managers {
    using namespace models;
    using namespace utilities;
    using namespace poolables;

    class ItemManager {
        private:
            std::vector<sf::Vector2f> vecUsedPositions; //try to move please to RoomManager or maybe for each area so it considers doors, enemies, etc

        public:


        public:
            void initializeScrapPool(int nLevelIndex);
            void clearScrapPool();
            void generateScrap(int nAreaIndex);
            PoolableObject* getItemAtLocation(int nTileRowIndex, int nTileColumnIndex);
            std::vector<PoolableObject*> getItemsAtLocation(int nAreaIndex);
            void setItemAtLocation(int nAreaIndex, int nTileRowIndex, int nTileColumnIndex);

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