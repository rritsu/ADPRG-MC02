#pragma once

#include "../GameObject.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Component/Input/RoomInput.hpp"
#include "../Component/Script/RoomScript.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/SceneManager.hpp"


namespace entities {
    using namespace models;
    using namespace managers;
    using namespace components;

    class Room : public GameObject {
        private:
            int nRoomIndex;
            SceneTag ETag;
            bool bTopDoor;
            bool bLeftDoor;
            bool bBottomDoor;
            bool bRightDoor;
            bool bHasEntryDoor;
        
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
            bool getHasEntryDoor();
            void setHasEntryDoor(bool bHasEntryDoor);
    };

}