#pragma once

#include "unordered_map"

#include "GameObjectManager.hpp"
#include "ObjectPoolManager.hpp"
#include "ItemManager.hpp"
#include "../Utility/Utility.hpp"


namespace managers {
    using namespace models;
    using namespace utilities;
    using namespace poolables;

    class LevelManager {
        private:
            int nQuota;
            int nProfit;
            int nCurrentLevel;
            int nCurrentDay;
            int nCompletedLevels;
            bool bHasFailed;

        public:
            void continueToNextDay();
            void continueToNextLevel();
            void resetAllLevels();
            void checkQuota();
            void calculateProfit(int nIncrement);

        public:
            bool getHasFailed();
            void setHasFailed(bool bHasFailed);
            int getCurrentDay();
            void setCurrentDay(int nCurrentDay);

        private:
            static LevelManager* P_SHARED_INSTANCE;
        
        private:
            LevelManager();
            LevelManager(const LevelManager&);
            LevelManager& operator = (const LevelManager&);
        
        public:
            static LevelManager* getInstance();
        
    };
}