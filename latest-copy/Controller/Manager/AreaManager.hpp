#pragma once

#include "../Utility/Utility.hpp"
#include "RoomManager.hpp"
#include "ItemManager.hpp"
#include "../../Model/Entity/Room.hpp"
#include "../../Model/Pooling/Entity/Scrap.hpp"
#include "../Pooling/GameObjectPool.hpp"

namespace managers {
    using namespace utilities;
    using namespace entities;
    using namespace poolables;

    class AreaManager {
        private:
            int nNumRooms;
            int nStartRoom;

        public:
            void generateArea();

        private:
            void createScraps(int nRoomIndex);
            

        private:
            static AreaManager* P_SHARED_INSTANCE;

        private:
            AreaManager();
            AreaManager(const AreaManager&);
            AreaManager& operator = (const AreaManager&);

        public:
            static AreaManager* getInstance();

    };
}