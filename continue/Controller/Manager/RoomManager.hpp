#pragma once

#include "../Utility/Utility.hpp"
#include "SceneManager.hpp"
#include "../../Model/Scene/RoomScene.hpp"
#include "../../Model/Enum/SceneTag.hpp"
#include "../../Model/Entity/Room.hpp"

namespace managers {
    using namespace utilities;
    using namespace scenes;
    using namespace entities;

    class RoomManager {
        private:
            int nNumRooms;
            int nEntryRoom;
            int nCurrentRoom;
            std::vector<int> vecIndeces;
            std::vector<Room*> vecRooms;
            std::unordered_map<int, Room*> mapRooms;

        public:
           // void initializeConnectedRooms();
            std::vector<int> getAdjacentRooms(int nRoomIndex);
            void generateRooms();
            void generateRoomIndeces();
            void addRoom(Room* pRoom);
            Room* findRoomByIndex(int nRoomIndex);
            void deleteAllRooms();
            std::string determineEntryDoor(int nRoomIndex);

        private:
            void initializeIndeces();
            std::vector<int> initializeRemove();
            void removeIndeces(std::vector<int> vecRemove);
            void instantiateRooms();
            void clearIndeces();
            int getRandomNumber(int nLowerbound, int nUpperbound);
         //   bool checkDuplicate(int nIndex);
            bool checkDuplicate (int nNum, std::vector<int> vecIndeces);
          //  std::vector<int> getAdjacentRooms(int nRoom); 

        public:
            std::vector<Room*> getVecRooms();
            SceneTag getRoomTag(int nIndex);
            int getEntryRoom();
           // SceneTag getEntryRoomTag();
            int getCurrentRoom();
            void setCurrentRoom(int nCurrentRoom);


        private:
            static RoomManager* P_SHARED_INSTANCE;

        private:
            RoomManager();
            RoomManager(const RoomManager&);
            RoomManager& operator = (const RoomManager&);

        public:
            static RoomManager* getInstance();
    };

}
