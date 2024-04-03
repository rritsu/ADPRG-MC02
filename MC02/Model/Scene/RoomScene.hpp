#pragma once

#include "iostream"
#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../../Controller/Manager/RoomManager.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Utility/Utility.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Tile.hpp"
#include "../Entity/Player.hpp"
#include "../Entity/Door.hpp"
#include "../Entity/Room.hpp"
#include "../Entity/Border.hpp"
#include "../EmptyGameObject.hpp"
#include "../../Config/Settings.hpp"

namespace scenes {
    using namespace managers;
    using namespace utilities;
    using namespace entities;
    using namespace models;

    class RoomScene : public Scene {
        private:
            int nRoomIndex;
            int nConnectedIndex;
            int nBackIndex;

        public:
            RoomScene(SceneTag ETag, int nRoomIndex);

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createNullObjects();
            void createGrid();
            void createBorders();
            void createPlayer();
            void createDoors();
<<<<<<< Updated upstream
=======
            void referScraps();
>>>>>>> Stashed changes
            void checkAdjacentRooms(std::vector<Room*> vecRooms, std::vector<int>& vecAdjacent);

        public:
            int getRoomIndex();

    };
}