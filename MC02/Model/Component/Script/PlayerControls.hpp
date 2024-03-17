#pragma once

#include "../../Enum/ComponentType.hpp"
#include "../../Enum/PoolTag.hpp"
#include "../Component.hpp"
#include "../Input/PlayerInput.hpp"
#include "../../Entity/Player.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp"

namespace components {
    using namespace managers;
    using namespace entities;

    class PlayerControls : public Component {
        private:
            float fSpeed;
            
        public:
            PlayerControls(std::string strName);

        public:
            void perform();
    };
}
