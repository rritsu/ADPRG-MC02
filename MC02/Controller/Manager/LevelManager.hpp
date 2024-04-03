#pragma once

#include "../Utility/Utility.hpp"

namespace managers {
    using namespace utilities;

    class LevelManager {
        private:
            int nNumRooms;
            int nStartRoom;

        public:
            void startDay();    
            

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