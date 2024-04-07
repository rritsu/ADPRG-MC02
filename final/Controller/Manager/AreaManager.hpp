#pragma once

#include "../Utility/Utility.hpp"
#include "RoomManager.hpp"
#include "SceneManager.hpp"
#include "TextureManager.hpp"
#include "GameObjectManager.hpp"
#include "../../Model/Entity/Player.hpp"
#include "../../Model/Enum/DoorType.hpp"

namespace managers {
    using namespace utilities;
    using namespace entities;
    using namespace poolables;

    class AreaManager {
        private:
            Player* pPlayerHolder;
            DoorType EDoorType;
            bool bLoaded;

        public:
            void generateArea();

        public:
            DoorType getDoorType();
            void setDoorType(DoorType EType);
            

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