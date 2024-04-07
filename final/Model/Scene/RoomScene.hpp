#pragma once

#include "iostream"
#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../../Controller/Manager/RoomManager.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/AreaManager.hpp"
//#include "../../Controller/Manager/ItemManager.hpp"
#include "../../Controller/Utility/Utility.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Tile.hpp"
#include "../Entity/Player.hpp"
#include "../Entity/Door.hpp"
#include "../Entity/Room.hpp"
#include "../Entity/Border.hpp"
#include "../EmptyGameObject.hpp"
#include "../Pooling/Entity/Scrap.hpp"
#include "../../Config/Settings.hpp"

namespace scenes {
    using namespace managers;
    using namespace utilities;
    using namespace entities;
    using namespace models;
    using namespace poolables;

    class RoomScene : public Scene {
        private:
            int nRoomIndex;
            int nConnectedIndex;
            int nBackIndex;
            std::vector<Scrap*> vecScraps;

        public:
            RoomScene(SceneTag ETag, int nRoomIndex);

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createNullObjects();
            void createRoom();
            void createGrid();
            void createBorders();
            void createPlayer();
            void createEntryDoor();
            void createDoors();
            void createScraps();
            void checkAdjacentRooms(std::vector<int>& vecAdjacent);

        public:
            int getRoomIndex();

    };
}
