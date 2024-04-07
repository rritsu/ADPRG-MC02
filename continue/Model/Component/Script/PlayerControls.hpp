#pragma once

#include "../../Enum/ComponentType.hpp"
#include "../../Enum/PoolTag.hpp"

#include "../Component.hpp"
#include "../Input/PlayerInput.hpp"
#include "../../Entity/Player.hpp"
#include "../../Pooling/Entity/Scrap.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../../Controller/Manager/InventoryManager.hpp"
#include "../../../Config/Settings.hpp"


namespace components {
    using namespace managers;
   // using namespace entities;
    using namespace poolables;

    class PlayerControls : public Component {
        private:
            float fX;
            float fY;
            
        public:
            PlayerControls(std::string strName);

        public:
            void perform();
    };
}
