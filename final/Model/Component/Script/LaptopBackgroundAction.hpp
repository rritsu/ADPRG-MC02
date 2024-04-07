#pragma once

#include "../../../Controller/Manager/SceneManager.hpp"
#include "../../../Controller/Manager/LevelManager.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Enum/SceneTag.hpp"
#include "../Component.hpp"
#include "../Input/LaptopBackgroundInput.hpp"

namespace components {
    using namespace managers;

    class LaptopBackgroundAction : public Component {
        public:
            LaptopBackgroundAction(std::string strName);

        public:
            void perform();
    };
}
