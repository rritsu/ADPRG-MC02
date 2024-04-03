#pragma once

#include "../GameObject.hpp"
#include "../Enum/SceneTag.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/SceneManager.hpp"
//#include "../Scene/RoomScene.hpp"

namespace entities {
    using namespace models;
    using namespace managers;
  //  using namespace scenes;

    class Room : public GameObject {
        private:
            int nRoomIndex;
            SceneTag ETag;
            bool bTopDoor;
            bool bLeftDoor;
            bool bBottomDoor;
            bool bRightDoor;
        
        public:
            Room(std::string strName, AnimatedTexture* pTexture, int nRoomIndex);
        
        public:
            void initialize();
            void assignDoors(int nAdjacentIndex);

        public:
            int getRoomIndex();
            SceneTag getTag();
            bool getTopDoor();
            bool getLeftDoor();
            bool getBottomDoor();
            bool getRightDoor();
    };

}