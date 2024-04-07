#pragma once

#include "unordered_map"

#include "GameObjectManager.hpp"
#include "ObjectPoolManager.hpp"
#include "LevelManager.hpp"
#include "ItemManager.hpp"
#include "../Utility/Utility.hpp"
#include "../../../Model/Pooling/Entity/Scrap.hpp"


namespace managers {
    using namespace models;
    using namespace utilities;
    using namespace poolables;

    class InventoryManager {
        private:
            std::vector<Scrap*> vecPlayerScraps;
            std::vector<Scrap*> vecStorage;
            int nPlayerCredits;

        public:
            void registerScrapToInventory(Scrap* pScrap);
            void clearInventory();
            void registerScrapToStorage();
            void clearStorage();
            void sellAllScrap();
            int getPlayerCredits();
            void setPlayerCredits(int nAmount);
            
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