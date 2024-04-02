#pragma once

#include "../GameObject.hpp"
#include "../Enum/SceneTag.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/SceneManager.hpp"
#include "../Scene/RoomScene.hpp"

namespace entities {
    using namespace models;
    using namespace managers;
    using namespace scenes;

    class Room : public GameObject {
        private:
            int nRoomIndex;
            SceneTag ETag;
        
        public:
            Room(std::string strName, AnimatedTexture* pTexture, int nRoomIndex);
        
        public:
            void initialize();

        public:
            int getRoomIndex();
    };

}