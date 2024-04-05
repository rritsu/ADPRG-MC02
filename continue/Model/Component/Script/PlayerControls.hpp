#pragma once

#include "../../Enum/ComponentType.hpp"
#include "../../Enum/PoolTag.hpp"

#include "../Component.hpp"
#include "../Input/PlayerInput.hpp"
#include "../../Entity/Player.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../../Config/Settings.hpp"

namespace components {
    using namespace managers;
    using namespace entities;

    class PlayerControls : public Component {
        private:
            float fX;
            float fY;
            
        public:
            PlayerControls(std::string strName);

        public:
            void perform();

        private:
            void boundPlayer();
            bool isAtBoundaries();
    };
}
