#pragma once

#include "../../Enum/ComponentType.hpp"

#include "../Component.hpp"
#include "../../Entity/Player.hpp"
#include "../../Entity/Room.hpp"
#include "../../../Controller/Manager/GameObjectManager.hpp" 
#include "../../../Controller/Manager/SceneManager.hpp" 
#include "../../../Controller/Manager/RoomManager.hpp" 

namespace components {
    using namespace entities;
    using namespace managers;

    class RoomScript : public Component {
        public:
            RoomScript(std::string strName);

        public:
            void perform();

    
    };
}